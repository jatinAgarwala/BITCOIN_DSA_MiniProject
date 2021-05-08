#include "libs.h"

#define UHTsize 1000
#define UAsize 1000

double InitialBalance;

int main()
{
    BlockChain B = InitBlockChain();
    UserHashTable UHT = InitUserHashTable(UHTsize);
    UsersArray UA = InitUsersArray(UAsize);

    srand(time(0));
    printf("\t\t\tBITCOIN\t\t\n");
    printf("\t\t\t-------\t\t\n\n\n");

    printf("Choose the amount that every new user will have: ");
    scanf("%Ld", &InitialBalance);

    int choice = -1;

    while(choice != 0)
    {
        printf("The following functions are supported:\n");
        printf("0 Exit\n");
        printf("1 Add user to the system\n");
        printf("2 Transact\n");
        printf("3 Attack\n");
        printf("4 Validate Block Chain\n");
        printf("5 Print the Information of the current Block\n");
        printf("6 Print the Information of a Block\n");
        printf("7 Print the Information of a User\n");
        printf("8 Print UIDs of all Users\n");
        printf("9 Print Number of Blocks\n\n");
        printf("Choose which function you want to execute (0 - 9) : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
                printf("Thank you for using our Bitcoin software.\nHave a nice day!\n");
                break;
            case 1:
                UI_AddUser(UA, UHT);
                break;
            case 2:
                UI_Transact(B, UA, UHT);
                break;
            case 3:
                UI_Attack(B);
                break;
            case 4:
                UI_ValidateBlockChain(B);
                break;
            case 5:
                UI_PrintCurrentBlockInfo(B);
                break;
            case 6:
                UI_PrintInfoBlock(B);
                break;
            case 7:
                UI_PrintUserInfo(UA, UHT);
                break;
            case 8:
                UI_PrintAll_UIDs(UA);
                break;
            case 9:
                UI_PrintNumBlocks(B);
                break;
            default:
                printf("Sorry, you seem to have entered an incorrect input. Please try again!\n");
                break;
        }
    }

    return 0;
}
