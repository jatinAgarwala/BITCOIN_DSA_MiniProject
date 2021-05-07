#ifndef BLOCK_H
#define BLOCK_H
#include "transaction.h" 

typedef struct block* Block;

struct block
{
    int BlockNumber;
    int PreviousBlockHash;   //TBD
    int Nonce;    //TBD
    Transaction TransactionArray[50];    
    int numTransaction;                   // Update of no. of Transactions

    // need doubly link list
    Block Next;  
    Block Prev;  
};

typedef struct blockChain* BlockChain;

struct blockChain
{
    Block Head;
    Block CurrBlock;
    int NumBlocks;
};

Block InitBlock();
BlockChain InitBlockChain();

int getpreviousBlockHash(Block block_node);

void AddBlock(BlockChain B);
void AddBlockTransaction(int S_UID, int R_UID, int amount, BlockChain B);
int Attack(BlockChain B);
// Create block function after a block is filled
#endif
