import java.util.concurrent.Semaphore;

public class Readerwriter {
    static int readcount=0;
    static Semaphore s = new Semaphore(1);
    static Semaphore wrt = new Semaphore(1);
   
static class Reader implements Runnable
{
 @Override
 public void run() 
 {
     try 
     {s.acquire();
     readcount++;
     if(readcount==1)
         wrt.acquire();
     s.release();
     System.out.println("READER");
     System.out.println(Thread.currentThread()+"Thread has started...");
     Thread.sleep(500);
     System.out.println(Thread.currentThread()+"Thread is running");
     s.acquire();
     readcount--;
     if(readcount==0)
         wrt.release();
     s.release();
     }
     catch(Exception e)
     {System.out.println(e);
 }
 }
}
 static class Writer implements Runnable{
     public void run()
     {try
     {wrt.acquire();
     System.out.println("WRITTER");
     System.out.println(Thread.currentThread()+"thread 1 started");
     Thread.sleep(500);
     System.out.println(Thread.currentThread()+" thread 1 still running");
     wrt.release();
     }
     catch(Exception e)
     {System.out.println(e);
         }
     
 }
 }




public static void main(String args[])
{Reader r = new Reader();
Writer w = new Writer();
Thread t1 = new Thread (r);
Thread t2 = new Thread (r);
Thread t3 = new Thread (w);
Thread t4 = new Thread (w);
t4.start();
t1.start();
t2.start();
t3.start();

}}
