package lab7;

public class NameOfMainThread {
	public static void main(String[] args) {
		Thread t = Thread.currentThread();
		System.out.println(t.getName());
		t.setName("mymain");
		System.out.println(t.getName());
	}
}
