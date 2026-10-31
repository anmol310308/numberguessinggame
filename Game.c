#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{int r,n=0; 
    srand(time(NULL));
    r=(rand()%100)+1;
    
   
    while(n!=r)
  {   printf("guess the number(between 1 to 100)\n");
    scanf("%d",&n);
    if(n>100||n<1)
{printf("invalid input\n");}
    
   else if(n>r)
    {printf("number is greater than actual number try again\n");
       }
 else if(n<r)
  {printf("number is less than actual number try again\n");}
   else{printf("correct guess");}
    
}
    return 0;
}
