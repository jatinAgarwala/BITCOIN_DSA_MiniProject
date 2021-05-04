#include "block.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
