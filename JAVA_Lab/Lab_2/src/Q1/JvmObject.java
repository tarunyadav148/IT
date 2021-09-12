package Q1;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class JvmObject {
	public static void main(String[] args) {
		Student student = new Student();
		
		//Getting Object created by JVM
		Class _class = student.getClass();
		
		//printing all field names
		Field[] fields = _class.getDeclaredFields();
		System.out.println("Printing All fields:");
		for(Field field:fields) {
			System.out.println(field.getName());
		}
		
		System.out.println("");
		
		//printing all methods names
		Method[] methods = _class.getDeclaredMethods();
		System.out.println("Printing All methods:");
		for(Method method:methods) {
			System.out.println(method.getName());
		}
		
		
	}
}
