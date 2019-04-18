package producer_without_thread;

import java.util.Scanner;

public class Producer_without_Thread

{
       
int mutex=1;int E=10;int F=0;int count=0;

	
	public static void main(String...args)
	
	{
	
    
    
	Producer_without_Thread p=new Producer_without_Thread();
	
	Scanner sc=new Scanner(System.in);
	
	while(true)
	
	{
	
	System.out.println("Press 1 for producer,2 for consumer,3 to exit");
	
	int ch=sc.nextInt();
	
	switch(ch)
	
	{
	
	case 1:
		
	if(p.mutex==1 &&  p.E!=0)
		
	p.producer();
		
	else
		
	System.out.println("Producer is waiting");
		
	break;
	
	
	case 2:
		
	if(p.mutex==1 && p.F!=0)
		
	p.consumer();
		
	else
		
	System.out.println("Consumer is waiting");
		
	break;
	
	
	case 3:
		
	System.exit(0);
		
	break;

	
	}
	
	}
	
	
	}
	
	
	public void producer()
	
	{
	
	mutex=wait(mutex);
	
	F=signal(F);
	
	E=wait(E);
	
	count++;
	
	System.out.println("Producer is producing at "+count);
	
	mutex=signal(mutex);	
	
	}

	
	
	public void consumer()
	
	{
	
	mutex=wait(mutex);
	
	F=wait(F);
	
	E=signal(E);
	
	count--;
	
	System.out.println("Consumer is consuming at "+count);
	
	mutex=signal(mutex);	
	
	}

	
	
	public int wait(int s)
	
	{
	return	--s;
		
	
	}

    
	
	public int signal(int s)
	
	{
	return ++s;
	
	}
	

}


