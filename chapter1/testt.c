#include <stdio.h>
int main(){

    int userInput;
    int arrayStuff[92];
    int i, j;

    for(i = 0; i < 92; ++i){
        arrayStuff[i] = 0;
    }

    while((userInput = getchar()) != '\n'){
        if(userInput >= 30 && userInput <= 122){
            if(userInput != '\n'){
                ++arrayStuff[(userInput-30)];
            }

            if(userInput == '\n'){
                break;
            }
        }
    }

    printf("Case\t|\tOccurances\n");

    for(i = 0; i < 92; ++i){
        printf("%c\t|\t%d\n", (i+30), arrayStuff[i]);
    }
}