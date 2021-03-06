#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/block.h"

const int SourceNumber = 123456;

Block InitBlock()                    // allocates memory for a new block
{
    Block Temp = (Block)malloc(sizeof(struct block));
    Temp->PreviousBlockHash = 0;
    Temp->BlockNumber = 1;
    Temp->Next = NULL;
    Temp->Prev = NULL;
    Temp->Nonce = (rand()%500)+1 ;
    Temp->numTransaction = 0;
    for(int i=0;i<50;i++)
        Temp->TransactionArray[i] = InitTransaction();     //allocating memory for struct transaction in transaction array
        
    return Temp;
}

BlockChain InitBlockChain()                  // allocating memory for a blockchain and its contents (info like number of blocks, pointers to head block and current block)
{
    BlockChain temp = (BlockChain)malloc(sizeof(struct blockChain));
    temp->Head = InitBlock();
    temp->CurrBlock = temp->Head;
    temp->NumBlocks = 1;
    return temp;
}

void AddBlock(BlockChain B)        //Function to add a new block to the blockchain after the previous block is filled
{          
    Block newBlock = InitBlock();
    if(B==NULL)    //When blockchain is empty
    {                      
        B = InitBlockChain();
        return;
    }
    Block cur = B->CurrBlock;
    newBlock->BlockNumber = cur->BlockNumber+1;
    newBlock->PreviousBlockHash = getpreviousBlockHash(cur);   

    //maintaining a doubly linked list
    cur->Next = newBlock;
    newBlock->Prev = cur;

    
    B->CurrBlock = newBlock;        //updating the current Block pointer
    B->NumBlocks++;
    return;
}

void AddBlockTransaction(int S_UID, int R_UID, double amount, BlockChain B)  //maintains transactions for a block
{
    if(B->CurrBlock->numTransaction == 50 )   
    {
        AddBlock(B);       //when previous block is full
    }

    int transaction_number = B->CurrBlock->numTransaction;

    B->CurrBlock->TransactionArray[transaction_number]->S_UID = S_UID;
    B->CurrBlock->TransactionArray[transaction_number]->R_UID = R_UID;
    B->CurrBlock->TransactionArray[transaction_number]->Amount = amount;

    B->CurrBlock->numTransaction++;       
    return;
}

int Attack(BlockChain B)    //Head is pointer to 1st block
{
    srand(time(0));
    Block head = B->Head;           // head ptr
    int randnum = (rand()%50) + 1;  //random number
    
    if(randnum >= B->NumBlocks)     // if user asks to attack a block which does not exist, or is not complete (last block)
        return 0;
    
    int blocknum = (randnum);
    randnum--;
    Block tmp = head;          // tmp= head block


    // in the below code , we reach attacked block and we change the nonce 
    // for example , attack block 4 = change its nonce to a random number
    while(tmp->Next != NULL)
    {
        if(randnum == 0)
        {
            int r = rand()%500 + 1;
            if(r == tmp->Nonce)
            {
                tmp->Nonce = (r+1)%500;         
            }
            else 
                tmp->Nonce = r;
            return blocknum;
        }
        else
        {
            randnum--;
            tmp = tmp->Next;
        }
    }

    if(randnum < 0)         //Technically, it should never reach this, but safety check
        return 0;           
    return -1;              //It should never return -1, but having this as a check
}

//This is used by the getPreviousBlockHash function
int power(int base, int POW_ER)
{
    int ret_value = 1;
    while(POW_ER--)
    {
        ret_value *= base ;         
    }
    return ret_value ;
}

//This is used by the getPreviousBlockHash function
int replace(int digit,int digit_posn, int Original_num) 
{
    int temp_num =  power(10, digit_posn)  ;         
    int Modified_num = Original_num   ;                 //123456  (if the number is)
    Modified_num  /= temp_num ;                         //1234
    Modified_num -= Modified_num%10;                    //1230
    Modified_num += digit;                              //1236
    Modified_num *= temp_num;                           //123600
    Modified_num += Original_num%temp_num;              //123656
   
   return Modified_num  ;
}


//To calculate previousBlockHash of a block

