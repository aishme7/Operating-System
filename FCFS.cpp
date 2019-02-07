#include<iostream>
using namespace std;
#define max10
int main()
{
	int n;
	float at[n],bt[n],ct[n],tat[n],wt[n],avgtat=0,avgwt=0;
	cout<<"Enter no. of processes: ";
	cin>>n;
	cout<<"Enter Arrival Time of processes: ";
	for(int i=0;i<n;i++){
		cin>>at[i];
	}
	cout<<"______________________________________";
	cout<<"\nEnter Burst Time of processes: ";
	for(int i=0;i<n;i++){
		cin>>bt[i];
    }
	cout<<"______________________________________"<<"\n";
    //Completion time
	ct[0]=bt[0];
	for(int i=1;i<n;i++) 
	{
		if(at[i]>ct[i-1])
		ct[i]=at[i]+bt[i];
		else
		ct[i]=ct[i-1]+bt[i];
	}
	
	//turn around time
		for(int i=0;i<n;i++)
	{
	tat[i]=ct[i]-at[i];
	avgtat=avgtat+tat[i];	
	}
	
	
	//waiting time	
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		avgwt+=wt[i];
	}
	
	
	//Result
	cout<<"Completion Time"<<"\t"<<" Total Arrival Time"<<"\t"<<"Waiting Time\n"<<"\n";
	for(int i=0;i<n;i++)
	cout<<ct[i]<<"\t\t|\t\t"<<tat[i]<<"\t\t|\t\t"<<wt[i]<<endl;
    cout<<"\nAverage TurnAround time is:  "<<avgtat;
    cout<<"\nAverage Waiting time is:  "<<avgwt;
return 0;	
}
