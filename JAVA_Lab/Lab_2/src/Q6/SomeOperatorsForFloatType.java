package Q6;

public class SomeOperatorsForFloatType {
	public static void main(String[] args) {
		int a=10>>3; // simple right shift and it cannot be applied to float
		System.out.println(a);
		
		
		a=10>>>3; // right shift filled with zero it just filled the empty space with 0 it also cannot applied on float
		System.out.println(a);
		
		
		double d = 10.5%5; //modulus operator on floating point numbers
		System.out.println(d);
	}
}
