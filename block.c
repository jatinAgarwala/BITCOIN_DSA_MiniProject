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

int Attack(PtrToBlock Head){//Head is pointer to 1st block
    int randnum = (rand()%50) + 1;
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
    if(randnum < 0){
        return 0;
    }
}

