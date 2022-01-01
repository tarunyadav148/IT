package lab6;

import java.util.Scanner;

public class FinallyBlock {
	public static void main(String[] args) {
		int i = 0;
		Scanner scan;
		scan = new Scanner(System.in);
		try {
			System.out.println("Enter i:");
			i = scan.nextInt();
			System.out.println("i: "+i);
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		finally {
			scan.close();
		}
	}
}
