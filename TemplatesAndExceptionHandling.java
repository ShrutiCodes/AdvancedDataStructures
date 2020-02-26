import java.util.*;
public class TandE{
	public static void main(String args[]){
		Stack st;
		System.out.println("Integer Stack: ");
		st=new IntStack();
		st.function();
		System.out.println("Character Stack: ");
		st=new CharStack();
		st.function();
	}
}

abstract class Stack{
	Stack(){}
	abstract protected void push();
	abstract protected int pop();
	abstract protected int top();
	public final void function(){
		Scanner sc = new Scanner(System.in);
		int choice;
		do{
			System.out.println("1. Push 2. Pop 3. Top 4. Exit. \nEnter choice: ");
			choice=sc.nextInt();
			switch(choice){
				case 1: push();
						break;
				case 2: if(pop()!=0)
							System.out.println(pop());
						break;
				case 3: if(top()!=0)
							System.out.println(top());
						break;
				case 4: break;
				default: System.out.println("Invalid! Enter again");
			}
		}while(choice!=4);
	}
}

class IntStack extends Stack{
	int[] IStack = new int[50];
	int tp = -1;
	protected void push(){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		try{
			RuntimeException re = new RuntimeException("Overflow!");
			if(tp==49)
				throw re;
			else
				IStack[++tp]=x;
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
		}
	}
	protected int pop(){
		try{
			RuntimeException re = new RuntimeException("Underflow!");
			if(tp==-1)
				throw re;
			else{
				System.out.println(IStack[tp--]);
				return 1;
			}
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
			return 0;
		}
	}
	protected int top(){
		try{
			RuntimeException re = new RuntimeException("Underflow!");
			if(tp==-1)
				throw re;
			else{
				System.out.println(IStack[tp]);
				return 1;
			}
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
			return 0;
		}
	}
}

class CharStack extends Stack{
	char[] CStack = new char[50];
	int tp = -1;
	protected void push(){
		Scanner sc = new Scanner(System.in);
		char x = sc.next().charAt(0);
		try{
			RuntimeException re = new RuntimeException("Overflow!");
			if(tp==49)
				throw re;
			else
				CStack[++tp]=x;
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
		}
	}
	protected int pop(){
		try{
			RuntimeException re = new RuntimeException("Underflow!");
			if(tp==-1)
				throw re;
			else{
				System.out.println(CStack[tp--]);
				return 1;
			}
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
			return 0;
		}
	}
	protected int top(){
		try{
			RuntimeException re = new RuntimeException("Underflow!");
			if(tp==-1)
				throw re;
			else{
				System.out.println(CStack[tp]);
				return 1;
			}
		}
		catch(RuntimeException re){
			System.out.println("Exception Caught: "+re);
			return 0;
		}
	}
}
