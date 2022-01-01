package lab4;

public class Complex {
	
	private double realPart;
	private double imaginaryPart;
	
	public Complex() {
		super();
		this.realPart = 0;
		this.imaginaryPart = 0;
	}
	
	public double getRealPart() {
		return realPart;
	}

	public void setRealPart(double realPart) {
		this.realPart = realPart;
	}

	public double getImaginaryPart() {
		return imaginaryPart;
	}

	public void setImaginaryPart(double imaginaryPart) {
		this.imaginaryPart = imaginaryPart;
	}
	
	public Complex(double realPart, double imaginaryPart) {
		super();
		this.realPart = realPart;
		this.imaginaryPart = imaginaryPart;
	}
	
	public Complex add(Complex otherNumber) {
		Complex result = new Complex();		
		result.realPart = this.realPart + otherNumber.realPart;
		result.imaginaryPart = this.imaginaryPart + otherNumber.imaginaryPart;
		return result;
	}
	
	public Complex subtract(Complex otherNumber) {
		Complex result = new Complex();		
		result.realPart = this.realPart + otherNumber.realPart;
		result.imaginaryPart = this.imaginaryPart - otherNumber.imaginaryPart;
		return result;
	}
	
	public Complex multiply(Complex otherNumber) {
		Complex result = new Complex();		
		result.realPart = (this.realPart * otherNumber.realPart) - 
							(this.imaginaryPart * otherNumber.imaginaryPart);
		result.imaginaryPart = (this.realPart * otherNumber.imaginaryPart) + 
								(this.imaginaryPart * otherNumber.realPart);
		return result;
	}
	
	public Complex divide(Complex otherNumber) {
		Complex result = new Complex();		
		result.realPart = ( (this.realPart * otherNumber.realPart) + 
							(this.imaginaryPart * otherNumber.imaginaryPart)
							)/(otherNumber.mod()*otherNumber.mod());
		result.imaginaryPart = ( (this.imaginaryPart*otherNumber.realPart) +
								 (this.realPart*otherNumber.imaginaryPart)
								)/(otherNumber.mod()*otherNumber.mod());
		return result;
	}
	
	
	private double mod() {
		return Math.sqrt(this.realPart*this.realPart + 
						this.imaginaryPart*this.imaginaryPart
					);
	}

	@Override
	public String toString() {
		String complex = Double.toString(this.realPart);
		if(this.imaginaryPart>0)
			complex += "+";
		complex += Double.toString(this.imaginaryPart)+"i";
		return complex;
	}
	
	
	
}
