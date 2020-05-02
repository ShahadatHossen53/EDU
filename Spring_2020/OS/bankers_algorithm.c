#include<stdio.h>

#define mx 100

int A, B, C, process_num, all_executed = 0, counter=0;
int available[3];
int total_allocation[3] = {0};
int executed[mx] = {0};
int allocation[mx][3];
int max_need[mx][3];
int Remaing_need[mx][3];
int process_executed[mx];

void get_abc_value(){
    printf("A = ");
    scanf("%d", &A);
    printf("B = ");
    scanf("%d", &B);
    printf("C = ");
    scanf("%d", &C);
}

void get_remainning_need(){
    int i;
    for(i=1;i<=process_num; i++){
        Remaing_need[i][0] = max_need[i][0]-allocation[i][0];
        Remaing_need[i][1] = max_need[i][1]-allocation[i][1];
        Remaing_need[i][2] = max_need[i][2]-allocation[i][2];
    }
}

void get_total_allocation(){

    int i;
    for(i=1; i<=process_num; i++){
        total_allocation[0]+=allocation[i][0];
        total_allocation[1]+=allocation[i][1];
        total_allocation[2]+=allocation[i][2];
    }
}

void get_available(){
    available[0]=A - total_allocation[0];
    available[1]=B - total_allocation[1];
    available[2]=C - total_allocation[2];
}

void calculate_availabel(int pn){
    available[0]+=allocation[pn][0];
    available[1]+=allocation[pn][1];
    available[2]+=allocation[pn][2];
}

void print_vlaue(){
    int i;

    printf("\n\nProcess\t");
    printf("Allocation\t");
    printf("Max Need\t");
    printf("Remaining Need\n\n");
    for(i=1; i<=process_num; i++){
        printf("P%d:\t", i);
        printf("%d %d %d\t\t", allocation[i][0],allocation[i][1],allocation[i][2]);
        printf("%d %d %d\t\t", max_need[i][0],max_need[i][1],max_need[i][2]);
        printf("%d %d %d\n", Remaing_need[i][0],Remaing_need[i][1],Remaing_need[i][2]);
    }
}
void print_available(){
    printf("A = %d ", available[0]);
    printf("B = %d ", available[1]);
    printf("C = %d ", available[2]);
    printf("\n");
}

void print_remaining_need(int pn){
    printf("A = %d ", Remaing_need[pn][0]);
    printf("B = %d ", Remaing_need[pn][1]);
    printf("C = %d ", Remaing_need[pn][2]);
    printf("\n");
}

int main(){
    get_abc_value();
    printf("Enter process number: ");
    scanf("%d", &process_num);
    int i;
    printf("Enter Allocation values of:\n");
    for(i=1; i<=process_num; i++){
        printf("P%d: ", i);
        scanf("%d%d%d", &allocation[i][0],&allocation[i][1],&allocation[i][2]);
    }
    printf("Enter Max Need values of:\n");
    for(i=1; i<=process_num; i++){
        printf("P%d: ", i);
        scanf("%d%d%d", &max_need[i][0],&max_need[i][1],&max_need[i][2]);
    }

    get_remainning_need();
    get_total_allocation();
    get_available();

    print_vlaue();
    printf("\n\n");
    while(counter<process_num){
        for(i=1; i<=process_num; i++){
            if(executed[i]==0){
                printf("Available Resource: ");
                print_available();
                printf("Remaining   Need  : ");
                print_remaining_need(i);
            }
            if(executed[i] == 0 && available[0]>=Remaing_need[i][0] && available[1]>=Remaing_need[i][1] && available[2]>=Remaing_need[i][2]){
                executed[i] = 1;
                counter++;
                calculate_availabel(i);
                printf("P%d is executed\n\n", i);

            }
            else if(executed[i]==0){
                printf("P%d is pending\n\n", i);
            }
            if(counter==process_num){
                break;
            }
        }
    }
    return 0;
}
