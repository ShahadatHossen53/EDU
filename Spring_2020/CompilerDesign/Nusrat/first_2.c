#include<stdio.h>
#include<string.h>
int prod_num;
char productions[10][20] = {
                                "E=TE'", ///X = E'
                                "E'=+TE'",
                                "T=FT'", /// Y = T'
                                "T'=*FT'",
                                "F=(E)",
                            };

int main(){
    prod_num = 5;
    int i, j;
    for(i=0; i<5;i++){
        char non_term[5] = "";
        char temp_first[5] = "";
        j=0;
        while(productions[i][j]!='='){
            j++;
        }
        j++;
        temp_first[0] = productions[i][j];
        non_term[0] = productions[i][0];
        if(productions[i][j+1]=='\''){
            temp_first[1] = productions[i][j+1];
        }
        if(productions[i][1]=='\''){
            non_term[1] = productions[i][1];
        }
        first(non_term, temp_first);
    }
}
void first(char non_ter[], char frst[]){
    int i, j, k;
    if(isupper(frst[0])){
        for(i=0; i<prod_num; i++){
            if(!isupper(frst[0])){
                break;
            }
            if(productions[i][0] == frst[0]){
                j=0;
                while(productions[i][j] != '='){
                    j++;
                }
                j++;
                frst[0] = productions[i][j];
            }
        }
    }
    printf("FIRST(%s)\t->\t%s\n", non_ter, frst);
}
