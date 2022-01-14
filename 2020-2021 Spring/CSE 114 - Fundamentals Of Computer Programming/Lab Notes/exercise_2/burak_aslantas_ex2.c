#include <stdio.h>

int main(){
    int number;
    char color;

    printf("Enter an integer:\n");
    scanf(" %d", &number);

    if (number > 30){
        printf("out of range");
        return 0;
    }

    printf("Enter a color (Options: 'R', 'G', 'B'):\n");
    scanf(" %c", &color);

    if ((number > 20 && number <= 30) && (color == 'B')){
        printf("correct color");
    }
    else if ((number > 10 && number <= 20) && (color == 'G')){
        printf("correct color");
    }
    else if ((number >= 0 && number <= 10) && (color == 'R')){
        printf("correct color");
    }
    else{
        printf("wrong color");
    }

    return 0;
}