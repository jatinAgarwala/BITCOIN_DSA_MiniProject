#ifndef BLOCK_H
#define BLOCK_H

#include "libs.h" 

typedef struct block* Block;

struct block
{
    int BlockNumber;
    int PreviousBlockHash;                // HashFunction value of previous block
    int Nonce;                            // Randomly generated number between 1-500
    Transaction TransactionArray[50];     // Transaction History of the Block
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
void AddBlockTransaction(int S_UID, int R_UID, double amount, BlockChain B);

int Attack(BlockChain B);
int Validate_BlockChain(BlockChain Chain)

#endif
