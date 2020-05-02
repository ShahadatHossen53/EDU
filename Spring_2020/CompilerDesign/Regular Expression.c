#include<stdio.h>
int states[] = {0, 0, 1};
int possition;


int main(){
    char str[100];
    while(gets(str)){

    int i, possition =0;
    for(i=0; i<strlen(str); i++){
        if(possition==0){
            if(str[i]=='a'){
                possition = 1;
            }
            else if(str[i]=='b'){
                possition = 2;
            }
        }
        else if(possition==1){
            if(str[i]=='a'){
                possition = 1;
            }
            else if(str[i]=='b'){
                possition = 2;
            }
        }
        else if(possition==2){
            possition=0;
            break;
        }
    }

    if(states[possition]){
        printf("accepted\n");
    }
    else{
         printf("Not accepted\n");
    }
    }
}
