package lab6;

public class MultiCacthDemo {
	public static void main(String[] args) {
		int[] arr = {1,2,0,4};
		
		try {
			System.out.println(10/arr[2]);
		}
		catch(ArithmeticException e) {
			e.printStackTrace();
		}
		catch(ArrayIndexOutOfBoundsException e) {
			e.printStackTrace();
		}
		
		
	}
}
