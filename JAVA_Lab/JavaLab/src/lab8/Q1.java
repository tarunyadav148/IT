package lab8;

public class Q1 {

	public static void main(String[] args) {
		Thread obj=Thread.currentThread();
		System.out.println("Name of Thread: "+obj.getName()+"| Priority :"+obj.getPriority());
		
		obj.setName("New Name");
		obj.setPriority(6);
		
		System.out.println("Name of Thread: "+obj.getName()+"| Priority :"+obj.getPriority());
		
		}

}
