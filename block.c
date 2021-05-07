#include "block.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

srand(time(0));

PtrToBlock InitBlock()
{
    PtrToBlock Temp = (PtrToBlock)malloc(sizeof(Block));
    Temp->PreviousBlockHash = 0;
    Temp->BlockNumber = 0;
    Temp->Next = NULL;
    Temp->Prev = NULL;
    Temp->Nonce = (rand()%500)+1 ;
    return Temp;
}

void AddBlockTransaction(int S_UID, int R_UID, int amount, BlockChain B)
{
    
}

int Attack(BlockChain B)    //Head is pointer to 1st block
{
    PtrToBlock Head = B->Head;
    int randnum = (rand()%50) + 1;
    if(randnum >= B->NumBlocks)
        return 0;
    
    int blocknum = (randnum);
    randnum--;
    PtrToBlock tmp = Head;
    while(tmp->Next != NULL){
        if(randnum == 0){
            int r = rand()%500 + 1;
            if(r == tmp->Nonce){
                tmp->Nonce = r+1;
            }
            else 
                tmp->Nonce = r;
            return blocknum;
        }
        else{
            randnum--;
            tmp = tmp->Next;
        }
    }

    if(randnum < 0)
        return 0;
    return -1;              //It should never return -1, but having this as a check
}


int power(int base, int POW_ER)
{
    int ret_value = 1;
    while(POW_ER--)
    {
        ret_value *= base ;         
    }
    return ret_value ;
}

int replace(int digit,int digit_posn, int Original_num) {
      int Modified_num = Original_num   ;  //123456
    Modified_num  /= power(10, digit_posn);             //1234
    Modified_num -= Modified_num%10;      //1230
    Modified_num += digit;        //1236
    Modified_num *= power(10, digit_posn);   //123600
    Modified_num += Original_num%power(10, digit_posn);
   
   return Modified_num  ;
}


//To calculate previousBlockHash of a block
int getpreviousBlockHash(int BlockNumber, Transaction transactions, int previousBlockHash, int nonce) {
          
    
    if(previousBlockHash==0)          // for Block 1/head block
    previousBlockHash = 123456;

    int base_num = previousBlockHash; 

    //Using BlockNumber 'function'
    int BlockNumberFnResult;
    int BlockNumbertemp = BlockNumber;
    int prod = 1;
    while(BlockNumbertemp>0) {
        prod *= BlockNumbertemp%10;
        BlockNumbertemp /= 10;
    }
    prod = prod%6;      //prod gives us the digit of the base_num that is to be changed
    int newDigit = (power(BlockNumber, 2))%10;
     
    int BlockNumberFnResult = replace(newDigit,prod,base_num);

    int tmp1,tmp2,tmp_sum=0;
    for(int i=0;i<50;i++)
    {
        tmp1 =  transactions[i].S_UID + transactions[i].R_UID ; 
        tmp1 *= ( (int) transactions[i].Amount/50 ) % power(10,7) ;
        tmp_sum  += tmp1  ;
    }

        tmp_sum = tmp_sum%6 ;
        int tmp_sum1 = tmp_sum%6;
        int transation_results = replace(tmp_sum % 10,tmp_sum1,base_num);//replace digit in previousBlockhash

        int NewBlockHash = (BlockNumberFnResult + transation_results + nonce) % power(10,7);


    return NewBlockHash;
}
