#include<stdio.h>
#include<stdbool.h>
int states[]={0,0,0,0,1,0,1,0,1,1,0};
int tracker;
int possition = 1;
char str[100];
bool isOperator(char ch){
    int i;
    char myOp[]="+-*/%";
    for(i=0; i<strlen(myOp); i++){
        if(ch==myOp[i]){
            return true;
        }
    }
    return false;
}
bool isNumber(int pn){
    int i, counter=0;
    if(isdigit(str[pn])){
        for(i=pn+1; i<strlen(str);i++){
            if(isalpha(str[i])){
                return false;
            }
            if(isOperator(str[i])){
                break;
            }
            if(isdigit(str[i]) || str[i]=='.'){
                counter++;
            }
        }
        tracker+=counter;
        return true;
    }
    else{
        return false;
    }
}
bool isValidID(int pn){
    int i, counter = 0;
    if((str[pn]=='_' && isalpha(str[pn+1]))|| isalpha(str[pn])){
        for(i=pn+1; i<strlen(str); i++){
            if(isalpha(str[i]) || isdigit(str[i]) || str[i]=='_'){
                counter++;
            }
            else{
                break;
            }
        }
        while(str[i++]==' '){
            counter++;
        }
        tracker+=counter;
        return true;
    }
    else{
        return false;
    }
}
int main(){
    while(gets(str)){
        for(tracker=0; tracker<strlen(str); tracker++){
            while(str[tracker]==' '){
                tracker++;
            }
            if(possition==1){
                if(isValidID(tracker)){
                    possition = 2;
                }
                else if((str[tracker]=='+' && str[tracker+1]=='+') || (str[tracker]=='-' && str[tracker+1]=='-')){
                    possition = 10;
                    tracker++;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==2){
                if(str[tracker]=='='){

                    possition=3;
                }
                else if((str[tracker]=='+' && str[tracker+1]=='+')||(str[tracker]=='-' && str[tracker+1]=='-')){
                    tracker++;
                    possition = 9;
                }
                else if(isOperator(str[tracker])){
                    possition = 2;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==3){
                if((str[tracker]=='+' && str[tracker+1]=='+')||(str[tracker]=='-' && str[tracker+1]=='-')){
                    tracker++;
                    possition = 10;
                }
                else if(isValidID(tracker)){
                    possition=4;
                }
                else if(isNumber(tracker)){
                    possition = 9;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==4){
                if(str[tracker]=='+'){
                    possition=5;
                }
                else if(str[tracker]=='-'){
                    possition=7;
                }
                else if(isOperator(str[tracker])){
                    possition=3;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==5){
                if(str[tracker]=='+'){
                    possition = 6;
                }
                else if(isNumber(tracker)){
                    possition = 9;
                }
                else if(isValidID(tracker)){
                    possition=4;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==6){
                if(isOperator(str[tracker])){
                    possition=3;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==7){
                if(str[tracker]=='-'){
                    possition = 8;
                }
                else if(isNumber(tracker)){
                    possition = 9;
                }
                else if(isValidID(tracker)){
                    possition=4;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==8){
                if(isOperator(str[tracker])){
                    possition=3;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==9){
                if(isOperator(str[tracker])){
                    possition=3;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else if(possition==10){
                if(isValidID(tracker)){
                    possition=9;
                }
                else{
                    possition=0;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(states[possition]){
            printf("Valid Expression\n");
        }
        else{
            printf("invalid Expression\n");
        }
        possition = 1;
    }
}
