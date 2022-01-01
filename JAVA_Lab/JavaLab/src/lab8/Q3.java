package lab8;

import java.util.Scanner;
import java.util.concurrent.ThreadFactory;

class MyThreadFactory implements ThreadFactory {
	private int count;

	public MyThreadFactory() {
		count = 0;
	}

	public Thread newThread(Runnable r) {
		Thread thread = new Thread(r, "Thread number " + (++this.count));
		return thread;
	}
}

class MyClass implements Runnable {
	public void run() {
		System.out.println(Thread.currentThread());
	}
}

public class Q3 {
	public static void main(String[] args) {
		int numberOfThreads;System.out.println("Enter the number of threads you want to create : ");

		Scanner input=new Scanner(System.in);numberOfThreads=input.nextInt();

		MyThreadFactory createThread = new MyThreadFactory();
		Thread ref;
		MyClass obj = new MyClass();

		for(
		int i = 0;i<numberOfThreads;i++)
		{
			ref = createThread.newThread(obj);
			ref.start();
		}

		input.close();
	}
	
}
