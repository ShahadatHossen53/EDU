#include<stdio.h>
int printCom = 0;
int main(){
    char str[100];
    char nonComm[100];
    int k=0, l;
    gets(str);
    int i, len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i]=='/')
            {
            if(str[i+1]=='/'){
                singleLineComm(str, len, i+2);
                break;
            }
            else if(str[i+1] == '*')
            {
                l = comm(str, len, i+2);
                i+=l;
                if(l==0){
                    nonComm[k++] = str[i];
                }
            }
            else
            {
                nonComm[k++] = str[i];
            }
        }
        else
        {
            nonComm[k++] = str[i];
        }
    }
    if(k>0)
        {
        printf("NON comment:\n\t");
        for(i=0; i<k; i++)
        {
            printf("%c", nonComm[i]);
        }
    }

}
void singleLineComm(char str[], int len, int start)
{
    printf("Single line comment:\t");
    int i;
    for(i=start; i<len; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

}
int comm(char str[], int len, int start){
    char comment[100] = "";
    int i, j=0;
    for(i=start; i<len; i++){
        if(str[i]=='*' && str[i+1]=='/'){/*12121*/
           // isComm = 1;
            printCom++;
            break;
        }
        else{
            comment[j++] = str[i];
        }
    }
    if(printCom==1){
        printf("Multi line Comment(s):\n");
    }
    if(len>i){
        printf("\t");
        puts(comment);
        return j+3;
    }
    return 0;
}
