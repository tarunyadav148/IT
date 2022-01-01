package lab10;

interface Shape {
	void draw();
}

class Circle implements Shape {
	public void draw() {
		System.out.println("Drawing a Circle....");
	}
}

class Rectangle implements Shape {
	public void draw() {
		System.out.println("Drawing a Rectangle....");
	}
}

class Square implements Shape {
	public void draw() {
		System.out.println("Drawing a Rectangle....");
	}
}

class ShapeFactory {
	public Shape getShape(String shapeType) {
		if (shapeType == null) {
			return null;
		}
		if (shapeType.equalsIgnoreCase("CIRCLE")) {
			return new Circle();
		} else if (shapeType.equalsIgnoreCase("RECTANGLE")) {
			return new Rectangle();
		} else if (shapeType.equalsIgnoreCase("SQUARE")) {
			return new Square();
		}
		return null;
	}
}

public class Q2 {
	public static void main(String[] args) {
		ShapeFactory shapeFactory = new ShapeFactory();

		Shape circle = shapeFactory.getShape("circle");
		circle.draw();
		
		Shape rectangle = shapeFactory.getShape("rectangle");
		rectangle.draw();
		
		Shape square = shapeFactory.getShape("square");
		square.draw();
	}
}
