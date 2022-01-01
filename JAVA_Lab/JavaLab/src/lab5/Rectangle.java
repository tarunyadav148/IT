package lab5;
public class Rectangle extends Shape {
		int lenght;
		int width;
		
		Rectangle(int l,int w){
			super(4);
			this.lenght = l;
			this.width = w;
		}
		
		int area() {
			return this.lenght*this.width;
		}
}
