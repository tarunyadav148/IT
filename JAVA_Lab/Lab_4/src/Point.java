
public class Point implements Cloneable {
	public int x;
	public int y;
	
	public Point(int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	public Object clone() throws CloneNotSupportedException
    {
        return super.clone();
    }
}
