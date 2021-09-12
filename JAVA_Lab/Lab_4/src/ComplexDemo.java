
public class ComplexDemo {

	public static void main(String[] args) {
		Complex z1 = new Complex(-1,-4);
		Complex z2 = new Complex(8,2);
		
		Complex add = z1.add(z2);
		Complex sub = z1.subtract(z2);
		Complex mul = z1.multiply(z2);
		Complex div = z1.divide(z2);
		
		
		System.out.println("z1: "+z1);
		
		z1.setImaginaryPart(4);
		
		System.out.println("z1: "+z1);
		System.out.println("z2: "+z2);
		
		System.out.println("Re(z1): "+z1.getRealPart());
		System.out.println("Img(z1): "+z1.getImaginaryPart());
		
		System.out.println("z1+z2: "+add);
		System.out.println("z1-z2: "+sub);
		System.out.println("z1*z2: "+mul);
		System.out.println("z1/z2: "+div);

	}

}
