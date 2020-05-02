#include<stdio.h>
int main(){
    int pn, bt[100], wt[100], tat[100], i, j;//pn = process number, bt = burst time, wt = waiting time, tat = turn around time
    float totalWt = 0, totalTat = 0;
    scanf("%d", &pn);//take the input how many process.
    for(i=0; i<pn; i++){
        scanf("%d", &bt[i]); //input burst time one by one.
    }

    //sorting the burst time using bubble sort.
    for(i=0; i<pn-1; i++){
        for(j=0; j<pn-i-1; j++){
            if(bt[j]>bt[j+1]){
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    wt[0] = 0; //1st process has no waiting time.So waiting time is zero.

    for(i=1; i<pn; i++){
        wt[i] = wt[i-1]+bt[i-1];//calculate the waiting time of other process.
    }

    for(i=0; i<pn; i++){
        tat[i] = bt[i]+wt[i];//calculate the turn around time of all process.
    }

    for(i=0; i<pn; i++){
        totalTat = totalTat+tat[i];//calculate the total turn turn around time.
        totalWt = totalWt+wt[i];//calculate the total waiting time.
    }

    printf("\n\n");//printing 2 new lines.
    printf("PN\tBT\tWT\tTAT\n\n");// '\t' means 4 white space or 1 tab.This line print "PN    BT    WT    TAT".


    //printing all elements
    for(i=0; i<pn; i++){
        printf("%d\t", i+1);
        printf("%d\t", bt[i]);
        printf("%d\t", wt[i]);
        printf("%d\n", tat[i]);
    }
    printf("\n\n");//printing 2 new lines.


    printf("Average of WT = %f\n", totalWt/pn);
    printf("Average of TAT = %f\n", totalTat/pn);
}


