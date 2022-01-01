package lab5;

abstract class Bike{  
	  abstract void run() throws Exception ;  
}  

class Honda extends Bike{  
	void run(){
		System.out.println("running safely");
	}  
} 

public class AbtractDemo {
	public static void main(String args[]) throws Exception{  
		 Bike obj = new Honda();  
		 obj.run();  
	}  
}
