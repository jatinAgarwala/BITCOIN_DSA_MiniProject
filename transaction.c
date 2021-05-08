#include "libs.h"

// if user->balance >= Amount then deduct
// if not return -1
// after deducting user balance (if deducted) then add amount to the R_UID by Finding it in UserHashTable
// update transaction history of both users

int Transact(int S_UID, int R_UID, double amount, BlockChain B, UsersArray UA ,UserHashTable UHT)   
{
    User sender = FindUser(S_UID, UA, UHT);  //Ht = data structure containing users

    if(sender->Balance >= amount) 
    {
        sender->Balance -= amount;
        User receiver = Find_User(R_UID, UA, UHT);
        receiver->Balance += amount;

        AddUserTransaction(S_UID, R_UID, amount, UA, UHT);
        AddBlockTransaction(S_UID, R_UID, amount, B);
        return 1;
    }
    else
        return 0;
    return 1;
}
