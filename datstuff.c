
#include <stdio.h>

int main()
{
    int numOfassign = 0;                  
    float sumOfpossible =0;               //declaration of variables  
    float sumOfearned = 0;  
    float averagedgrade =0;
 
    printf("Enter the number of assignments: \n"); // propmts user for amount of grades and sets entered value equal to the variable
        scanf("%d", &numOfassign);  
        float earned[numOfassign];
        float possible[numOfassign];  //variables declared and assigned arrys with spots equal to entered number of grades
        
        for(int i=0; i<numOfassign; ++i){
            printf("Enter earned points %d:\n", (i+1));
            scanf("%f", &earned[i]);
            printf("enter possible points %d:\n", (i+1));      // loop propmting user for points earned and possible seting the equalto the respective variables
            scanf("%f", &possible[i]);
        }   
        for(int i=0; i<numOfassign; ++i ){
        sumOfearned += earned[i];           //lopp to sum the points earned and points possble
        sumOfpossible += possible[i];
        }  
        averagedgrade = ( sumOfearned/sumOfpossible)*100; // usses summed varibles and divides to give deccimal and *100 for percent
        
        printf("The average grade is %lf.\n", averagedgrade); // prints the ratio of sum earned to sum possible
    
        return 0; //error code
    }
