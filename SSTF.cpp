#include<bits/stdc++.h>
using namespace std;
int main()
{
	int start,n,i,move=0,temp;
		cout<<"Enter the position of the current head"<<endl;
		cin>>start;
		cout<<"Enter the number requests in queue"<<endl;
		cin>>n;
		int req[n],dist[n];
		cout<<"Enter the requests in queue"<<endl;
		for(int i=0;i<n;i++)
		cin>>req[i];
		for(int i=0;i<n;i++)
       dist[i]=abs(start-req[i]);
       for(int i=0;i<n;i++)
       {
     	for(int j=i+1;j<n;j++)
     	 if(dist[i]>dist[j])
		  {
     	 	temp=dist[i];
     	 	dist[i]=dist[j];
     	 	dist[j]=temp;
     	 	
     	 	temp=req[i];
     	 	req[i]=req[j];
     	 	req[j]=temp;
		  }
	   } 
	   for(int i=1;i<n;i++)
	   {  
	 	  move+=abs(start-req[i]);
	 	  start=req[i];
	   }  
	cout<<"Total seek time is:"<<move;
	return 0;
	}
