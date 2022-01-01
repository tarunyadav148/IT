package lab6;

public class ReThrow {
	public static void func2() throws Exception{
		throw new Exception("Somthing went wrong");
	}
	
	public static void func1() throws Exception{
		try {
			func2();
		}
		catch(Exception e) {
			throw e;
		}
	}
	
	public static void main(String[] args) {
		try {
			func1();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
