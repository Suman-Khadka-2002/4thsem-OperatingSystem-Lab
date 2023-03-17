#include <stdio.h>
// #include <conio.h>
#include <string.h>
int main()
{
	int bt[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
	int totwt=0,totta=0;
	float awt,ata;
	printf("Enter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Arrival time,Burst time & Priority:");
		printf("\np[%d]:",i+1);
		scanf(" %d %d %d",&at[i],&bt[i],&p[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i]<p[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			st[i]=at[i];
			wt[i]=st[i]-at[i];
			ft[i]=st[i]+bt[i];
			ta[i]=ft[i]-at[i];
		}
		else
		{
			st[i]=ft[i-1];
			wt[i]=st[i]-at[i];
			ft[i]=st[i]+bt[i];
			ta[i]=ft[i]-at[i];
		}
		totwt+=wt[i];
		totta+=ta[i];
	}
	awt=(float)totwt/n;
	ata=(float)totta/n;
	printf("Pname\tarrival time\t Bursttime \t priority \t waiting time \t tatime");
	for(i=0;i<n;i++)
	{
		printf("\n P[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],p[i],wt[i],ta[i]);
	}
	printf("\nAverage waiting time is: %f",awt);
	printf("\n Average turn around time is: %f",ata);
}
