#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


char * Get_JoinDateTime ()
{
      time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
   

// returns time in Day, Month/date time in hh:mm:ss year

   return asctime(timeinfo);

}



int main ()
{
    
}
