#include<stdio.h>
int main(){
    char str[100];
    int i, com=0;
    printf("Enter a line: ");
    gets(str);
    if(str[0]=='/'){
        if(str[1]=='/'){//sdfkjldk/*ljsadfkjl
            printf("This is a comment\n");
        }
        else if(str[1]=='*'){
            for(i=2; i<strlen(str); i++){
                if(str[i]=='*' && str[i+1]=='/'){
                    printf("This is a comment\n");
                    com=1;
                    break;
                }
            }
            if(!com)
                printf("This is not a comment\n");
        }
        else{
            printf("This is not a comment\n");
        }
    }
    else{
        printf("This is not a comment\n");
    }
    return 0;

}
