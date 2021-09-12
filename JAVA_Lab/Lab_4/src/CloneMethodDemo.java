
public class CloneMethodDemo {
		
	public static void main(String[] args) {
		Point a = new Point(4,5);
		Point b = a;
		
		System.out.println(a);
		System.out.println(b);
		
		System.out.println();
		
		try {
			Point c = (Point)a.clone();
						
			System.out.println(a);
			System.out.println(c);
			
			System.out.println("c:("+c.x+","+c.y+")");
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		
		
	}
}
