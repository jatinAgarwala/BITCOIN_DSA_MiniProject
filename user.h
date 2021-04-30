#ifndef _USER_H
#define _USER_H

#include "transaction.h"

typedef struct user* User;

struct user
{
    int UID;
    double Balance;
    Transaction TransactionHistory;
    char* JoinDateTime;  
};

User InitUser();
char * Get_JoinDateTime();



#endif

