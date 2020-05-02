#include<stdio.h>
int main(){
    int pn, bt[100], tat[100], wt[100], wtt = 0;
    float totalTat = 0, totalwt = 0;
    scanf("%d", &pn);
    int i;
    wt[0] = 0;
    for(i=0; i<pn; i++){
        printf("PN%d: ", i+1);
        scanf("%d", &bt[i]);
        wtt+= bt[i];
        wt[i+1] = wtt;
        tat[i]= wt[i]+bt[i];
    }
    printf("pn\tbt\twt\ttat\n");
    for(i=0; i<pn; i++){
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i],wt[i], tat[i]);
        totalTat += tat[i];
        totalwt += wt[i];
    }
    printf("Average WT = %g\n", totalwt/pn);
    printf("Average TAT = %g\n", totalTat/pn);
}
