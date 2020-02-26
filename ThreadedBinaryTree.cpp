#include <iostream>
using namespace std;

class Node{
	int data;
	Node *left, *right;
	bool rightThread, leftThread;
public:
	Node(int n){
		data=n;
		left=right=NULL;
		rightThread=leftThread=false;
	}
	friend class Stack;
	friend class TBT;
};
class TBT{
	Node *head;
public:
	TBT(){
		head=new Node(0);
		head->data=0;
		head->left=head;
		head->right=head;
		head->leftThread=false;
		head->rightThread=true;
	}
	void Create();
	void InsertLeft(Node *, Node *);
	void InsertRight(Node *, Node *);
	Node* LeastLeftNode(Node *temp);
	void InOrderTraversal();
	void PreOrderTraversal();
	friend class Stack;
};
class Stack{
	Node* st[25];
	int top;
	public:
		Stack(){
			top=-1;
		}
		void Push(Node* x){
			st[++top]=x;
		}
		void Pop(){
			top--;
		}
		Node* getTop(){
			return st[top];
		}
		bool isEmpty(){
			if(top==-1)
				return true;
			else
				return false;
		}
		friend class Node;
};

void TBT :: InsertLeft(Node *S, Node *T){
	T->left=S->left;
	S->left=T;
	T->right=S;
	S->leftThread=true;
}

void TBT :: InsertRight(Node *S, Node *T){
	T->right=S->right;
	S->right=T;
	T->left=S;
	S->rightThread=true;
}

void TBT :: Create(){
	int data; 
	char ch;
	Stack S;

	S.Push(head);
	while(!S.isEmpty()){
		Node *temp=S.getTop();
		S.Pop();
		if(temp!=head){
			cout<<"Do you want to enter left child of "<<temp->data<<"?";
			cin>>ch;
			if(ch=='y'||ch=='Y'){
				cout<<"Enter data: ";
				cin>>data;
				Node *temp1=new Node(data);
				InsertLeft(temp, temp1);
				S.Push(temp1);
			}
			cout<<"Do you want to enter right child of "<<temp->data<<"?";
			cin>>ch;
			if(ch=='y'||ch=='Y'){
				cout<<"Enter data: ";
				cin>>data;
				Node *temp2=new Node(data);
				InsertRight(temp, temp2);
				S.Push(temp2);
			}
		}
		else{
			cout<<"Enter root data: ";
			cin>>data;
			Node *temp3=new Node(data);
			InsertLeft(temp, temp3);
			S.Push(temp3);
		}
	}
}

Node* TBT :: LeastLeftNode(Node *temp){
	while(temp->leftThread)
		temp=temp->left;
	return temp;
}

void TBT :: InOrderTraversal(){
	Node *current = LeastLeftNode(head->left);
	while(current!=head){
		cout<<current->data<<" ";
		if(current->rightThread)
			current=LeastLeftNode(current->right);
		else
			current=current->right;
	}
}

void TBT :: PreOrderTraversal(){
	Node *temp = head->left;

	while(temp!=head){
		cout<<temp->data<<" ";
		if(temp->leftThread)
			temp=temp->left;
		else if(temp->rightThread)
			temp=temp->right;
		else{
			while(temp!=head && !temp->rightThread)
				temp=temp->right;
			if(temp->right==head)
				break;
			else
				temp=temp->right;
		}
	}
}

int main() {
	TBT T;
	int x;
	cout<<"---------------------------THREADED BINARY TREE---------------------------\n";
	cout<<"Header node has been set to 0\n";
	do{
		cout<<"\nEnter:"
			<<"\n1.Create"
			<<"\n2.Inorder Traversal"
			<<"\n3.Preorder Traversal"
			<<"\n4.Exit\n";
		cin>>x;
		switch(x){
			case 1:	T.Create();
					break;
			case 2: T.InOrderTraversal();
					break;
			case 3: T.PreOrderTraversal();
					break;
			case 4: break;
			default: cout<<"Invalid! Please enter a number between 1 through 3 only!\n";
		}
	}while(x!=4);
	return 0;
}