#ifndef _Transaction_H
#define _Transaction_H

#include "libs.h"

typedef struct transaction* Transaction; 

struct transaction  // creating a struct that records a transaction performed/requested between users
{
    int S_UID ; //Sender Credentials
    int R_UID ; //Reciever Credentials
    double Amount ; // Amount to be Transferred
    Transaction Next;       //For the U_Transactions
};

typedef struct user_transactions* U_transactions;

struct user_transactions // creating a struct that records transaction of user
{
    int UID;    // User Credentials
    double Amount;  // Amount used in transaction
    U_transactions Next; // Next set of Transactions
};

int Transact(int S_UID, int R_UID, double amount, BlockChain B, UsersArray UA, UserHashFunction UHT);   // Initializing the Transact function

#endif
