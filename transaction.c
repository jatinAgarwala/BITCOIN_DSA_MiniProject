#include "transaction.h"
#include "user.h"
#include <stdio.h>


int Transact(int S_UID, int R_UID, int Amount)
{
     User sender = Find_User(S_UID,Ht);  //Ht = data structure containing users

     if(sender->Balance >= Amount) {
          sender->Balance -= Amount;
          User receiver = Find_User(R_UID,Ht);
          receiver->Balance += Amount;

          addTransaction(sender->TransactionHistory,R_UID,-1*Amount);
          addTransaction(receiver->TransactionHistory,S_UID,Amount);
     }
     else return -1;
     
     //if user->balance >= Amount then deduct
     //if not return -1
     // update trans history of user
     //after deducting user balance (if deducted) then add amount to the R_UID by Finding it in User hash table/etc
     //update trans history of receiver
    
}
