#include <stdlib.h>
#include <stdio.h>
#include "../include/transaction.h"

Transaction InitTransaction()
{
    Transaction temp = (Transaction)malloc(sizeof(struct transaction));
    temp->S_UID = -1;
    temp->R_UID = -1;
    temp->Amount = 0;
    return temp;
}

U_transactions InitU_Transaction()
{
    U_transactions temp = (U_transactions)malloc(sizeof(struct user_transactions));
    temp->Amount = 0;
    temp->Next = NULL;
    temp->UID = -1;
    return temp;
}
