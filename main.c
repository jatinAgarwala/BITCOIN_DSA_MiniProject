#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "transaction.h"
#include "user.h"

double InitialBalance;

int main()
{
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
                
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            default:
                printf("Sorry, you seem to have entered an incorrect input. Please try again!\n");
                break;
        }
    }
    



    return 0;
}
