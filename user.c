#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int MOD_UID = 90000000;
int MIN_UID = 100000000;

srand(time(0));

const double InitialBalance = 1000;

char * Get_JoinDateTime()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // returns time in Day, Month/date time in hh:mm:ss year

   return asctime(timeinfo);
}

User InitUser()
{
    User temp = (User)malloc(sizeof(struct user));
    temp->Balance = InitialBalance;
    temp->JoinDateTime = Get_JoinDateTime();
    temp->TransactionHistory = NULL ; 
    return temp;
}

U_transactions InitUserTransaction(int UID,double amount)
{
    U_transactions Node = (U_transactions)malloc(sizeof(struct user_transactions));
    
    Node->UID = UID ;
    Node->Amount = amount ;
    Node->Next = NULL;

    return Node;
}

void AddUserTransaction(U_transactions TH  ,int UID, double amount) 
{
    U_transactions Node = InitUserTransaction(UID, amount);
    Node->Next = TH->Next;      //Adds the Node at the top
    TH->Next = Node ;
    return;
}

UserHashTable InitUserHashTable(int HTSize)
{
    UserHashTable tempUHT = (UserHashTable)malloc(sizeof(struct userHashTable));
    tempUHT->UserHT = (int*)malloc(sizeof(int)*HTSize);
    for (int i=0;i<HTSize;i++)
    {
        tempUHT->UserHT[i] = -1;
    }
    tempUHT->NumUsers=0;
    tempUHT->UHTSize = HTSize;
    return tempUHT;
}

UserHashTable ResizeUHT(UserHashTable UHT)
{

}


int UserHashFunction(int UID, UserHashTable UHT)
{

}

int* SearchUHT(int UID, UserHashTable UHT)
{
    int HashValue = UserHashFunction(UID, UHT);
    return &(UHT->UserHT[HashValue]);
}

int AddUser(int UserIndex, UserHashTable UHT)
{
    int flag=0;
    int UID;
    while(flag == 0)
    {
        UID = (rand()%MOD_UID) + MIN_UID;
        int* position = SearchUHT(UID, UHT);
        if (*position != -1)
        {
            continue;
        }
        else
        {
            *position = UserIndex;
            flag=1;
        }
    }
    UHT->NumUsers++;
    if(UHT->NumUsers == (UHT->UHTSize)/2)
    {
        ResizeUHT(UHT);
    }
    return UID;
}