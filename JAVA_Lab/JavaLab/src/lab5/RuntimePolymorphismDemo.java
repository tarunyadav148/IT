package lab5;

class Bank_{  
	float getRateOfInterest(){return 0;}  
}  
class SBI_ extends Bank_{  
	float getRateOfInterest(){return 8.4f;}  
}  
class ICICI_ extends Bank_{  
	float getRateOfInterest(){return 7.3f;}  
}  
class AXIS_ extends Bank_{  
	float getRateOfInterest(){return 9.7f;}  
}  

public class RuntimePolymorphismDemo {
	public static void main(String args[]){  
		Bank_ b;  
		b=new SBI_();  
		System.out.println("SBI Rate of Interest: "+b.getRateOfInterest());  
		b=new ICICI_();  
		System.out.println("ICICI Rate of Interest: "+b.getRateOfInterest());  
		b=new AXIS_();  
		System.out.println("AXIS Rate of Interest: "+b.getRateOfInterest());  
	}  
}
