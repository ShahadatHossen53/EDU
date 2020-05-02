#include<stdio.h>
#include<string.h>
int prod_num;
char productions[10][20] = {
                                "E=TX", /// X = E'
                                "X=+TX", 
                                "T=FY", /// Y = T'
                                "Y=*FY",
                                "F=(E)",
                            };

int main(){
    prod_num = 5;
    int i, j, k, l, m;
    for(i=0; i<5;i++){
        j=0;
        while(productions[i][j]!='='){
            j++;
        }
        j++;
        k = 0;
        first(productions[i][0], productions[i][j]);
    }
}

void first(char non_ter, char frst){
    int i, j, k;
    if(isupper(frst)){
        for(i=0; i<prod_num; i++){
            if(!isupper(frst)){
                break;
            }
            if(productions[i][0] == frst){
                j=0;
                while(productions[i][j] != '='){
                    j++;
                }
                j++;
                frst = productions[i][j];
            }
        }
    }
    printf("FIRST(%c) -> %c\n", non_ter, frst);
}