int getpreviousBlockHash(Block block_node) // block_node = ptr to the previous block (which is full)
 {
    int BlockNumber = block_node->BlockNumber;
    Transaction* transactions = block_node->TransactionArray ;
    int previousBlockHash = block_node->PreviousBlockHash;
    int nonce = block_node->Nonce ;
    
    if(previousBlockHash==0)                // for Block 1 or head block
        previousBlockHash = SourceNumber;   // We do this since our hash function assumes previousBlockHash is a 6 digit number

    // hash function includes three parts 

    // part 1 : modifying the 6 digit previousBlock using blocknumber
    
    int base_num = previousBlockHash; 
    int BlockNumberFnResult;
    int BlockNumbertemp = BlockNumber;

    int prod = 1;
    while(BlockNumbertemp>0) 
    {
        prod *= BlockNumbertemp%10;
        BlockNumbertemp /= 10;
    }
    // prod = product of digits of BlockNumber

    prod = prod%6;      //prod gives us the position of the digit of the base_num that is to be changed from the right side
    int newDigit = (BlockNumber*BlockNumber)%10;  // newDigit is the number which will replace the above mentioned number
     
    BlockNumberFnResult = replace(newDigit,prod,base_num);  //replacing the digit with nreDigit

    //Now BlockNumberFnResult is the number we got using BlockNumber and PreviousBlockHash


    //part 2 : modifying the 6 digit previousBlockHash using transaction history details

    int tmp1,tmp2,tmp_sum=0;
    for(int i=0;i<50;i++)      // loop using info of all the 50 transactions and generating a number by an algorithm
    {
        tmp1 =  (transactions[i]->S_UID + transactions[i]->R_UID)%10000000 ; 
        tmp2 = ((int) transactions[i]->Amount)/50;
        tmp1 = (tmp1*tmp2)%10000000;
        tmp_sum = (tmp_sum+tmp1)%10000000;
    }
    
    int tmp_sum2 = tmp_sum%6 ;       //tmp_sum gives us the position of the digit of the base_num that is to be changed from the right side
    int tmp_sum1 = (tmp_sum*tmp_sum)%10000000;  
    tmp_sum1 = tmp_sum1 %10 ;           // tmp_sum1 is the number which will replace the above mentioned number
            
    int transaction_results = replace(tmp_sum1,tmp_sum2,base_num);  //replace digit in previousBlockhash


    // Part 3 : adding BlockNumberFnResult , transaction_results and nonce to get our NewBlockHash
    int NewBlockHash = (BlockNumberFnResult + transaction_results + nonce) % 10000000; 

    return NewBlockHash;
}

int Validate_BlockChain(BlockChain Chain)   //Iterates from first block to second last, and checks if the nonce is correct for each. If not, then fixes it
{   
    Block ptr = Chain->Head;
    // if(ptr == Chain->Head)
    //     return 0;
    
    int flag = 0;

    while(ptr != Chain->CurrBlock)     // will stop when reaches Current Block as Current Block can't be attacked
    {
        int pBh = ptr->Next->PreviousBlockHash ;    //we are accessing the stored value of previousBlockhash (original value)
        int pBh_next = getpreviousBlockHash(ptr);   // here we are computing the new value to check the validity
        
        if(pBh!=pBh_next)         // if nonce does not match --> attack has happened 
        {
            for(int i=1;i<=500;i++)   // iterates through 1 to 500 to find the original nonce
            {
                ptr->Nonce = i;
                pBh_next = getpreviousBlockHash(ptr);
                if(pBh==pBh_next)  
                {
                    printf("\tBlock %d was attacked\n",ptr->BlockNumber);
                    flag = 1;
                    break;
                }
            }
        }
        ptr = ptr->Next;
    }
    return flag;
}

int Transact(int S_UID, int R_UID, double amount, BlockChain B, UsersArray UA ,UserHashTable UHT)   
{
    User sender = FindUser(S_UID, UA, UHT);  //Ht = data structure containing users

    if(sender->Balance >= amount)   //Checks if transactable amount is permissible by observing user balance
    {
        sender->Balance -= amount;  //Amount deducted/added from sender
        User receiver = FindUser(R_UID, UA, UHT);   //Searches for reciever through the user list
        receiver->Balance += amount;    //Amount added/deducted from reciever

        AddUserTransaction(S_UID, R_UID, amount, UA, UHT);  //Updates transaction for users
        AddBlockTransaction(S_UID, R_UID, amount, B);   //Updates transaction in the block
        return 1;
    }
    else
        return 0;   //If transaction is not viable, it returns a value signifying that the transaction has failed
    return 1;
}
