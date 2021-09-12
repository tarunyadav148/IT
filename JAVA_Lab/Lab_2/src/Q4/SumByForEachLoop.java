package Q4;

import Q3.ZigZagArray;

public class SumByForEachLoop {

	public static void main(String[] args) {
		ZigZagArray zigzagarray = new ZigZagArray();
		zigzagarray.initializePattern();
		System.out.println(calculateSum(zigzagarray));
	}
	
	public static int calculateSum(ZigZagArray zigzagarray) {
		int sum = 0;
		
		for(int[] array:zigzagarray.array) 
			for(int num:array) 
				sum += num;	
		
		return sum;
	}

}
