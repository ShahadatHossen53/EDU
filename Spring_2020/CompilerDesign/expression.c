#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int states[] = {0, 0, 0, 0, 1, 0, 0};
int possition = 0;

bool isChar(char ch);
bool isOperator(char ch);

int main(){
    char str[30];
    gets(str);
    int len = strlen(str);
    str[len++] = ';';
    str[len++] = '\0';

    puts(str);
    int i;
    //printf("len = %d\n", strlen(str));
    for(i=0; str[i]!='\0'; i++){
        //printf("i = %d\t", i);
       // printf("poss = %d\t char = %c\t", possition, str[i]);
        if(isChar(str[i]) && possition == 0){
            possition = 1;
        }
        else if(isOperator(str[i]) && possition == 0){
            possition = 5;
        }
        else if(possition == 1 && isChar(str[i])){
            possition = 1;
        }
        else if(possition == 1 && isOperator(str[i])){
            possition = 2;
        }
        else if(possition == 2 && isChar(str[i])){
            possition = 3;
        }
        else if(possition == 2 && isOperator(str[i])){
            possition = 6;
        }
        else if(possition == 3 && isChar(str[i])){
            possition = 3;
        }
        else if(possition == 3 && isOperator(str[i])){
            possition = 2;
        }
        else if(possition == 3 && str[i]==';'){
            possition = 4;
        }
        else if(possition == 6 && str[i]==';'){
            possition = 4;
        }
        else if(possition == 5 && isOperator(str[i])){
            possition = 3;
        }
        else{
            possition = 0;
            break;
        }
        // printf("poss = %d\n", possition);
    }
    if(states[possition]){
        //printf("poss = %d\n", possition);
        printf("Valid Expression\n");
    }
    else{
       // printf("poss = %d\n", possition);
        printf("Invalid Expression\n");
    }
}
bool isChar(char ch){
    return isalpha(ch);
}
bool isOperator(char ch){
    char oper[] = {'+', '-', '*','/'};
    int i;
    for(i=0; i<strlen(oper); i++){
        if(ch==oper[i]){
            return true;
        }
    }
    return false;
}



