#include "../include/transaction.h"
#include "../include/user.h"
#include "../include/block.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/UI.h"
#include <string.h>

#define UHTsize 1000
#define UAsize 1000

int test_AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance) {
    User A = AddUser(UA, UHT, InitialBalance);
    User checkA = FindUser(A->UID, *UA, *UHT);
    if(A==checkA) {
        printf("Test AddUser function has passed\n");
        return 1;
    }
    else {
        printf("Test AddUser function has failed\n");
        return 0;
    }
}

int test_Transact(BlockChain B, UsersArray* UA, UserHashTable* UHT, double InitialBalance) {
    User S = AddUser(UA, UHT, InitialBalance);
    User R = AddUser(UA, UHT, InitialBalance);
    double Amount;
    double SInitialBalance = S->Balance;
    double RInitialBalance = R->Balance;
    Amount = rand()%((int)S->Balance);
    int transactionResult = Transact(S->UID, R->UID, Amount, B, *UA, *UHT);
    if(transactionResult==1) {          //this should always be the case
        if(S->Balance+Amount==SInitialBalance &&R->Balance-Amount==RInitialBalance) {
            printf("Test Transact function has passed\n");
            return 1;
        }
        else {
            printf("Test Transact function has failed\n");
            return 0;
        }
    }        
}

int test_Attack(BlockChain B, UsersArray* UA, UserHashTable* UHT, double InitialBalance) {
    User S = AddUser(UA, UHT, InitialBalance);
    User R = AddUser(UA, UHT, InitialBalance);
    double Amount;
    double SInitialBalance = S->Balance;
    Amount = (S->Balance)/2;
    for(int i=0; i<2502; i++) {
        if(i%2==0) {
            Transact(S->UID, R->UID, Amount, B, *UA, *UHT);
        }
        else Transact(R->UID, S->UID, Amount, B, *UA, *UHT);
    }
    int numBlocks = B->NumBlocks;
    int prevNonceVals[numBlocks];
    Block ptr = B->Head;
    int i=0;
    while(ptr!=NULL) {
        prevNonceVals[i] = ptr->Nonce;
       // printf("%d ", prevNonceVals[i]);
        i++;
        ptr = ptr->Next;
    }
   // printf("\n");
    int Result = 0;
    int attackResult = Attack(B);
    if(attackResult>0) {
        ptr = B->Head;
        while(ptr!=NULL) {
            if(ptr->BlockNumber==attackResult) {
                //printf("Attacked, old, new: %d %d %d\n", ptr->BlockNumber, prevNonceVals[ptr->BlockNumber-1], ptr->Nonce);
                break;
            }
            ptr = ptr->Next;
        }
        if(prevNonceVals[attackResult-1]==ptr->Nonce) {
            printf("Test Attack function failed\n");
            return 0;
        }
        else {
            printf("Test Attack function passed\n");
            Result++;
            //printf("%d\n", Validate_BlockChain(B));
            Validate_BlockChain(B);
            //printf("Updated: %d\n", ptr->Nonce);
            if(prevNonceVals[attackResult-1]==ptr->Nonce) {
                printf("Test ValidateBlockChain function has passed\n");
                Result++;
            }
            else printf("Test ValidateBlockChain function has failed\n");
            return Result;
        }
    }
}

int test_PrintAllUIDs(UsersArray* UA, UserHashTable* UHT, double InitialBalance) {
    int UIDvals[1600] = {0};
    for(int i=0; i<1600; i++) {
        //printf("%d\n", (*UA)->ArraySize);
        User newUser = AddUser(UA, UHT, InitialBalance);
        UIDvals[i] = newUser->UID;
        //printf("%d\n", UIDvals[i]);
    }
    for(int i=0; i<(*UA)->CurrIndex; i++) 
    {
        if(UIDvals[i]!=(*UA)->ArrayOfUsers[i]->UID) {
            printf("Test PrintAllUIDs function failed\n");
            return 0;
        }
    }
    printf("Test PrintAllUIDs function passed\n");
    return 1;
}

int test_PrintNumBlocks(UsersArray* UA, UserHashTable* UHT, double InitialBalance) {
    BlockChain BChainTest = InitBlockChain();
    User S = AddUser(UA, UHT, InitialBalance);
    User R = AddUser(UA, UHT, InitialBalance);
    double Amount;
    Amount = (S->Balance)/2;
    int numTransactions = rand()%5001;
    for(int i=0; i<numTransactions; i++) {
        if(i%2==0) {
            Transact(S->UID, R->UID, Amount, BChainTest, *UA, *UHT);
        }
        else Transact(R->UID, S->UID, Amount, BChainTest, *UA, *UHT);
    }
    //printf("%d\n", BChainTest->NumBlocks);
    int expectedNumBlocks = numTransactions/50;
    if(numTransactions%50!=0) {
        expectedNumBlocks++;
    }
    //printf("Expected: %d\n", expectedNumBlocks);
    if(BChainTest->NumBlocks==expectedNumBlocks) {
        printf("Test PrintNumBlocks function has passed\n");
        return 1;
    }
    printf("Test Print NumBlocks function has failed\n");
    return 0;
}

int main() {
    double InitialBalance = 5000;

    srand(time(NULL));

    BlockChain B = InitBlockChain();    //Creating a blockchain
    UserHashTable UHT = InitUserHashTable(UHTsize); //Creating a UserHashTable
    UsersArray UA = InitUsersArray(UAsize); //Creating an Array where UserInfo is stored

    int tcs=0;

    tcs += test_PrintAllUIDs(&UA, &UHT, InitialBalance);        //this function also checks ResizeUA and ResizeUHT
    tcs += test_AddUser(&UA, &UHT, InitialBalance);
    tcs += test_Transact(B, &UA, &UHT, InitialBalance);
    tcs += test_Attack(B, &UA, &UHT, InitialBalance);           //this function also checks for ValidateBlockChain
    tcs += test_PrintNumBlocks(&UA, &UHT, InitialBalance);

    printf("%d test cases out of %d have passed\n", tcs, 6);
    return 0;
}
