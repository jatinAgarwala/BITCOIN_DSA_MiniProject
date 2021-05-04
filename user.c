#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

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

U_transactions MakeUserTransaction(int UID,double amount)
{
    U_transactions Node = (U_transactions)malloc(sizeof(struct user_transactions));
    
    Node->UID = UID ;
    Node->Amount = amount ;
    Node->Next = NULL;

    return Node;
}

void AddUserTransaction(U_transactions TH  ,int UID, double amount) 
{
    U_transactions Node = Make_UserTH_Node(UID, amount);
    Node->Next = TH->Next;      //Adds the Node at the top
    TH->Next = Node ;
    return;
}
