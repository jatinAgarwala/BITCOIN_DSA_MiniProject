#include "libs.h"

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

void UI_PrintCurrentBlockInfo(BlockChain B) {
    printf("Current block:-\n");
    printf("\tBlock number: %d\n", B->CurrBlock->BlockNumber);
    printf("\tpreviousBlockHash: %d\n", B->CurrBlock->PreviousBlockHash);
    printf("\tNonce: %d\n", B->CurrBlock->Nonce);
    printf("\tNumber of transactions: %d\n", B->CurrBlock->numTransaction);
    printf("\tTransactions -\n");
    for(int i=0; i<B->CurrBlock->numTransaction; i++) {
        printf("\t\tSender UID: %d\n", B->CurrBlock->TransactionArray[i]->S_UID);
        printf("\t\tReceiver UID: %d\n", B->CurrBlock->TransactionArray[i]->R_UID);
        printf("\t\tAmount: %lf\n", B->CurrBlock->TransactionArray[i]->Amount);
    }
}

void UI_PrintInfoBlock(BlockChain B) {
    int blockNumber;
    printf("Enter block number: ");
    scanf("%d", &blockNumber);
    Block ptr = B->Head;
    while(ptr!=NULL) {
        if(ptr->BlockNumber==blockNumber) {
            printf("\tBlock number: %d\n", ptr->BlockNumber);
            printf("\tpreviousBlockHash: %d\n", ptr->PreviousBlockHash);
            printf("\tNonce: %d\n", ptr->Nonce);
            printf("\tNumber of transactions: %d\n", ptr->numTransaction);
            printf("\tTransactions -\n");
            for(int i=0; i<ptr->numTransaction; i++) {
                printf("\t\tSender UID: %d\n", ptr->TransactionArray[i]->S_UID);
                printf("\t\tReceiver UID: %d\n", ptr->TransactionArray[i]->R_UID);
                printf("\t\tAmount: %lf\n", ptr->TransactionArray[i]->Amount);
            }
            return;
        }
        ptr = ptr->Next;
    }
}

void UI_PrintUserInfo(UsersArray UA , UserHashTable UHT) {
    int UID;
    printf("Enter UID: ");
    scanf("%d", &UID);
    User userptr = FindUser(UID, UA, UHT);
    printf("User details -\n");
    printf("\tUID: %d\n", UID);
    printf("\tBalance: %lf\n", userptr->Balance);
    printf("\tJoin date/time: %s\n", userptr->JoinDateTime);
    printf("\tTransaction History -\n");
    U_transactions ptr = userptr->TransactionHistory;
    while(ptr!=NULL) {
        printf("\t\tUID: %d\n", ptr->UID);
        printf("\t\tAmount: %lf\n", ptr->Amount);
        ptr = ptr->Next;
    }
}

void UI_PrintAll_UIDs(UsersArray UA) {
    printf("UIDs -\n");
    for(int i=0; i<UA->CurrIndex; i++) {
        printf("\t%d\n", UA->ArrayOfUsers[i]->UID);
    }
}

void UI_PrintNumBlocks(BlockChain B) {
    printf("Number of blocks in blockchain: %d", B->NumBlocks);
}