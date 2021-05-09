#ifndef BLOCK_H
#define BLOCK_H

#include "transaction.h"
#include "user.h"

typedef struct block* Block;
typedef struct blockChain* BlockChain;

struct block
{
    int BlockNumber;                      // Block number of the block in the blockchain
    int PreviousBlockHash;                // HashFunction value of previous block     
    int Nonce;                            // Randomly generated number between 1-500
    Transaction TransactionArray[50];     // Transaction History of the Block
    int numTransaction;                   // Update of no. of Transactions
    
    // need doubly link list
    Block Next;        // pointer to the next Block
    Block Prev;        // pointer to the previous Block
};

struct blockChain
{
    Block Head;               // Pointer to the Head Block                
    Block CurrBlock;          // Pointer to the Current empty/partially filled block
    int NumBlocks;            // stores the number of Blocks in the Blockchain
};

Block InitBlock();            
BlockChain InitBlockChain();

int getpreviousBlockHash(Block block_node);

void AddBlock(BlockChain B);
void AddBlockTransaction(int S_UID, int R_UID, double amount, BlockChain B);

int Attack(BlockChain B);
int Validate_BlockChain(BlockChain Chain);

int Transact(int S_UID, int R_UID, double amount, BlockChain B, UsersArray UA, UserHashTable UHT);   // Initializing the Transact function

#endif
