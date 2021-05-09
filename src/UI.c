#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/UI.h"
#include "../include/block.h"
#include "../include/transaction.h"
#include "../include/user.h"

int UI_AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance) 
{
    User newUser = AddUser(UA, UHT, InitialBalance);
    printf("New user added with UID: %d\n", newUser->UID);
    return newUser->UID;
}

void UI_Transact(BlockChain B, UsersArray UA, UserHashTable UHT) 
{
    int S_UID, R_UID;
    double Amount;
    
    printf("Enter sender's UID: ");
    scanf("%d", &S_UID);
    User S = FindUser(S_UID,UA,UHT);
    if(S == NULL || S->UID != S_UID)
    {
        printf("Sorry... Invalid UID\n");
        return;
    }

    printf("Enter receiver's UID: ");
    scanf("%d", &R_UID);
    User R = FindUser(R_UID,UA,UHT);
    if(R == NULL || R->UID != R_UID)
    {
        printf("Sorry... Invalid UID\n");
        return;
    }

    if(S_UID == R_UID)
    {
        printf("You cannot transact with yourself xD\n");
        return;
    }

    printf("Enter the Transaction Amount: ");
    scanf("%lf", &Amount);
    int validTransaction = Transact(S_UID, R_UID, Amount, B, UA, UHT);

    if(validTransaction) 
        printf("Transaction was successful\n");
    else 
        printf("Transaction failed due to insufficient Balance\n");
    return;
}

void UI_Attack(BlockChain B) 
{
    int attackedBlock = Attack(B);
    if(attackedBlock>0) 
        printf("Block %d was attacked!\n", attackedBlock);
    else if(attackedBlock==0) 
        printf("Attack failed!\n");
    //else printf("Our function failed\n");
    return;
}

int UI_ValidateBlockChain(BlockChain B) 
{
    int vbcCheck = Validate_BlockChain(B);
    if(vbcCheck==0) 
        printf("No block was attacked. Block chain is valid\n");
    else 
        printf("Block chain has been validated\n");
    return vbcCheck;
}

void UI_PrintCurrentBlockInfo(BlockChain B) 
{
    printf("Current block:-\n");
    printf("\tBlock number: %d\n", B->CurrBlock->BlockNumber);
    printf("\tpreviousBlockHash: %d\n", B->CurrBlock->PreviousBlockHash);
    printf("\tNonce: %d\n", B->CurrBlock->Nonce);
    printf("\tNumber of transactions: %d\n", B->CurrBlock->numTransaction);
    printf("\tTransactions -\n");
    for(int i=0; i<B->CurrBlock->numTransaction; i++) 
    {
        printf("\t\tSender UID: %d\t", B->CurrBlock->TransactionArray[i]->S_UID);
        printf("\t\tReceiver UID: %d\t", B->CurrBlock->TransactionArray[i]->R_UID);
        printf("\t\tAmount: %lg\n", B->CurrBlock->TransactionArray[i]->Amount);
    }
    return;
}

void UI_PrintInfoBlock(BlockChain B) 
{
    int blockNumber;
    printf("Enter block number: ");
    scanf("%d", &blockNumber);
    Block ptr = B->Head;
    while(ptr!=NULL) {
        if(ptr->BlockNumber==blockNumber) 
        {
            printf("\tBlock number: %d\n", ptr->BlockNumber);
            printf("\tpreviousBlockHash: %d\n", ptr->PreviousBlockHash);
            printf("\tNonce: %d\n", ptr->Nonce);
            printf("\tNumber of transactions: %d\n", ptr->numTransaction);
            printf("\tTransactions -\n");
            for(int i=0; i<ptr->numTransaction; i++) 
            {
                printf("\t\tSender UID: %d\t", ptr->TransactionArray[i]->S_UID);
                printf("\t\tReceiver UID: %d\t", ptr->TransactionArray[i]->R_UID);
                printf("\t\tAmount: %lg\n", ptr->TransactionArray[i]->Amount);
            }
            return;
        }
        ptr = ptr->Next;
    }
    printf("Sorry... Invalid Block Number\n");
    return;
}

void UI_PrintUserInfo(UsersArray UA , UserHashTable UHT) 
{
    int UID;
    printf("Enter UID: ");
    scanf("%d", &UID);
    User userptr = FindUser(UID, UA, UHT);

    if(userptr == NULL || userptr->UID != UID)
    {
        printf("Sorry... Invalid UID\n");
        return;
    }

    printf("User details -\n");
    printf("\tUID: %d\n", UID);
    printf("\tBalance: %lg\n", userptr->Balance);
    printf("\tJoin date/time: %s\n", userptr->JoinDateTime);
    
    U_transactions ptr = userptr->TransactionHistory->Next;
    if(ptr == NULL)
    {
        printf("\tThe user has made no transactions\n");
        return;
    }

    printf("\tTransaction History -\n");
    while(ptr!=NULL) 
    {
        if(ptr->Amount > 0)
            printf("\t\tReceived %lg BTC from %d\n",ptr->Amount,ptr->UID);
        else if(ptr->Amount < 0)
            printf("\t\tSent %lg BTC to %d\n",(ptr->Amount)*(-1),ptr->UID);
        // printf("\t\tUID: %d\n", ptr->UID);
        // printf("\t\tAmount: %lg\n", ptr->Amount);
        ptr = ptr->Next;
    }
    return;
}

void UI_PrintAll_UIDs(UsersArray UA) 
{
    printf("UIDs -\n");
    for(int i=0; i<UA->CurrIndex; i++) 
    {
        printf("\t%d has Balance: %lg\n", UA->ArrayOfUsers[i]->UID, UA->ArrayOfUsers[i]->Balance);
    }
    return;
}

void UI_PrintNumBlocks(BlockChain B) 
{
    printf("Number of Blocks in BlockChain: %d\n", B->NumBlocks);
    return;
}
