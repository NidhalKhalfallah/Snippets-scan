//Define a method to access an element of a resource of type list. The index of the element is given by the user
//The method returns the element at the given index
//The method returns null if the index is out of range

public class ListAccessor {
	
	public static void main(String[] args) {
		
		List<String> list = new ArrayList<String>();
		list.add("A");
		list.add("B");
		list.add("C");
		list.add("D");
		list.add("E");
		list.add("F");
		list.add("G");
		list.add("H");
		list.add("I");
		list.add("J");
		list.add("K");
		list.add("L");
		list.add("M");
		list.add("N");
		list.add("O");
		list.add("P");
		list.add("Q");
		list.add("R");
		list.add("S");
		list.add("T");
		list.add("U");
		list.add("V");
		list.add("W");
		list.add("X");
		list.add("Y");
		list.add("Z");
		
		System.out.println("Enter the index of the element you want to access: ");
		Scanner sc = new Scanner(System.in);
		int index = sc.nextInt();
		sc.close();
		String element = list.get(index);
		System.out.println("The element at index " + index + " is: " + element);
	}
}