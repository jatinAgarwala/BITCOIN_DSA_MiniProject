#ifndef _USER_H
#define _USER_H

#include "transaction.h"

typedef struct user* User;
typedef struct usersArray* UsersArray;
typedef struct userHashTable* UserHashTable;

struct user             //struct to store the information of each user
{
    int UID;                                // UID of the user
    double Balance;                         // Wallet balance
    U_transactions TransactionHistory;      //Stores the transaction history of the user in the form of a linked list of Transactions. The latest is at the top
    char* JoinDateTime;                     // Joining Date Time
};

//  We are using a Separate Hash Table to store the indices of the User in the UserArray so that we can store the Users sequentially
//  The biggest advantage of storing Users sequentially is that if the array is filled, we can simply call a realloc to increase the size.
//  The benefit of this is that if continuous memory is available, realloc will simply increase the size of the current array, and there will be no need to copy the entire structs
//  The resizing of the Hash Table will not be as computationally expensive since we would only be copying integers (UIDs and user indices only)

struct usersArray       //An array of Users, in which each new user is stored sequentially. To access it, use the userHashTable and the UID
{
    User* ArrayOfUsers; //The array is allocated with the ArraySize number of Users (which are pointers to the struct) So memory has to be allocated when a new user is added
    int CurrIndex;      // gives us the index where we can store the user in the user array
    int ArraySize;      // the size of the user array
};

struct userHashTable    //hash table that stores the index at which a user is present in the UsersArray, using the UID and UserHashFunction
{
    int* UserHT;        // pointer to the hash table
    int NumUsers;       // Number of Users in the hash table (we use this data to check if the hash table needs to be resized or not)
    int UHTSize;        // Hash Table Size
};


User InitUser();
UserHashTable InitUserHashTable(int HTSize);
UsersArray InitUsersArray(int UASize);
void ResizeUA(UsersArray* UA);
U_transactions InitUserTransaction(int UID,double amount);
UserHashTable ResizeUHT(UsersArray UA, UserHashTable* UHT); 
void DeleteUHT(UserHashTable* UHT);

int UserHashFunction(int UID, UserHashTable UHT);

User AddUser(UsersArray* UA, UserHashTable* UHT, double InitialBalance);
int AddUserUHT(int UserIndex, UsersArray UA, UserHashTable* UHT);  
void AddUserTH(U_transactions TH  ,int UID, double amount);
int* SearchUHT(int UID, UserHashTable UHT);


User FindUser(int UID, UsersArray UA, UserHashTable UHT);
void AddUserTransaction(int S_UID, int R_UID, double amount, UsersArray UA, UserHashTable UHT);

#endif
