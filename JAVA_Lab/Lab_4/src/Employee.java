
public class Employee {
	
	public Employee(String name, int yearOfJoining, long salary, String city) {
		super();
		this.name = name;
		this.yearOfJoining = yearOfJoining;
		this.salary = salary;
		this.city = city;
	}



	private String name;
	private int yearOfJoining;
	private long salary;
	private String city;
	
	

	public static void main(String[] args) {
		Employee[] employeeList = new Employee[3];
		employeeList[0] = new Employee("Amit",1994,120000,"Delhi");
		employeeList[1] = new Employee("Vijay",2000,150000,"Mumbai");
		employeeList[2] = new Employee("Akshaya",1999,130000,"Pune");
		
		System.out.printf("Name\tYear of joining\tAddress\n");
		
		for(int i=0;i<3;i++) {		
			System.out.printf("%s\t\t%d\t%s\n",
					employeeList[i].getName(),
					employeeList[i].getYearOfJoining(),
					employeeList[i].getCity()
					);
			
		}
		
		
	}
	
	



	public String getName() {
		return name;
	}



	public void setName(String name) {
		this.name = name;
	}



	public int getYearOfJoining() {
		return yearOfJoining;
	}



	public void setYearOfJoining(int yearOfJoining) {
		this.yearOfJoining = yearOfJoining;
	}



	public long getSalary() {
		return salary;
	}



	public void setSalary(long salary) {
		this.salary = salary;
	}



	public String getCity() {
		return city;
	}



	public void setCity(String city) {
		this.city = city;
	}

}
