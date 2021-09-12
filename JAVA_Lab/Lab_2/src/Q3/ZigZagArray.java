package Q3;

public class ZigZagArray {
	
	public int[][] array;

	public static void main(String[] args) {
		ZigZagArray z = new ZigZagArray();
		z.initializePattern();
		z.showPattern();
	}
	
	public void initializePattern() {
		//creating array
		this.array = new int[4][];
		this.array[0]  = new int[1];
		this.array[1]  = new int[2];
		this.array[2]  = new int[3];
		this.array[3]  = new int[4];
		//Initializing pattern to array
		for(int i=0;i<4;i++) 
			for(int j=0;j<=i;j++) 
				this.array[i][j] = j+1;
	}
	
	public void showPattern() {
		for(int i=0;i<4;i++) {
			for(int j=0;j<=i;j++) {
				System.out.print(this.array[i][j]+" ");
			}
			System.out.println("");
		}
	}

}
