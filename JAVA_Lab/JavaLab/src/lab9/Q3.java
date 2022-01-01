package lab9;

class Func extends Thread {

	volatile boolean working = true;
	public void run()
	{
		long count = 0;
		while (working) {
			count++;
		}

		System.out.println("Thread terminated."
						+ count);
	}
}

public class Q3 {

	public static void main(String[] args) throws InterruptedException {
		Func test = new Func();
		test.start();
		Thread.sleep(100);
		System.out.println("After Sleeping in Main");
		test.working = false;
		test.join();
		System.out.println("Working set to "+ test.working);
	}

}
