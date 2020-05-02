#include<stdio.h>
#include<stdbool.h>
#include<string.h>
char str[100], temp[100][25];
int indx = 0;


bool isKeyword(char str[]);
bool isIdentifire(char str[]);
bool isSpecial(char c);



int main(){
    gets(str);
    int i, j = 0, k = 0, size=strlen(str);
    for(i=0; i<size; i++){
        if(str[i]==' '){
            temp[j][k++]='\0';
            j++;
            k =0;
        }
        else{
            temp[j][k++] = str[i];
        }
    }
    temp[j][k++]='\0';
    define();
    /*for(i=0; i<=j; i++){
        define(temp[i], strlen(temp[i]));
    }*/
}

void define(){
    if(isKeyword(temp[0])){
        if(isIdentifire(temp[1])){
            printf("Valid expression\n");
        }
        else{
            printf("Not valid expression\n");
        }
    }
    else{
        if(isIdentifire(temp[0])){
            printf("Valid expression\n");
        }
        else{
            printf("Not valid expression\n");
        }
    }
}
bool isKeyword(char str[]){
    char keywords[25][20] = {"int", "double", "float", "long", "char", "unsigned", "bool"};
    int i;
    for(i=0; i<7; i++){
        if(strcmp(str, "int")==0){
            return true;
        }
    }
    return false;
}
bool isIdentifire(char str[]){
    int i;
    if(isalpha(str[0]) || str[0]=='_' || !isdigit(str[0])){
        for(i=1; i<strlen(str); i++){
            if(isSpecial(str[i])){
                return false;
            }
        }
        return true;
    }
    return true;
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



