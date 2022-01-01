package lab6;

public class ReadStackTrace {
	
	public static void func() throws Exception{
		throw new Exception("Somthing went wrong");
	}
	
	public static void main(String[] args) {
		try {
			func();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
