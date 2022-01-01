package lab5;

public class Employee extends Person {
	int id;
	float salary;
	
	void incrementSalary(float percentage) {
		this.salary += (percentage/100)*this.salary;
	}
	
	public static void main(String[] args) {
		Person p = new Employee();
		p.age = 25;
		p.firstName = "Abhi";
		p.lastName = "Singh";
		
		System.out.println("Name of person: "+p.name());
	}
	
}
