package lab8;

public class Q5 implements Runnable {
	
	public void run() {
		for(int i=0;i<100000;i++);
	}
	
	public static void main(String[] args) {
		Q5 obj = new Q5();
		Thread t = new Thread(obj);
		t.start();
		
//		try {
//			t.join();
//		} catch (InterruptedException e) {
//			e.printStackTrace();
//		}
		
		if(t.isAlive()) {
			System.out.println("Thread is alive");
		}else {
			System.out.println("Thread already finished");
		}
	}

}
