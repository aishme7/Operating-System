package thread_using_runnable;
public class Thread_using_Runnable implements Runnable
{
 public void run(){
     for(int i=0;i<10;i++){
         System.out.println("Child Thread");
     }
 }
}
   class Thread2{
    public static void main(String[] args) {
    Thread_using_Runnable th = new  Thread_using_Runnable();
    Thread r = new Thread(th);
    r.start();
    for(int i=0;i<10;i++){
         System.out.println("Parent Thread");
     }
    }
    
}
