#ifndef BLOCK_H
#define BLOCK_H
// Include transaction.h too

typedef struct block Block ;
typedef Block* PtrToBlock ;
struct block
{
    int BlockNumber;
    int PreviousBlockHash;
    int Nonce;
    // transactioninfo transactions[50];
    int numTransaction;
    PtrToBlock Next;
    PtrToBlock Prev;  
};

PtrToBlock InitBlock();

#endif

