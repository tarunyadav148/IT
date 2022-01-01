package lab3;

public class CircularQueue<T> {
	private T[] array;
	private int front;
	private int back;
	private int size;
	
	@SuppressWarnings("unchecked")
	CircularQueue(int size){
		this.size = size;
		array = (T[]) new Object[size];
		front = -1;
		back = -1;
	}
	
	@SuppressWarnings("unchecked")
	CircularQueue(int size, T... args) throws Exception{
		this.size = size;
		array = (T[]) new Object[size];
		front = -1;
		back = -1;
		
		for(T i:args) {
			if(!this.isFull())
				this.enQueue(i);
		}
	}
	
	public boolean isFull() {
		return back+1 == front ;
	}
	
	public boolean isEmpty() {
		return front == -1;
	}
	
	void enQueue(T number) throws Exception {
		if(!this.isFull()) {
			array[(back+1)%size] = number;
			if(front == -1) {
				front = 0;
				back = 0;
			}
			else{
				back = (back+1)%size;
			}
		}
		else
			throw new Exception("Queue is Full");
	}
	
	T deQueue() throws Exception {
		if(!this.isEmpty()){
			T num = this.array[front];
			if(front == back) {
				front = -1;
				back = -1;
			}
			else {
				front = (front+1)%size;
			}
			return num;
		}
		else
			throw new Exception("Empty Queue");
	}
	
	

	public static void main(String[] args) {
		
		CircularQueue<Integer> q = new CircularQueue<Integer>(10);
		
		
		if(q.isEmpty()){
			System.out.println("Queue is Empty");
		}
		
		try {
			q.enQueue(5);
			q.enQueue(7);
			q.enQueue(9);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		try {
			System.out.println("This number is DeQueued: "+q.deQueue());
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		try {
			CircularQueue<Integer> cq = new CircularQueue<Integer>(10,8,7,6);
			System.out.println("This number is DeQueued: "+cq.deQueue());
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}