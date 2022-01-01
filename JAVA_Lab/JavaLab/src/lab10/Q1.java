package lab10;

class Singleton{
	private static Singleton instance;

	private Singleton() {
	}

	synchronized public static Singleton getInstance() {
		if (instance == null) {
			instance = new Singleton();
		}
		return instance;
	}
}

public class Q1 {
	
	public static void main(String[] args) {
		Singleton s1 = Singleton.getInstance();
		Singleton s2 = Singleton.getInstance();
		
		System.out.println(s1);
		System.out.println(s2);
	}
}
