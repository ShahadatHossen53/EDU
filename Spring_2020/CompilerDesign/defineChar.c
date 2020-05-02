#include<stdio.h>
#include<ctype.h>
int main(){
    char str[100], letter[100]="", digit[100]="", special[100]="", oparetor[100]="";
    gets(str);
    int i, len = strlen(str), l = 0, d = 0, s = 0, o = 0;
    for(i=0; i<len; i++){
        if(isalpha(str[i])){
            letter[l++] = str[i];
        }
        else if(isdigit(str[i])){
            digit[d++]=str[i];
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '='  ){
            oparetor[o++] = str[i];
        }
        else{
            special[s++] = str[i];
        }
    }
    printf("Letters: %s\n", letter);
    printf("Digits: %s\n", digit);
    printf("Special Characters: %s\n", special);
    printf("Operators: %s\n", oparetor);
}
