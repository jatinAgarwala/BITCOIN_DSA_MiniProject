#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UI.h"
#include "block.h"
#include "transaction.h"
#include "user.h"

int UI_AddUser(UsersArray UA, UserHashTable UHT) {
    User newUser = AddUser(UA, UHT);
    printf("New user added with UID: %d\n", newUser->UID);
    return newUser->UID;
}

void UI_Transact(BlockChain B, UsersArray UA, UserHashTable UHT) {
    int S_UID, R_UID;
    double Amount;
    printf("Enter your UID: ");
    scanf("%d", &S_UID);
    printf("Enter receiver UID: ");
    scanf("%d", &R_UID);
    printf("Enter the Transaction Amount: ");
    scanf("%lf", &Amount);
    int validTransaction = Transact(S_UID, R_UID, Amount, B, UA, UHT);
    if(validTransaction) {
        printf("Transaction was successful\n");
    }
    else printf("Transaction failed\n");
}

void UI_Attack(BlockChain B) {
    int attackedBlock = Attack(B);
    if(attackedBlock>0) {
        printf("Block %d was attacked\n", attackedBlock);
    }
    else if(attackedBlock==0) {
        printf("Attack failed\n");
    }
    ///else printf("Our fn faile\n");
}

int UI_ValidateBlockChain(BlockChain B) {
    int vbcCheck = Validate_BlockChain(B);
    if(vbcCheck==0) {
        printf("No block was attacked. Block chain is valid\n");
    }
    else printf("Block chain has been validated\n");
}
