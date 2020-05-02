#include<stdio.h>
#include<stdbool.h>

bool isKeyword(char keyd[]){
    char key[10];
    strcpy(key, keyd);
    char myKywrd[10][10]={"int", "double", "float", "char", "bool"};
    int i;
    for(i=0; i<strlen(myKywrd); i++){
        if(strcmp(myKywrd[i], key)==0){
            return true;
        }
    }
    return false;
}

bool isOperator(char ch){
    char myOp[]="+-*/=";
    int i;
    for(i=0; i<strlen(myOp); i++){
        if(myOp[i]==ch){
            return true;
        }
    }
    return false;
}
bool isSymbol(char ch){
    char mySym[]=",;:(){}[]";
    int i;
    for(i=0; i<strlen(mySym); i++){
        if(mySym[i]==ch){
            return true;
        }
    }
    return false;
}


int main(){
    char str[] = "int a, b,c;  c = a + b ;";
    int i;
    for(i=0; i<strlen(str); i++){
        if(str[i]==' '){
            continue;
        }
        else if(isalpha(str[i])){
            char temp[20] = "";
            int t=0;
            while(isalpha(str[i])){
                temp[t]=str[i];
                t++;
                i++;
            }
            i--;
            if(isKeyword(temp)){
                printf("'%s' is a keyword\n", temp);
            }
            else{
                printf("'%s' is an identifier\n", temp);
            }

        }
        else if(isOperator(str[i])){
            printf("'%c' is an operator\n", str[i]);
        }
        else if(isSymbol(str[i])){
            printf("'%c' is a symbol\n", str[i]);
        }
        else{
            continue;
        }
    }
}
