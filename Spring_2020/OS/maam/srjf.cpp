#include<stdio.h>
#include<stdlib.h>
int processes[100][4], NP, scheduler[1000], arrivedProcesses[100], NAP=0;
unsigned int time = 0;


void getSystem()
{
	printf("\nNumber of processes: ");
	scanf("%d", &NP);



	for(int i=0; i<NP; i++ )
	{
		printf("\n Arrival Time of p%d: ", i+1);
		scanf("%d", &processes[i][0]);
		printf("\n Burst time for p%d: ", i+1);
		scanf("%d", &processes[i][1]);
		processes[i][2] = processes[i][1];
		printf("\n-----------");
	}
}
/*void x()
{
	NP = 5;
	processes[0][0] =3; processes[0][1] = 1; processes[0][2] = 1;
	processes[1][0] =1; processes[1][1] = 4; processes[1][2] = 4;
	processes[2][0] =5; processes[2][1] = 2; processes[2][2] = 2;

	processes[3][0] =0; processes[3][1] = 6; processes[3][2] = 6;
	processes[4][0] =2; processes[4][1] = 3; processes[4][2] = 3;



}*/
void printSystem()
{
	printf("\n\t\tOur System is :");
	printf("\nPi:  AT  BT RT");
	for(int i=0; i<NP; i++)
	{
		printf("\nP%d:  %d  %d  %d", i+1, processes[i][0], processes[i][1], processes[i][2]);
	}

}
unsigned int remainTimes()
{
	for(int i=0; i< NP; i++)
	{
		if(processes[i][2] > 0)
		{
			return 1;
		}
	}
	return 0;
}
void addArivedProcesses()
{
	for(int i=0; i<NP; i++)
	{
		if(processes[i][0] == time)
		{
			arrivedProcesses[NAP] = i;
			NAP++;
		}
	}
}
int getSRT()
{
	if(NAP == 0)
	{
		return -1;
	}
	unsigned int smalestRTP, smalestRTPIndex;
	smalestRTPIndex = arrivedProcesses[0];
	smalestRTP = processes[arrivedProcesses[0]][2];
	for( int i=0; i<NAP ; i++)
	{
		if(processes[arrivedProcesses[i]][2] < smalestRTP)
		{
			smalestRTP = processes[arrivedProcesses[i]][2];
			smalestRTPIndex = arrivedProcesses[i];
		}
	}
	return smalestRTPIndex;
}
void printArrivedProcesses()
{
	printf("\n\nArrived Processes(%d)  : ",NAP);
	for(int i=0; i<NAP; i++)
	{
		printf(" [%d]", arrivedProcesses[i]+1);
	}
}
void removeFromArrivedProcesses(int toRun)
{
	printArrivedProcesses();
	int temp[100];
	int x = 0;
	for(int i=0; i< NAP; i++)
	{
		if(arrivedProcesses[i] != toRun)
		{
			temp[x] = arrivedProcesses[i];
			x++;

		}
	}
	NAP = NAP - 1;
	for(int i=0; i<NAP ; i++)
	{
		arrivedProcesses[i] = temp[i];
	}
	printArrivedProcesses();

}
void schedule()
{
	int x;
	int toRun;
	while(remainTimes())
	{
		addArivedProcesses();
		toRun = getSRT();
		scheduler[time] = toRun;
		processes[toRun][2]--;
		if(processes[toRun][2]==0)
		{
			removeFromArrivedProcesses(toRun);
		}
		printf("\nRun = %d, Time = %d",toRun+1 ,time);
		printSystem();
		time++;
	}
}
void printScheduler()
{
	printf("\n\nScheduler: \n");
	for(int t=0;t<time; t++)
	{
		if(scheduler[t] == -1)
		{
			printf("\n[%d, %d] . IDLE", t, t+1);
		}
		else
		{
			printf("\n[%d, %d] . %d", t, t+1, scheduler[t]+1);
		}
	}
}
void waitingTime()
{

	unsigned int releaseTime, t;
	for(unsigned int i=0; i<NP; i++)
	{

		for(t=time-1; scheduler[t]!= i; t--);
		releaseTime = t+1;
		processes[i][3] = releaseTime - processes[i][0] - processes[i][1];
	}

}
void printWaitingTime()
{
	int waitingTilmeSumm = 0;
	float AWT;
	printf("\nWaiting Time For Each Process: \n");
	for(unsigned int i=0; i<NP; i++)
	{
		printf("\nWT(%d) = %d", i+1, processes[i][3]);
		waitingTilmeSumm = waitingTilmeSumm + processes[i][3];
	}
	AWT = waitingTilmeSumm/(float)NP;
	printf("\nAverage Waiting Time = %f", AWT);
}
main()
{
	getSystem();
	printSystem();
	schedule();
	printScheduler();
	waitingTime();
	printWaitingTime();
}
