#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

const double InitialBalance = 1000;

char * Get_JoinDateTime()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

// returns time in Day, Month/date time in hh:mm:ss year

   return asctime(timeinfo);
}

User InitUser()
{
    User temp = (User)malloc(sizeof(struct user));
    temp->Balance = InitialBalance;
    temp->JoinDateTime = Get_JoinDateTime();
    return temp;
}

int main ()
{
    
}
