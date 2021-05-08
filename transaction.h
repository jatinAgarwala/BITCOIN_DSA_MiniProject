#ifndef _Transaction_H
#define _Transaction_H

typedef struct transaction* Transaction; 
typedef struct user_transactions* U_transactions;

struct transaction
{
    int S_UID ;
    int R_UID ;
    double Amount ;
    Transaction Next;       //For the U_Transactions
};

struct user_transactions 
{
    int UID;
    double Amount;
    U_transactions Next; 
};

Transaction InitTransaction();
U_transactions InitU_Transaction();

#endif
