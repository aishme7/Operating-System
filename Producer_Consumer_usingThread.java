package producerconsumer;

import java.util.ArrayList;
public class ProducerConsumer {
public static void main(String[] args) {
     ArrayList <Integer> buffer = new ArrayList<Integer>();
     Thread t1 = new Thread(new P(buffer));
     Thread t2 = new Thread (new C(buffer));
     t1.start();
     t2.start();
    }
}
class P implements Runnable{
ArrayList<Integer> b = null;
final int limit =10;
int i =10;
P(ArrayList<Integer>buffer)
{
b = buffer;
}
public void run(){
while(true)
{
try{
 i++;
produce(i);
}
catch(Exception e)
{
System.out.println(e);
}
}
}
public void produce(int i )throws InterruptedException
{
synchronized(b){
while(b.size()==limit){
System.out.println("Producer is waiting for consumer to consume...");
b.wait();
}
}
synchronized (b){
    System.out.println("Added item is :" + i);
    b.add(i);
System.out.println("Producer has added item...");
Thread.sleep(100);
b.notify();
}
}
}
class C implements Runnable{
ArrayList<Integer> b = null;
//final int limit =10;
//int i =10;
C(ArrayList<Integer>buffer)
{
b = buffer;
}
public void run(){
while(true)
{
try{

consume();
}
catch(Exception e)
{
System.out.println(e);
}
}
}
public void consume( )throws InterruptedException
{
synchronized(b){
while(b.size()==0){
System.out.println("Consumer is consuming...");
b.wait();
}
}
synchronized (b){
b.remove(0);
System.out.println("Consumer has removed item..");
Thread.sleep(100);
b.notify();
}
}
}
