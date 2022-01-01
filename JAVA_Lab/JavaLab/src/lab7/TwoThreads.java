package lab7;

class Hello implements Runnable{
	public void run() {
		for(int i=0;i<5;i++) {
			System.out.println("hello");
		}
	}
}

class Hi implements Runnable{
	public void run() {
		for(int i=0;i<5;i++) {
			System.out.println("hi");
		}
	}
}

public class TwoThreads {
	public static void main(String[] args) {
		Hello hello = new Hello();
		Hi hi = new Hi();
		
		Thread t1 = new Thread(hello);
		Thread t2 = new Thread(hi);
		
		t1.start();
		t2.start();
		
		for(int i=0;i<10;i++) {
			System.out.println("java");
		}
	}
}
