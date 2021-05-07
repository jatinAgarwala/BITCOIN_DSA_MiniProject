#include "transaction.h"
#include "user.h"
#include "block.h"
#include <stdio.h>
#include <stdlib.h>

int Transact(int S_UID, int R_UID, int amount, BlockChain B, UsersArray UA ,UserHashTable UHT)   
{
    User sender = FindUser(S_UID,UHT);  //Ht = data structure containing users

    if(sender->Balance >= amount) 
    {
        sender->Balance -= amount;
        User receiver = Find_User(R_UID,Ht);
        receiver->Balance += amount;

        AddUserTransaction(sender->TransactionHistory,R_UID,-1*amount);
        AddUserTransaction(receiver->TransactionHistory,S_UID,amount);

        AddBlockTransaction(sender, receiver, amount, B);
    }
    else
        return -1;

    //if user->balance >= Amount then deduct
    //if not return -1
    // update trans history of user
    //after deducting user balance (if deducted) then add amount to the R_UID by Finding it in User hash table/etc
    //update trans history of receiver

}
