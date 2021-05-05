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

typedef struct userHashTable* UserHashTable;

struct userHashTable
{
    int* UserHT;
    int NumUsers;
    int UHTSize;
};

int UserHashFunction(int UID, UserHashTable UHT);
UserHashTable ResizeUHT(UserHashTable UHT);
int AddUser(int UserIndex, UserHashTable); 
int* SearchUHT(int UID, UserHashTable UHT);

User InitUser();
UserHashTable InitUserHashTable(int HTSize);

U_transactions InitUserTransaction(int UID,double amount);
void AddUserTransaction(U_transactions TH  ,int UID, double amount);

User FindUser(int UID, UserHashTable UHT);

#endif
