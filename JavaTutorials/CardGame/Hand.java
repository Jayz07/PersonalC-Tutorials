
public class Hand{
	public static void displayArray(int showArray[]){
		for(int i:showArray){
			System.out.println(i);
		}
		System.out.println();
	}
	
	public static void main(String args[]){
		int test[] = new int[3];
		int a,b;
		
		test[0] = 1;
		test[1] = 2;
		test[2] = 3;
		
		displayArray(test);
		a = test[0];
		b = test[2];
		
		test[0] = b;
		test[2] = a;
		
		displayArray(test);
		
		
		
	}

}
