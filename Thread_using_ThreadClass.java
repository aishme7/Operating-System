
class myThread extends Thread
{
@Override
public void run()
{
for(int i=0;i<=10;i++)
{
System.out.println("Child thread");
}}
}
class thread1
{
public static void main(String [] args)
{
myThread t=new myThread();
t.start();
for(int i=1;i<=10;i++)
{
System.out.println("Parent thread");
}}
}