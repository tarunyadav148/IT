package Q2;

public class PassArrayToFunction {
	
	static public void printArray(int[] array) {
		for(int num:array)
			System.out.println(num);
	}

	public static void main(String[] args) {
		int[] array = {1,4,8,17,45};
		
		//Reference Value of Array in passed
		printArray(array);

	}

}
