#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define max 100
vector < pair< int,int > > uv;
vector < pair< int,int > > temp;
vector < pair< int,int > > EndBr;

int Ar[max],Br[max],Cr[max],Tat[max],Wt[max];
int main(){
    printf("Enter Processor Number : ");
    int p,x,y; scanf("%d",&p);
    printf("Enter Arrive Time & Burst Time Number : \n");
    for(int i=0;i<p;i++){
        scanf("%d%d",&x,&y);
        uv.pb(mp(x,y));
    }
    sort(uv.begin(),uv.end());
    for(int i=0;i<uv.size();i++){
        Ar[i]=uv[i].first;
        Br[i]=uv[i].second;
    }
    int initial_sum=0,j,k,counter=0;
    int *lowAr = min_element(Ar,Ar+p);
    int highBr = accumulate(Br,Br+p,initial_sum);
    int n = (*lowAr+highBr);
    for(int i=*lowAr;i<n;i++){
        while(i==uv[counter].first){
            temp.pb(mp(uv[counter].second,counter));
            counter++;
        }
    sort(temp.begin(),temp.end());
    temp[0].first=temp[0].first-1;
    if(temp[0].first==0){
        EndBr.pb(mp(temp[0].second,i+1));
        temp[0].first=99999;
        sort(temp.begin(),temp.end());
        }
    }
    sort(EndBr.begin(),EndBr.end());
    for(int i=0;i<EndBr.size();i++)
        Cr[i]=EndBr[i].second;
    for(int i=0;i<p;i++){
        Tat[i]=Cr[i]-Ar[i];
        Wt[i]=Tat[i]-Br[i];
    }
    printf("\n\n\n\tArrive\tBurst\tCA\tTAT\tWait\n");
    for(int i=0;i<p;i++)
        printf("\n\t%d\t%d\t%d\t%d\t%d\n",Ar[i],Br[i],Cr[i],Tat[i],Wt[i]);
    printf("\n\n\n");
}
