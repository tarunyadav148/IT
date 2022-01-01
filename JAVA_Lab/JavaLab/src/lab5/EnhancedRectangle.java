package lab5;

public class EnhancedRectangle extends Rectangle {
	int color[];
	float opacity;
	
	private void validateRGB() throws Exception{
		for(int i=0;i<this.color.length;i++) {
			if(color[i]<0 && color[i]>255)
				throw new Exception("RBG not in range");
		}		
	}
	
	EnhancedRectangle(int l,int w,int r,int g, int b, float o) throws Exception{
		super(l,w);
		color = new int[3];
		color[0] = r;
		color[1] = g;
		color[2] = b;
		this.validateRGB();
		this.opacity = o;
		
	}
	
	float grayscale() {
		return (color[0]+color[1]+color[2])/3;
	}
	
	public static void main(String[] args) {
		try {
			EnhancedRectangle rect = new EnhancedRectangle(4,5,40,156,200,0.7f);
			System.out.println("Area of Enhanced Rectangle:"+rect.area());
			System.out.println("Opacity:"+rect.opacity);
			System.out.println("Greyscale:"+rect.grayscale());
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
	}
	
}
