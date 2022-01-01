package lab8;

public class Q4 implements Runnable {
	
	int[] arr;
	
	Q4(){
		arr = new int[10];
	}
	
	public void run() {
		for(int i = 0;i<10;i++) {
			arr[i] = i;
		}
	}
	
	public static void main(String[] args) {
		Q4 obj = new Q4();
		Thread t = new Thread(obj);
		t.start();
		
		try {
			t.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		for(int i = 0;i<10;i++) {
			System.out.println(obj.arr[i]);
		}
	}

}
