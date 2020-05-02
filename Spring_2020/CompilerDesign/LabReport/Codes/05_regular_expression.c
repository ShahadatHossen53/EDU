#include<stdio.h>
int states_a_star[] = {0, 1, 0}, states_a_star_b[] = {0, 0, 1};
int position = 0;
char str[100];
int expression;
int main()
{
    come:
    printf("Enter 1 for expression 'a*'\nEnter 2 for expression 'a*b'\nEnter -1 for exit\n\t: ");
    scanf("%d", &expression);
    if(expression==-1){
        return 0;
    }
    if(expression==1)
    {
        printf("Enter The String: ");
        scanf("%s",str);
        {
            for(int i=0; i<strlen(str); i++){
                if(position==0){
                    if(str[i]=='a'){
                        position = 1;
                    }
                    else{
                        position = 2;
                        break;
                    }
                }
                else if(position==1){
                    if(str[i]=='a'){
                        position = 1;
                    }
                    else if(str[i]=='b'){
                        position = 2;
                        break;
                    }
                }
            }
            if(states_a_star[position]){
                printf("Accepted\n\n");
                 }
                else{
                    printf("Not Accepted\n\n");
                }
        }
    }
    else{
        printf("Enter The String: ");
        scanf("%s",str);
        {
            for(int i=0; i<strlen(str); i++){
                if(position==0){
                    if(str[i]=='a'){
                        position = 1;
                    }
                    else if(str[i]=='b'){
                        position = 2;
                    }
                }
                else if(position==1){
                    if(str[i]=='a'){
                        position = 1;
                    }
                    else if(str[i]=='b'){
                        position = 2;
                    }
                }
                else if(position==2){
                    position=0;
                    break;
                }
            }

            if(states_a_star_b[position]){
                printf("Accepted\n\n");
            }
            else{
                printf("Not Accepted\n\n");
            }
        }
    }
    goto come;
}
