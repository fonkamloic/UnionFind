#include <stdio.h>
#include <time.h>
#include "unionFind.h"
//prototype
int menu();


int main() {
 list *headList = NULL;
 int value = 0, value2 = 0, value1 = 0;
    while(1)
    {


        switch(menu()) {

            case 1:
                printf("Enter an int (enter -1 when done): "); //prompt user for and integer
                scanf("%d", &value1);         //read input
                while(value1 != -1){
                    headList = insertNode(headList, value1);
                    printf("Enter an int (enter -1 when done):  "); //prompt user for and integer
                    scanf("%d", &value1);
                }
                break;

            case 2:

                printf("The list so far is: \n");
                printList(headList);
                printf("\nEnter the first integer you want to perform join: ");
                scanf("%d", &value2);
                printf("\nEnter the second integer you want to perform join: ");
                scanf("%d", &value);
                join(headList, value, value2);
                break;


            case 3:
                printf("\nEnter the first integer you want to perform sameclass: ");
                scanf("%d", &value2);
                printf("\nEnter the second integer you want to perform sameclase: ");
                scanf("%d", &value);

               list *result = sameClass(headList, value, value2);
               if(result == NULL) {
                   printf("Not in the same class :(\n");
                   break;
               }
               printf("There are in the same class :)\n");
                break;
            case 4:
                showSets(headList);

                break;

            case 5:
                    printList(headList);
                break;
            case 6:

                    printf("Enter amount of test data: ");
                    scanf("%d", &value);
                    srand(0);
                    for(int i = 0 ; i < value ; i++){
                        value1 = rand() % value;
                        headList = insertNode(headList, value1);
                    }

                    // partition half of the elements
                    for(int i = 0 ; i < value  ; i++ ){
                        value1 = rand() % value;
                        value2 = rand() % value;
                        join(headList, value1, value2);
                    }

                    //print partitions
                    showSets(headList);
                    break;
            case 7:
                return 0;
            default:
                printf("invalid option\n");


        }

    }

    return 0;
}



int menu()

{
    int ch;
    printf("\n 1. Create a Node Item ");
    printf("\n\n 2. Join Node items");
    printf("\n\n 3. Establish Same Class");
    printf("\n\n 4. Print Sets");
    printf("\n\n 5. Print nodes with rank");
    printf("\n\n 6. Run sample data");
    printf("\n\n 7. Exit");

    puts(" ");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);

    return ch;
}