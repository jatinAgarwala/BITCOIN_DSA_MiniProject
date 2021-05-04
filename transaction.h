#ifndef _Transaction_H
#define _Transaction_H

typedef struct transaction* Transaction; 

struct transaction
{
    int S_UID ;
    int R_UID ;
    double Amount ;
    Transaction Next;       //For the U_Transactions
};

typedef struct user_transactions* U_transactions;

struct user_transactions 
{
    int UID;
    double Amount;
    U_transactions Next; 
};

int Transact(int S_UID, int R_UID, int amount);

#endif
