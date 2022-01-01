package lab6;

class InvalidArgumentRangeException extends Exception{
	InvalidArgumentRangeException(){
		super("argument value is not between 0 to 10");
	}
}

public class CustomException {
	
	public static void func(int x) throws InvalidArgumentRangeException {
		if(x<0 || x>10)
			throw new InvalidArgumentRangeException();
	}
	
	public static void main(String[] args) {
		try {
			func(90);
			System.out.println("argument is between 0 to 10");
		}
		catch(InvalidArgumentRangeException e){
			e.printStackTrace();
		}
	}
}
