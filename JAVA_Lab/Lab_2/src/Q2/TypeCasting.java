package Q2;

public class TypeCasting {

	public static void main(String[] args) {
		// A narrowing of long to short loses high bits:
        long l = 0x12345678;
        System.out.println(Long.toBinaryString(l));
        System.out.println(Long.toBinaryString((short)l));
        
	}

}
