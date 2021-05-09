#include <stdlib.h>
#include <stdio.h>
#include "../include/transaction.h"

Transaction InitTransaction()                           // initialising transaction structs for transaction array
{
    Transaction temp = (Transaction)malloc(sizeof(struct transaction));   //alocates memory to struct transaction in transaction array
    temp->S_UID = -1;
    temp->R_UID = -1;
    temp->Amount = 0;
    return temp;
}

U_transactions InitU_Transaction()                // initialises struct user_transaction for transaction history of a user
{
    U_transactions temp = (U_transactions)malloc(sizeof(struct user_transactions));  //allocates memory 
    temp->Amount = 0;  
    temp->UID = -1;
    temp->Next = NULL;
    return temp;
}
