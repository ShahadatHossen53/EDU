#include<stdio.h>
#include<string.h>

int prod_num;

char productions[10][20] = {
                                "E=TE'",
                                "E'=+TE'|e",
                                "T=FT'",
                                "T'=*FT'|e",
                                "F=(E)|id",
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

        first(non_term, temp_first, i);
    }
}
void first(char t_non_ter[], char t_frst[], int num){

    char non_ter[10], frst[10];

    strcpy(non_ter, t_non_ter);
    strcpy(frst, t_frst);

    int i, j, k, l;

    if(isupper(frst[0])){
        for(i=0; i<prod_num; i++){
            if(productions[i][0] == frst[0]){
                j=0;
                while(productions[i][j] != '='){
                    j++;
                }
                j++;
                frst[0] = productions[i][j];
                num = i;
            }
        }
    }

    for(k=0; k<strlen(productions[num]); k++){
        if(productions[num][k]=='|'){
            frst[1] = ',';
            l=2;
            while(k<strlen(productions[num])){
                k++;
                frst[l++] = productions[num][k];
            }
        }
    }

    printf("FIRST(%s)\t->\t{%s}\n", non_ter, frst);
}
