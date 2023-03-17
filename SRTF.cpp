#include <iostream>
using namespace std;
int main()
{
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    int i, j, smallest, count=0, time, n;
    double avg=0, tt=0, end;

    cout<<"\nenter the number of processes: ";
    cin>>n;
    
    for (i=0 ; i<n ; i++)
    {
        cout<<"\nenter the arrival time of process"<<i+1<<": ";
        cin>>a[i];
    }
    for(i=0 ; i<n ; i++)
    {
        cout<<"\nenter burst time of process"<<i+1<<": ";
        cin>>b[i];
    }
    
    for(i=0 ; i<n ; i++)
        x[i] = b[i];
    b[9] = 9999;

    for(time=0 ; count!=n ; time++)
    {
        smallest = 9;
        for(i=0 ; i<n ; i++)
        {
            if(a[i] <= time && b[i] < b[smallest] && b[i]>0)
                smallest = i;
        }
        b[smallest]--;

        if(b[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }

    cout<<"Process\t"<<"burst time\t"<<"arrival time\t"<<"waiting time\t"<<"turnaround time\t"<<"completion time"<<endl;

    for(i=0 ; i<n ; i++)
    {
        cout <<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg += waiting[i];
        tt += turnaround[i];
    }

    cout<<"\n\nAverage WT= "<<avg/n<<endl;
    cout<<"Average turnaround time= "<<tt/n<<endl;

}