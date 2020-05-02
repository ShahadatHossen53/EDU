#include<stdio.h>

#define mx 100

int process_num, counter = 0, timer = 0, start_time;
float average_waiting_time, average_turn_around_time, system_throughput;
int executed[mx] = {0};
int arival_time[mx];
int temp_arival_time[mx];
int burst_time[mx];
int waiting_time[mx];
int completion_time[mx];
int turnt_around_time[mx];
float penalty_ratio[mx];

int gc_process[mx];
int gc_completion_time[mx];

void print_values(){
    int i;
    printf("\n\nPN\t");
    printf("A.T\t");
    printf("B.T\t");
    printf("W.T\t");
    printf("C.T\t");
    printf("T.A.T\t");
    printf("P.R\n\n");

    for(i=1; i<=process_num; i++){
        printf("%d\t", i);
        printf("%d\t", arival_time[i]);
        printf("%d\t", burst_time[i]);
        printf("%d\t", waiting_time[i]);
        printf("%d\t", completion_time[i]);
        printf("%d\t", turnt_around_time[i]);
        printf("%0.2f\n", penalty_ratio[i]);
    }

    printf("Average waiting time = %0.2f\n", average_waiting_time);
    printf("Average turn around time = %0.2f\n", average_turn_around_time);
    printf("system throughput = %0.2f seconds\n", system_throughput);

}

void print_gc(){
    int i;
    printf("%d->", start_time);
    for(i=1;i<=process_num; i++){
        printf("P%d->%d->", gc_process[i], gc_completion_time[i]);
    }
    printf("\n\n");
}

void avg_wt(){
    int i;
    float sum=0;
    for(i=1; i<=process_num; i++){
        sum+=waiting_time[i];
    }
    average_waiting_time = sum/process_num;
}
void avg_tat(){
    int i;
    float sum=0;
    for(i=1; i<=process_num; i++){
        sum+=turnt_around_time[i];
    }
    average_turn_around_time = sum/process_num;
}

void sys_thro(){
    int i;
    float sum=0;
    for(i=1; i<=process_num; i++){
        sum+=burst_time[i];
    }
    system_throughput = sum/process_num;
}

int main(){
    int i, smallest=1, pre_indx, gc=1;
    printf("Enter process number: ");
    scanf("%d", &process_num);
    for(i=1; i<=process_num; i++){
        printf("P%d A.T:", i);
        scanf("%d", &arival_time[i]);
        temp_arival_time[i] = arival_time[i];
        printf("P%d B.T:", i);
        scanf("%d", &burst_time[i]);

        if(arival_time[smallest]>arival_time[i]){
            smallest=i;
        }

    }
    timer = arival_time[smallest];

    start_time = arival_time[smallest];
    waiting_time[smallest] = 0;
    completion_time[smallest] = burst_time[smallest]+start_time;
    turnt_around_time[smallest] = completion_time[smallest]-arival_time[smallest];
    penalty_ratio[smallest] = (float)turnt_around_time[smallest]/(float)burst_time[smallest];
    executed[smallest] = 1;
    timer+= burst_time[smallest];
    temp_arival_time[smallest]=110;
    gc_completion_time[gc] = completion_time[smallest]+start_time;
    gc_process[gc++] = smallest;
    pre_indx = smallest;
    counter++;

    while(counter<process_num){
        int xyz = 110;
        for(i=1; i<=process_num; i++){
            if(executed[i]==0){
                if(temp_arival_time[i]<=timer){
                    if(xyz>burst_time[i]){
                        xyz=burst_time[i];
                        smallest = i;
                    }
                }
            }
        }
        waiting_time[smallest]=completion_time[pre_indx]-arival_time[smallest];
        completion_time[smallest] = completion_time[pre_indx]+burst_time[smallest];
        turnt_around_time[smallest] = completion_time[smallest]-arival_time[smallest];
        penalty_ratio[smallest] = (float)turnt_around_time[smallest]/(float)burst_time[smallest];
        temp_arival_time[smallest]=110;
        timer+= burst_time[smallest];
        counter++;
        pre_indx = smallest;

        gc_completion_time[gc] = completion_time[smallest]+start_time;
        gc_process[gc++] = smallest;
    }


    avg_wt();
    avg_tat();
    sys_thro();
    print_values();
    printf("\n\n");
    print_gc();
}
