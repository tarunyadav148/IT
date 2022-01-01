package lab6;

public class NestedTryCatch {
	public static void main(String[] args) {
		int[] arr = {1,2,0,4};
		
		try {
			try {
				System.out.println(10/arr[2]);
			}
			catch(ArrayIndexOutOfBoundsException e) {
				e.printStackTrace();
			}
			
		}
		catch(ArithmeticException e) {
			e.printStackTrace();
		}
		
	}
}
