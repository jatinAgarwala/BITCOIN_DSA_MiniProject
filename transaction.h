#ifndef _Transaction_H
#define _Transaction_H

typedef struct Transaction Trans_node; 

struct Transaction{

    int S_UID ;
    int R_UID ;
    double Amount ;
    Trans_node * pNext;

};






#endif

