#include <stdio.h>
#include <string.h>
int main()
{
	int at[5]={3,5,0,5,4};
	int bt[5]={4,3,2,1,3};
	char p_id[5]={'a','b','c','d','e'};
	int tat[5], wt[5], ct[5], i, sum=0;
	float avg_tat, avg_wt;
	printf("p_id\t Arrival time\t burst time");
	for(i=0 ; i<5 ; i++)
		printf("\n%c\t\t %d\t\t %d", p_id[i], at[i], bt[i]);
	//turnaround time = completion time - arrival time
	//waiting time = turnaround time - burst time
	
	int j=0;
	float total_tat=0, total_wt=0;
	while (j!=5)
	{
		ct[j] = bt[j] + sum;
		tat[j] = ct[j] - at[j];
		total_tat += tat[j];
		wt[j] = tat[j] - bt[j];
		total_wt += wt[j];
		sum += bt[j];
		j++;

	}
	avg_tat = (total_tat)/5;
	avg_wt =(total_wt)/5;
	printf("\nAverage turn around time = %.3f", avg_tat);
	printf("\nAverage waiting time = %.3f", avg_wt);
	return 0;
}
