#include<stdio.h>
int main(){
    char ope[5];
    while(gets(ope)){
        define(ope);
    }


}
void define(char s[]){
    if(strcmp(s, "++")==0 || strcmp(s, "--")==0){
        printf("Unary Operator\n");
    }
    else if(strcmp(s, "+")==0 || strcmp(s, "-")==0 || strcmp(s, "*")==0 ||strcmp(s, "/")==0 || strcmp(s, "%")==0){
        printf("Arithmetic Operator\n");
    }
    else if(strcmp(s, "<")==0 ||strcmp(s, "<=")==0 ||strcmp(s, ">")==0 ||strcmp(s, ">=")==0 ||strcmp(s, "==")==0 ||strcmp(s, "!=")==0 ){
        printf("Relational Operator\n");
    }
    else if(strcmp(s, "&&")==0 ||strcmp(s, "||")==0 ||strcmp(s, "!")==0 ){
        printf("Logical Operator\n");
    }
    else if(strcmp(s, "&")==0 ||strcmp(s, "|")==0 ||strcmp(s, "<<")==0 ||strcmp(s, ">>")==0 ||strcmp(s, "~")==0 ||strcmp(s, "^")==0 ){
        printf("Bitwise Operator\n");
    }
    else if(strcmp(s, "=")==0 ||strcmp(s, "+=")==0 ||strcmp(s, "-=")==0 ||strcmp(s, "*=")==0 ||strcmp(s, "/=")==0 ||strcmp(s, "%=")==0 ){
        printf("Assignment Operator\n");
    }
}
