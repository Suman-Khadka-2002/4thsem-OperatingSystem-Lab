#include<stdio.h>
#include<math.h>
int main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("Enter the max range of disk: ");
            scanf("%d",&max);
            printf("\nEnter the size of queue request: ");
            scanf("%d",&n);
            printf("\nEnter the queue of disk positions to be read:\n");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            printf("Enter the initial head position: ");
            scanf("%d",&head);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
            }
            printf("Total seek time is %d: ",seek);
            avg=seek/(float)n;
            printf("\nAverage seek time is %f: ",avg);
            return 0;
}