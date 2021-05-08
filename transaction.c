#include "libs.h"

// if user->balance >= Amount then deduct
// if not return -1
// after deducting user balance (if deducted) then add amount to the R_UID by Finding it in UserHashTable
// update transaction history of both users

int Transact(int S_UID, int R_UID, double amount, BlockChain B, UsersArray UA ,UserHashTable UHT)   
{
    User sender = FindUser(S_UID, UA, UHT);  //Ht = data structure containing users

    if(sender->Balance >= amount)   //Checks if transactable amount is permissible by observing user balance
    {
        sender->Balance -= amount;  //Amount deducted/added from sender
        User receiver = Find_User(R_UID, UA, UHT);   //Searches for reciever through the user list
        receiver->Balance += amount;    //Amount added/deducted from reciever

        AddUserTransaction(S_UID, R_UID, amount, UA, UHT);  //Updates transaction for users
        AddBlockTransaction(S_UID, R_UID, amount, B);   //Updates transaction in the block
        return 1;
    }
    else
        return 0;   //If transaction is not viable, it returns a value signifying that the transaction has failed
    return 1;
}
