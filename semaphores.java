/*
A semaphore controls access to a shared resource through the use of a counter. If the counter is greater than zero, then access is allowed. If it is zero, then access is denied. What the counter is counting are permits that allow access to the shared resource. Thus, to access the resource, a thread must be granted a permit from the semaphore.

Java provide Semaphore class in java.util.concurrent package that implements this mechanism, so you don’t have to implement your own semaphores.


Constructors in Semaphore class : There are two constructors in Semaphore class.

Semaphore(int num)
Semaphore(int num, boolean how)

Here, num specifies the initial permit count. Thus, it specifies the number of threads that can access a shared resource at any one time. If it is one, then only one thread can access the resource at any one time. By default, all waiting threads are granted a permit in an undefined order. By setting how to true, you can ensure that waiting threads are granted a permit in the order in which they requested access.

Using Semaphores as Locks(preventing race condition)

We can use a semaphore to lock access to a resource, each thread that wants to use that resource must first call acquire( ) before accessing the resource to acquire the lock. When the thread is done with the resource, it must call release( ) to release lock. Here is an example that demonstrate this:

*/
// java program to demonstrate 
// use of semaphores Locks 
import java.util.concurrent.*; 

//A shared resource/class. 
class Shared 
{ 
	static int count = 0; 
} 

class MyThread extends Thread 
{ 
	Semaphore sem; 
	String threadName; 
	public MyThread(Semaphore sem, String threadName) 
	{ 
		super(threadName); 
		this.sem = sem; 
		this.threadName = threadName; 
	} 

	@Override
	public void run() { 
		
		// run by thread A 
		if(this.getName().equals("A")) 
		{ 
			System.out.println("Starting " + threadName); 
			try
			{ 
				// First, get a permit. 
				System.out.println(threadName + " is waiting for a permit."); 
			
				// acquiring the lock 
				sem.acquire(); 
			
				System.out.println(threadName + " gets a permit."); 
		
				// Now, accessing the shared resource. 
				// other waiting threads will wait, until this 
				// thread release the lock 
				for(int i=0; i < 5; i++) 
				{ 
					Shared.count++; 
					System.out.println(threadName + ": " + Shared.count); 
		
					// Now, allowing a context switch -- if possible. 
					// for thread B to execute 
					Thread.sleep(10); 
				} 
			} catch (InterruptedException exc) { 
					System.out.println(exc); 
				} 
		
				// Release the permit. 
				System.out.println(threadName + " releases the permit."); 
				sem.release(); 
		} 
		
		// run by thread B 
		else
		{ 
			System.out.println("Starting " + threadName); 
			try
			{ 
				// First, get a permit. 
				System.out.println(threadName + " is waiting for a permit."); 
			
				// acquiring the lock 
				sem.acquire(); 
			
				System.out.println(threadName + " gets a permit."); 
		
				// Now, accessing the shared resource. 
				// other waiting threads will wait, until this 
				// thread release the lock 
				for(int i=0; i < 5; i++) 
				{ 
					Shared.count--; 
					System.out.println(threadName + ": " + Shared.count); 
		
					// Now, allowing a context switch -- if possible. 
					// for thread A to execute 
					Thread.sleep(10); 
				} 
			} catch (InterruptedException exc) { 
					System.out.println(exc); 
				} 
				// Release the permit. 
				System.out.println(threadName + " releases the permit."); 
				sem.release(); 
		} 
	} 
} 

// Driver class 
public class SemaphoreDemo 
{ 
	public static void main(String args[]) throws InterruptedException 
	{ 
		// creating a Semaphore object 
		// with number of permits 1 
		Semaphore sem = new Semaphore(1); 
		String version = System.getProperty("java.version");
				System.out.println(version); 

		// creating two threads with name A and B 
		// Note that thread A will increment the count 
		// and thread B will decrement the count 
		MyThread mt1 = new MyThread(sem, "A"); 
		MyThread mt2 = new MyThread(sem, "B"); 
		
		// stating threads A and B 
		mt1.start(); 
		mt2.start(); 
		
		
		// count will always remain 0 after 
		// both threads will complete their execution 
		System.out.println("count: " + Shared.count); 
	} 
} 
