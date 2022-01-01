package lab2;

public class LabeledBreak {

	public static void main(String[] args) {
		System.out.println("Unlabeled break");
		for(int i=0;i<5;i++) {
			for(int j=0;j<=i;j++) {
				if(i==3)
					break;  //Unlabeled break 
				System.out.print("*");
			}
			System.out.println();
		}
		
		System.out.println("Labeled break");
		OUTTER_LOOP:  //creating a label
		for(int i=0;i<5;i++) {
			for(int j=0;j<=i;j++) {
				if(i==3)
					break OUTTER_LOOP;  //Labeled break
				System.out.print("*");
			}
			System.out.println();
		}
		

	}

}
