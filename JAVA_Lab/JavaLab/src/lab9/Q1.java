package lab9;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Q1 {

	public static void main(String[] args) throws Exception {
		File sourceFile = new File("//home//tarun//Pictures//ayush.jpeg");
		File destinationFile = new File("//home//tarun//Desktop//"+sourceFile.getName());

		FileInputStream fileInputStream = new FileInputStream(sourceFile);
		FileOutputStream fileOutputStream = new FileOutputStream(
		                destinationFile);

		int bufferSize;
		byte[] bufffer = new byte[512];
		while ((bufferSize = fileInputStream.read(bufffer)) > 0) {
		    fileOutputStream.write(bufffer, 0, bufferSize);
		}
		fileInputStream.close();
		fileOutputStream.close();
		System.out.println("File copied");
	}

}
