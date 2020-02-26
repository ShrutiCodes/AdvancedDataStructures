#include <iostream>
#include <cmath>
using namespace std;

class Tree;
class Node{
	int data;
	Node *left, *right;
public:
	Node(){
		data=0;
		left=right=NULL;
	}
	Node(int d){
		data=d;
		left=right=NULL;
	}
	friend class Tree;
};

class Tree{
	Node *root;
public:
	Tree(){
		root=NULL;
	}
	Node* LL(Node*);
	Node* RR(Node*);
	Node* LR(Node*);
	Node* RL(Node*);
	Node* Successor(Node*);

	void callInsert(int a){
		Node *temp=new Node(a);
		root=Insert(temp, root);
		cout<<"Root: "<<root->data<<endl;
	}
	void callHeight(){
		if(root==NULL)
			return;
		else
			cout<<"Height is: "<<Height(root)<<endl;
	}
	void callDelete(){
		int d;
		cout<<"Enter data you want to delete: ";
		cin>>d;

		root=Delete(root,d);
	}
	void callTraversal(){
		if(root==NULL)
			cout<<"Empty!\n";
		else{
			cout<<"Inorder: ";
			Inorder(root);
			cout<<"Preorder: ";
			Preorder(root);
		}
	}
	
	Node* Insert(Node*, Node*);
	Node* Delete(Node*, int a);
	int BalanceFactor(Node*);
	int Height(Node*);
	void Inorder(Node*);
	void Preorder(Node*);
};


Node* Tree::LL(Node *temp){
	Node *current=temp->left;
	temp->left=current->right;
	current->right=temp;
	return current;
}

Node* Tree::LR(Node *temp){
	Node *temp1=temp->left;
	Node *temp2=temp1->right;
	temp1->right=temp2->left;
	temp2->left=temp1;
	temp->left=temp2;
	temp=LL(temp);
	return temp;
}

Node* Tree::RL(Node *temp){
	Node *temp1=temp->right;
	Node *temp2=temp1->left;
	temp1->left=temp2->right;
	temp2->right=temp1;
	temp->right=temp2;
	temp=RR(temp);
	return temp;
}

Node* Tree::RR(Node *temp){
	Node *current=temp->right;
	temp->right=current->left;
	current->left=temp;
	return current;
}

int Tree::BalanceFactor(Node *temp){
	int x, y;
	x=Height(temp->left);
	y=Height(temp->right);
	return (x-y);
}

Node* Tree::Successor(Node *temp){
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}

Node* Tree::Insert(Node *temp1, Node *temp2){
	if(temp2==NULL)
		return temp1;

	if(temp1->data < temp2->data){
		temp2->left=Insert(temp1, temp2->left);
		if(abs(BalanceFactor(temp2))>1){
			if(temp2->left->data > temp1->data)
				temp2=LL(temp2);
			else
				temp2=LR(temp2);
		}
	}
	else{
		temp2->right=Insert(temp1, temp2->right);
		if(abs(BalanceFactor(temp2))>1){
			if(temp2->right->data < temp1->data)
				temp2=RL(temp2);
			else
				temp2=RR(temp2);
		}
	}
	return temp2;
}

void Tree::Inorder(Node *temp){
	if(temp==NULL)
		return;
	Inorder(temp->left);
	cout<<temp->data<<" ";
	Inorder(temp->right);
}

void Tree::Preorder(Node *temp){
	if(temp==NULL)
		return;
	cout<<temp->data<<" ";
	Preorder(temp->left);
	Preorder(temp->right);
}

int Tree::Height(Node *temp){
	if(temp==NULL)
		return 0;
	int x=Height(temp->left);
	int y=Height(temp->right);

	return(x>y?x+1:y+1);
}

Node* Tree::Delete(Node *temp, int a){
	if(temp==NULL)
		return NULL;

	if(a < temp->data){
		temp->left=Delete(temp->left, a);
		if(abs(BalanceFactor(temp))>1){
			if(BalanceFactor(temp->right)==0 || BalanceFactor(temp->right)==-1)
				temp=RR(temp);
			else
				temp=RL(temp);
		}
	}
	else if(a > temp->data){
		temp->right=Delete(temp->right, a);
		if(abs(BalanceFactor(temp))>1){
			if(BalanceFactor(temp->left)==0 || BalanceFactor(temp->right)==1)
				temp=LL(temp);
			else
				temp=LR(temp);
		}
	}
	else{
		if(temp->left==NULL){
			Node *n=temp->right;
			delete temp;
			return n;
		}
		else if(temp->right==NULL){
			Node *n=temp->left;
			delete temp;
			return n;
		}
		else{
			Node *current=Successor(temp->right);
			temp->data=current->data;
			temp->right=Delete(temp->right, current->data);
		}
	}
	return temp;
}

int main() {
	Tree t;
	int c,n;

	do{
		cout<<"1. Insert\n"
			<<"2. Delete\n"
			<<"7. Height\n"
			<<"8. Display(Inorder)\n"
			<<"10.Exit\n";
		cin>>c;
		switch(c){
			case 1: cout<<"Enter Element\n";
					cin>>n;
					t.callInsert(n);
					break;
			case 2: t.callDelete();
					break;
			case 7: t.callHeight();
					break;
			case 8: t.callTraversal();
					break;
			case 10: break;
			default: cout<<"Invalid\n";
		}

	}while(c!=10);
	return 0;
}
