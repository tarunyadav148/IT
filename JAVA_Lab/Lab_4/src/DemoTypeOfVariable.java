
public class DemoTypeOfVariable {
	//instance variable
	public int instanceVariable = 10;
	
	//static variable
	public static int staticVariable = 50;
	
	public static void main(String[] args) {
		//local variable
		int localVariable = 30;
		
		DemoTypeOfVariable obj = new DemoTypeOfVariable();
		
		System.out.println("Instance Variable:"+obj.instanceVariable);
		System.out.println("Static Variable:"+staticVariable);
		System.out.println("Local Variable:"+localVariable);
	}
}
