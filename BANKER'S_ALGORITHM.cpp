#include<iostream>
using namespace std;
#define max 10
main()
{
 int p,r,counter,exec,running[max],safe,maxall[max][max],runn[1],curall[max][max],avail[max],need[max][max];
 cout<<"\nEnter no. of processes:";	
 cin>>p;
 cout<<"\nEnter no. of resources:";	
 cin>>r;
 //current allocation matrix
 cout<<"\nEnter Current Allocation values:"<<endl;
 for(int i=0;i<p;i++)
 {
 	for(int j=0;j<r;j++)
 	{
 		cin>>curall[i][j];
 		
	 }
 }
 cout<<"\nEnter Maximum Allocation values:"<<endl;
 //max allocation matrix
 for(int i=0;i<p;i++)
 {
 	for(int j=0;j<r;j++)
 	{
 		cin>>maxall[i][j];
	}
 }
 //availablity matrix
 cout<<"\nEnter availablity:";
 for(int i=0;i<r;i++)
 	{
 		cin>>avail[i];cout<<"\t";
	}
 cout<<"\nNeed matrix :";
//need matrix
for(int i=0;i<p;i++)
 {
 	for(int j=0;j<r;j++)
 	{
 		 need[i][j]=maxall[i][j]-curall[i][j];cout<<need[i][j]<<"  ";
 		 
	} cout<<"\n\n";
 }
 counter=p;

 while(counter!=0)
 {
 	safe=0;
 	for(int i=0;i<p;i++)
 {
 	if (running[i])
 	exec=1;
 	 for(int j=0;j<r;j++)
    {
    	if(maxall[i][j]-curall[i][j]>avail[j])
		{
    	   exec=0;
		   break;	
		}
	} if(exec)
	{
		runn[i]=0;
	}
	
	for(int j=0;j<r;j++){
		avail[j]+=curall[i][j];
		safe=1;
	}
	
 }
 if (safe==0)
 cout<<"\nIt is not safe...";
 else
 cout<<"\n It is safe...";
break;
 	
}

for(int i=0;i<p;i++)
{
	for(int j=0;j<r;j++)
	{
		avail[j]+=maxall[i][j];
	}
}

cout<<"Available is ";
for(int i=0;i<r;i++) cout<<avail[i]<<"  ";

}
//Inputs:
/*
5 
3
0		1		0
2		0		0
3		0		2
2		0		0
0		0		2

7		5		3
3		2		2	
9		0		2
2		2		2
4		3		3	

3		3		2

*/
 
