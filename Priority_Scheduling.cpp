#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    cout<<"\nEnter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter  Priority and Burst Time of:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nProcess: "<<i+1<<endl;
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;                    //contains process number
        cout<<"Burst Time: ";
        cin>>bt[i];
                 
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    cout<<"\n\tProcess    \t\tBurst Time    \t\tWaiting Time   \t\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\n\t"<<p[i]<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i];
    }
 
    avg_tat=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}
 


