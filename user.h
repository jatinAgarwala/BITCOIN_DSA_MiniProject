#ifndef _USER_H
#define _USER_H

#include "transaction.h"

typedef struct user* User;

struct user
{
    int UID;
    double Balance;
    U_transactions TransactionHistory;
    char* JoinDateTime;  
};

User InitUser();
U_transactions InitUserTransaction(int UID,double amount);
void AddUserTransaction(U_transactions TH  ,int UID, double amount);

User FindUser(int UID, UserHashTable UHT);

#endif
