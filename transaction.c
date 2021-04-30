#include "transaction.h"
#include "user.h"
#include <stdio.h>


void Transact(int S_UID, int R_UID, int Amount)
{
     User ptr = Find_User(S_UID,Ht);  //Ht = data structure containing users
     

     //if user->balance >= Amount then deduct
     //if not return -1
     // update trans history of user
     //after deducting user balance (if deducted) then add amount to the R_UID by Finding it in User hash table/etc
     //update trans history of receiver
    
}
