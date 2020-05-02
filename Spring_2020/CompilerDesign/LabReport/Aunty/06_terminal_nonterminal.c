#include<stdio.h>
define(char str[], int i);
main(){
    int n,i,j;
    char str[100][25];
    scanf("%d",&n);
    for(j=0;j<=n;j++)
    {
        gets(str[j]);
    }
      for(i=0; i<j; i++){
        define(str[i], strlen(str[i]));
    }
}
define(char str[], int j){
int i;
for(i=0;i<j;i++)
{
    if(isalpha(str[i]) && isupper(str[i]))
        printf("%c is non terminal symbol\n",str[i]);
    else if(isalpha(str[i]) && islower(str[i]))
        printf("%c is terminal symbol\n",str[i]);
    else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'|| str[i]=='('|| str[i]==')')
        printf("%c is terminal symbol\n",str[i]);
    else
        printf("grammar symbol\n");
}
return 0;
}
