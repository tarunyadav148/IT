package lab5;

class Student implements Cloneable{  
	int rollno;  
	String name;  
  
	Student(int rollno,String name){  
		this.rollno=rollno;  
		this.name=name;  
	} 
  
	public Object clone()throws CloneNotSupportedException{  
		return super.clone();  
	}		
}

public class CloneMethodDemo {
	public static void main(String args[]){  
		try{  
		Student s1=new Student(101,"amit");  
		  
		Student s2=(Student)s1.clone();  
		  
		System.out.println(s1.rollno+" "+s1.name); 
		s1.name = "tarun";
		System.out.println(s2.rollno+" "+s2.name);  
		  
		}catch(CloneNotSupportedException c){
			c.printStackTrace();
		}  
		  
		}  
}
