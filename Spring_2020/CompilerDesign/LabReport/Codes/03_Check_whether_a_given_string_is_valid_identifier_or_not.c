#include<stdio.h>
#include <stdbool.h>
#include<ctype.h>
#include <stdlib.h>
int valid = 0;
int start = 0;
bool isSpecial(char c);
int main(){
    char str[100];
    while(gets(str)!=EOF){
        int len = strlen(str), i;
        while(str[start] == ' '){
            start++;
        }
        if(isalpha(str[start]) || str[start]=='_'){
            isValid(str, len);
            if(valid==0){
                printf("valid identifier\n");
            }
            else{
                printf("not valid identifier\n");
            }
        }
        else{
            printf("Not valid identifier\n");
        }
    }
}
void isValid(char str[], int len){
    int i;
    for(i=start+1; i<len; i++){
        if(isSpecial(str[i])){
            valid = 1;
        }
    }
}
bool isSpecial(char c){
    char s[] = "!@#$%^&*()-=+/.`~ {}[]\|?;\",";
    int i;
    for(i=0; i<strlen(s); i++){
        if(s[i] == c){
            return true;
        }
    }
    return false;
}
