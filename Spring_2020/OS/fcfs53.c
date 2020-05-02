#include<stdio.h>
float avgTAT(int tat[], int pn);
float avgWT(int wt[], int pn);
int main(){
    int pn, i;
    printf("Enter total number of process: ");
    scanf("%d", &pn);
    int at[pn], bt[pn], ct[pn], tat[pn], wt[pn];
    for(i=0; i<pn; i++){
        printf("Process: %d\n", i+1);
        printf("AT: ");
        scanf("%d", &at[i]);
        printf("BT: ");
        scanf("%d", &bt[i]);
    }
    printf("\n\n\n");
    findCT(at, bt, ct,pn);
    findTAT(tat, at, ct, pn);
    findWT(wt, tat, bt, pn);

    float tatAvg = avgTAT(tat, pn);
    float wtAvg = avgWT(wt, pn);


    printf("PN\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i=0; i<pn; i++){
        printf("%d\t", i+1);
        printf("%d\t", at[i]);
        printf("%d\t", bt[i]);
        printf("%d\t", ct[i]);
        printf("%d\t", tat[i]);
        printf("%d\t", wt[i]);
        printf("\n");
    }

    printf("\n\nAverage of TAT = %g\n", tatAvg);
    printf("Average of WT = %g\n", wtAvg);
}

void findCT(int at[], int bt[],int ct[], int pn){
    int i, j;
    int min = 999999;
    int temp[pn];
    for(i=0; i<pn; i++){
        temp[i] = at[i];
    }
    int indx=0, preIndx = 0;
    for(j = 0; j<pn; j++){
        for(i=0; i<pn; i++){
            if(min>temp[i]){
                min = temp[i];
                indx = i;
            }
        }
        if((indx == preIndx)||(ct[preIndx]<=at[indx])){
            ct[indx] = bt[indx]+at[indx];
        }
        else{
            ct[indx] = ct[preIndx]+bt[indx];
        }
        preIndx = indx;
        min = 999999;
        temp[indx] = min;
    }
}
void findTAT(int tat[], int at[], int ct[], int pn){
    int i;
    for(i=0; i<pn; i++){
        tat[i] = ct[i]-at[i];
    }
}
void findWT(int wt[], int tat[], int bt[], int pn){
    int i;
    for(i=0; i<pn; i++){
        wt[i] = tat[i]-bt[i];
    }
}
float avgTAT(int tat[], int pn){
    int i, total=0;
    for(i=0; i<pn; i++){
        total+= tat[i];
    }
    return (float)total/(float)pn;
}
float avgWT(int wt[], int pn){
    int i, total=0;
    for(i=0; i<pn; i++){
        total+= wt[i];
    }
    return (float)total/(float)pn;
}
