import java.util.*;

public class PandI{
	public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		int choice, ch, value;
		String key;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		ArrayList<Integer> al = new ArrayList<>();
		HashMap<String, Integer> hm = new HashMap<>();
		LinkedList<Integer> ll = new LinkedList<>();
                Stack<Integer> st = new Stack<>();

		do{
			System.out.println("Enter your choice: \n1. Priority Queue \n2. HashMap \n 3. Stack \n4. LinkedList \n5. ArrayList \n6. Exit");
			choice=sc.nextInt();

			switch(choice){
				case 1: System.out.println("PRIORITY QUEUE: \n 1.Enqueue 2. Dequeue 3. Main Menu");
						ch=sc.nextInt();
						if(ch==1){
							System.out.println("Enter data: ");
							pq.add(new Integer(sc.nextInt()));
							for(int s: pq){
								System.out.print(s+" ");
							}
							break;
						}
						if(ch==2){
							System.out.println("Removed-"+pq.remove());
							break;
						}
						if(ch==3){
							break;
						}
						break;
				case 2: System.out.println("HASHMAP: ");
						key="hello"; value=2;
						hm.put(key, value);
						System.out.println(hm.hashCode());
						key="apple"; value=4;
						hm.put(key, value);
						System.out.println(hm.hashCode());
						System.out.println(hm.size());
						System.out.println(hm.remove("apple"));
						System.out.println(hm.size());
						break;
				case 3: System.out.println("Stack:");
						st.push(new Integer(10));
						System.out.println(st.pop());
						st.push(new Integer(30));
						System.out.println(st.peek());
						st.push(new Integer(20));
						System.out.println(st.pop());
						break;
				case 4: System.out.println("Linked List: ");
						ll.add(new Integer(1));
						ll.add(new Integer(2));
						ll.add(new Integer(3));
						System.out.println(ll.getFirst());
						System.out.println(ll.getLast());
						System.out.println(ll.remove());
						break;
				case 5: System.out.println("Array: ");
						al.add(new Integer(1));
						al.add(new Integer(2));
						al.add(new Integer(3));
						System.out.println(al.size());
						System.out.println(al.remove(1));
						break;
				case 6: break;
				default: System.out.println("Invalid! Enter again.");
			}
		}while(choice!=6);
	}
}
