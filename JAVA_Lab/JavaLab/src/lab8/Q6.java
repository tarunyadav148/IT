package lab8;

public class Q6 implements Runnable {
	
	int count = 0;
	long x = 0;
	
	synchronized void increament() {
		for(int i=0;i<500000;i++) {
			
			for(int j=0;j<10;j++) {x++;}
			
			count++; count = count +1;
		}
	}
	
	public void run() {
		increament();
	}

	public static void main(String[] args) throws Exception {
		Q6 obj = new Q6();
		
		Thread t1 = new Thread(obj);
		Thread t2 = new Thread(obj);
		t1.start();
		t2.start();
		
		t1.join();
		t2.join();
		
		System.out.println(obj.count);		

	}

}
