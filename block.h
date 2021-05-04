#ifndef BLOCK_H
#define BLOCK_H
#include "transaction.h" 

typedef struct block Block ;
typedef Block* PtrToBlock ;

struct block
{
    int BlockNumber;
    int PreviousBlockHash;   //TBD
    int Nonce;    //TBD
    Transaction Transaction_Array[50];    
    int numTransaction;                   // Update of no. of Transactions

    // need doubly link list
    PtrToBlock Next;  
    PtrToBlock Prev;  
};

PtrToBlock InitBlock();

void AddBlockTransaction(int S_UID, int R_UID, int amount);

#endif
