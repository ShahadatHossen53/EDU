#include<stdio.h>
int main(){
    char str[] = "exp = term + fac * 2";
    char temp_str[10][10];
    int possition[10];
    int i, p=0, x=0, y=0;// counter=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]==' '){
            temp_str[x][y]='\0';
            x++;
            y=0;

        }
        else if(str[i]=='=' || str[i]=='+' || str[i]=='*'){
            temp_str[x][y]=str[i];
            possition[p]=i+1;
            p++;
            y++;
        }
        else{
            temp_str[x][y]=str[i];
            y++;
        }
        //counter++;
    }
    temp_str[x][y]='\0';
    for(i=0; i<p; i++){
        printf("%d\n", possition[i]);
    }
    for(i=1; i<=x; i=i+2){
            printf("%s %s %s\n", temp_str[i-1], temp_str[i+1], temp_str[i]);
    }
}
