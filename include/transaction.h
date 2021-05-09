#ifndef _Transaction_H
#define _Transaction_H

typedef struct transaction* Transaction; 
typedef struct user_transactions* U_transactions;

struct transaction
{
    int S_UID ;             // sender's UID
    int R_UID ;             // receiver's UID
    double Amount ;         // Amount to be transferred
};

struct user_transactions 
{
    int UID;                // UID of the other user in transaction 
    double Amount;          // Amount to be transferred 
    U_transactions Next;    // pointer to the next transaction in transaction history of a user
};

Transaction InitTransaction();
U_transactions InitU_Transaction();

#endif
