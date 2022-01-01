package lab8;

class Q {
	int n;
	boolean valueSet = false;

	synchronized int get() {
		while (!valueSet) {
			try {
				wait();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		System.out.println("Got : " + n);
		valueSet = false;
		notify();
		return n;
	}

	synchronized void put(int n) {
		while (valueSet) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		this.n = n;
		valueSet = true;
		System.out.println("Put :" + n);
		notify();

	}
}

class Producer implements Runnable {
	Q q;
	Thread t;

	Producer(Q q) {
		this.q = q;
		t = new Thread(this, "Producer");
	}

	public void run() {
		int i = 0;
		while (true) {
			q.put(i++);
		}
	}
}

class Consumer implements Runnable {
	Q q;
	Thread t;

	Consumer(Q q) {
		this.q = q;
		this.t = new Thread(this, "Consumer");
	}

	public void run() {
		while (true) {
			q.get();
		}
	}
}

public class Q8 {
	public static void main(String[] args) throws Throwable {
		Q q = new Q();
		Producer p = new Producer(q);
		Consumer c = new Consumer(q);

		p.t.start();
		c.t.start();

		p.t.join();
		c.t.join();

		System.out.println("Running now.... stop the program explicitly");
	}
}
