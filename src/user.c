#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "../include/user.h"

int MOD_UID = 90000000;
int MIN_UID = 100000000;

char * Get_JoinDateTime()       // returns time in Day, Month/date time in hh:mm:ss year
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

   return asctime(timeinfo);
}

User InitUser()     //Allocates memory for a new user
{
    User temp = (User)malloc(sizeof(struct user));
    temp->Balance = 0;
    temp->JoinDateTime = Get_JoinDateTime();
    temp->TransactionHistory = InitU_Transaction(); 
    return temp;
}

U_transactions InitUserTransaction(int UID,double amount)   //Allocates memory for a new U_Transaction
{
    U_transactions Node = (U_transactions)malloc(sizeof(struct user_transactions));
    
    Node->UID = UID ;
    Node->Amount = amount ;
    Node->Next = NULL;

    return Node;
}

UsersArray InitUsersArray(int UASize)      //Allocates memory for UsersArray
{
    UsersArray tempUA = (UsersArray)malloc(sizeof(struct usersArray));
    tempUA->ArrayOfUsers = (User*)malloc(sizeof(User)*(UASize+1));
    for(int i=0;i<UASize;i++)
        tempUA->ArrayOfUsers[i]=NULL;
    tempUA->ArraySize = UASize;
    tempUA->CurrIndex = 0;
    return tempUA;
}

UserHashTable InitUserHashTable(int HTSize)     //Allocates memory for UserHashTable
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

void ResizeUA(UsersArray* UA)    //Resizes the UsersArray if it gets filled
{
    (*UA)->ArrayOfUsers = realloc((*UA)->ArrayOfUsers, 2*((*UA)->ArraySize));
    (*UA)->ArraySize = ((*UA)->ArraySize)*2;
    return;
}

void DeleteUHT(UserHashTable* UHT)   //Deletes the User HashTable. This is used when we have to resize the UHT
{
    free((*UHT)->UserHT);
    free(*UHT);
    return;
}

UserHashTable ResizeUHT(UsersArray UA, UserHashTable* UHT)      //Resizes UHT to double the current size if it's filled up 50%
{
    UserHashTable NewUHT = InitUserHashTable(((*UHT)->UHTSize)*2);
    for(int i=0;i<(*UHT)->UHTSize;i++)
    {
        if(((*UHT)->UserHT[i] != -1))
        {
            int userIndex = (*UHT)->UserHT[i];
            if(userIndex==UA->CurrIndex) {
                continue;
            }
            int UIDcurr = UA->ArrayOfUsers[userIndex]->UID;
            int newIndex = UserHashFunction(UIDcurr, NewUHT); 
            NewUHT->UserHT[newIndex] = userIndex;
            NewUHT->NumUsers++;
        }
    }
    DeleteUHT(UHT);
    return NewUHT;
}

int UserHashFunction(int UID, UserHashTable UHT)    //Hash function that takes input the UID and returns an index of the UHT
                                                    //The index of the UHT stores the index of the User in the UsersArray
{
    return UID%UHT->UHTSize;
}

int* SearchUHT(int UID, UserHashTable UHT)          //Takes input the UID and uses the hash function to return the value stored at that index of UHT
                                                    //If the index is free, then it will return -1, otherwise the userIndex of the user in the UsersArray
{
    int HashValue = UserHashFunction(UID, UHT);
    return &(UHT->UserHT[HashValue]);
}

int AddUserUHT(int UserIndex, UsersArray UA, UserHashTable* UHT)     //Takes input the index of the user in UserArray and stores it in the index returned by the HashFunction
                                                                    //when it takes the UID as input. The function returns the random UID generated
{
    int flag=0;
    int UID;
    while(flag == 0)
    {
        UID = (rand()%MOD_UID) + MIN_UID;
        int* position = SearchUHT(UID, *UHT);
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
    (*UHT)->NumUsers++;
    if((*UHT)->NumUsers == ((*UHT)->UHTSize)/2)
    {
        *UHT = ResizeUHT(UA, UHT);
    }
    return UID;
}

User AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance)  //Adds a new user, returns the pointer to the User (which also stores the randomly generated UID)
{
    User Temp = InitUser();
    Temp->Balance = InitialBalance;
    Temp->UID = AddUserUHT((*UA)->CurrIndex, *UA, UHT);
    //printf("New User UID = %d\n",Temp->UID);
    (*UA)->ArrayOfUsers[(*UA)->CurrIndex] = Temp;
    (*UA)->CurrIndex++;
    if((*UA)->CurrIndex == (*UA)->ArraySize)
        ResizeUA(UA);
    return Temp;
}

User FindUser(int UID, UsersArray UA, UserHashTable UHT)    //Uses UID to return the pointer to the struct user that stores the information
{
    int* index = SearchUHT(UID, UHT);
    if(*index == -1)
        return NULL;
    return UA->ArrayOfUsers[*index];
}

void AddUserTH(U_transactions TH, int UID, double amount)     //Add a transaction to a user's U_Transactions. The top transaction is the latest
{
    U_transactions Node = InitUserTransaction(UID, amount);
    Node->Next = TH->Next;      //Adds the Node at the top
    TH->Next = Node ;
    return;
}

void AddUserTransaction(int S_UID, int R_UID, double amount, UsersArray UA, UserHashTable UHT)  //The actual function that uses previous functions to update
                    // the User Transaction history of the users involved in a transaction
{
    User S = FindUser(S_UID, UA, UHT);
    User R = FindUser(R_UID, UA, UHT);

    AddUserTH(S->TransactionHistory, R_UID, (-1)*amount);
    AddUserTH(R->TransactionHistory, S_UID, amount);
    return;
}
