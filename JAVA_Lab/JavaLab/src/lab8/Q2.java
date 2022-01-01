package lab8;

class ExtendThread extends Thread{
	public void run() {
		System.out.println("Extended Thread object");
	}
}
class ImplementRunnable implements Runnable{
	public void run() {
		System.out.println("Runnable implementing object");
	}
}

public class Q2 {

	public static void main(String[] args) {
		ExtendThread obj1=new ExtendThread();
		Thread obj2= new Thread(new ImplementRunnable(),"Runnable Thread");
		
		obj1.start();
		obj2.start();

	}

}
