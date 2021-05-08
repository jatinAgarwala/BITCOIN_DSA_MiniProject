#ifndef BLOCK_H
#define BLOCK_H

#include "libs.h" 

typedef struct block* Block;

struct block    // Created a structure for Block
{
    int BlockNumber;
    int PreviousBlockHash;                // HashFunction value of previous block
    int Nonce;                            // Randomly generated number between 1-500
    Transaction TransactionArray[50];     // Transaction History of the Block
    int numTransaction;                   // Update of no. of Transactions

    // need doubly link list to traverse both ways
    Block Next;  
    Block Prev;  
};

typedef struct blockChain* BlockChain;

struct blockChain   //Creates Blockchain
{
    Block Head; //Head of the blockchain(?)
    Block CurrBlock;    //Current block
    int NumBlocks;  //Number of blocks in chain
};

Block InitBlock();  //Initializes a block
BlockChain InitBlockChain();    //Initializes a blockchain

int getpreviousBlockHash(Block block_node); //Obtains hash values for the previous block (to verify nonce stuff??????)

void AddBlock(BlockChain B);    //Initialized AddBlock function to add a block to the blockchain
void AddBlockTransaction(int S_UID, int R_UID, double amount, BlockChain B);    //Initialized AddBlockTransaction so that it Adds a block transaction

int Attack(BlockChain B);   // Initialized function to attack a blockchain
int Validate_BlockChain(BlockChain Chain)   // Initialized function to validate blockchain

#endif
