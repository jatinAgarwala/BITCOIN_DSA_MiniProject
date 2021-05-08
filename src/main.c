#include "../include/transaction.h"
#include "../include/user.h"
#include "../include/block.h"
#include "../include/UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UHTsize 1000003
#define UAsize 1000003

int main()
{
    double InitialBalance;

    BlockChain B = InitBlockChain();    //Creating a blockchain
    UserHashTable UHT = InitUserHashTable(UHTsize); //Creating a UserHashTable
    UsersArray UA = InitUsersArray(UAsize); //Creating an Array where UserInfo is stored

    srand(time(0));
    printf("\t\t\tBITCOIN\t\t\n");
    printf("\t\t\t-------\t\t\n\n\n");

    printf("Choose the amount that every new user will have: ");    // Setting a default Balance amount that will be applicable for all users
    scanf("%lf", &InitialBalance);

    int choice = -1;

    while(choice != 0)
    {
        printf("\nThe following functions are supported:\n"); // Using numbers to perform a certian transaction corresponding to its value
        printf("0 Exit\n"); //Exits the program
        printf("1 Add user to the system\n");   // Adds a user to the system
        printf("2 Transact\n");  // Performs a transaction
        printf("3 Attack\n");   // Performs the attack function that may alter nonce values
        printf("4 Validate Block Chain\n"); // Validates the blockchain to check for attacks
        printf("5 Print the Information of the current Block\n");   //Info on the current block
        printf("6 Print the Information of a Block\n"); //Info about any particular block
        printf("7 Print the Information of a User\n");  //Info about a user in the system {Including Transaction history????}
        printf("8 Print UIDs and wallet balance of all Users\n");  //Prints the list of UIDs for all Users in the system
        printf("9 Print Number of Blocks\n\n"); //Prints the numbers of blocks comprising the blockchain
        printf("Choose which function you want to execute (0 - 9) : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
                printf("Thank you for using our Bitcoin software.\nHave a nice day!\n");    //Generic Polite Outro
                break;
            case 1:
                UI_AddUser(UA, UHT);    //Invokes the InitUser function to add a user
                break;
            case 2:
                UI_Transact(B, UA, UHT);    //Performs a transaction
                break;
            case 3:
                UI_Attack(B);   //Performs an attack
                break;
            case 4:
                UI_ValidateBlockChain(B);   //Validates Blockchain
                break;
            case 5:
                UI_PrintCurrentBlockInfo(B);    //Prints the information about the current block
                break;
            case 6:
                UI_PrintInfoBlock(B);   //Prints info of block
                break;
            case 7:
                UI_PrintUserInfo(UA, UHT);  //Prints User Information including the required credentials
                break;
            case 8:
                UI_PrintAll_UIDs(UA);   //Prints all User_IDs in the system
                break;
            case 9:
                UI_PrintNumBlocks(B);   //Prints the number of blocks
                break;
            default:
                printf("Sorry, you seem to have entered an incorrect input. Please try again!\n");  // Generic error message
                break;
        }
    }

    return 0;
}
