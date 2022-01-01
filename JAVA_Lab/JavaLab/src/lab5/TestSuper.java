package lab5;

public class TestSuper {
	public static void main(String[] args) {
		
		System.out.println("Constructor called with super():");
		Dog d=new Dog();
				
		System.out.println("\nField used with super keyword");
		d.printColor();
		
		System.out.println("\nMethod call with super keyword");		
		d.work();
						
	}
}
