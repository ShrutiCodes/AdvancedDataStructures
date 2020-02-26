//============================================================================
// Name        : Assignment2.cpp
// Author      : Shruti
// Roll Number : 21168
// Description : Binary Search Tree: Dictionary
//============================================================================
/*
 * PROBLEM STATEMENT:
 * A Dictionary stores keywords & its meanings. Provide facility for adding new
 * keywords, deleting keywords, updating values of any entry, assign a given tree into
 * another tree (=). Provide facility to display whole data sorted in ascending/
 * Descending order. Use Binary Search Tree for implementation.
 */

#include <iostream>
using namespace std;

class Node{
	int n;
	string word;
	string meaning[10];
	Node *left;
	Node *right;
public:
	Node(){
		n=0;
		word="";
		meaning[0]="";
		left=NULL;
		right=NULL;
	}
	Node(string s){
		n=0;
		word=s;
		cout<<"Enter number of meanings you want to add for the keyword: "<<s<<": ";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Enter meaning "<<i+1<<": ";
			cin>>meaning[i];
		}
		left=NULL;
		right=NULL;
	}
	friend class BST;
	friend void Copy(Node *temp1, Node *temp2);
};
class BST{
	Node *root;
public:
	BST(){
		root=NULL;
	}
	void callAdd();
	Node* AddWord(Node *temp, Node *temp2);//to add new keywords
	void callUpdate();
	void UpdateMeaning();//update meaning of existing keywords
	Node* Traverse(Node *temp, string s);
	void callA();
	void Ascending(Node *temp);//display in ascending order
	void callD();
	void Descending(Node *temp);//display in descending order
	void operator =(BST T);//overloaded to copy BSTs
	void callDelete();
	Node* Smallest(Node *temp);//finds lexicographically smallest element in subtree of which temp is the head
	Node* Delete(Node* temp, string s);//deletes entry having keyword stored in s
};

//function to call creation function
void BST :: callAdd(){
	string s;
	cout<<"Enter keyword you want to add: ";
	cin>>s;
	Node *temp2=new Node(s);
	root=AddWord(root,temp2);
}
//adds dictionary entries word by word
Node* BST :: AddWord(Node *temp,Node *temp2){
	if(temp==NULL){
		return temp2;
	}
	else if(temp2->word>temp->word){
		temp->right=AddWord(temp->right,temp2);
	}
	else if(temp2->word<temp->word){
		temp->left=AddWord(temp->left,temp2);
	}
	return temp;
}

//calling function for updating meanings
void BST :: callUpdate(){
	UpdateMeaning();
}
//this function checks if the keyword whose meaning is to be updated exists in the tree
Node* BST :: Traverse(Node *temp, string s1){
	while(temp!=NULL){
		if(s1>temp->word)
			temp=temp->right;
		else if(s1<temp->word)
			temp=temp->left;
		else if(s1==temp->word)
			return temp;
	}
	return NULL;
}
//updates meanings of a keyword(adds more)
void BST :: UpdateMeaning(){
	Node *temp;
	string s1;
	int n1,i;
	cout<<"Enter the keyword whose meaning you want to update: ";
	cin>>s1;

	temp=Traverse(root,s1);

	if(temp!=NULL){ //if found, update meaning(s)
		cout<<"Enter the number of additional meanings you would like to add: ";
		cin>>n1;
		n1+=temp->n;
		for(i=temp->n;i<n1;i++){
			cout<<"Enter meaning: ";
			cin>>temp->meaning[i];
		}
		temp->n=n1;
		cout<<"Successfully updated!\n";
	}
	else if(temp==NULL)//if not found
		cout<<"This keyword does not exist in the dictionary! Please add it before requesting an update.\n";
}

//calls Ascending
void BST :: callA(){
	if(root==NULL)
		cout<<"Nothing to display!\n";
	else
		Ascending(root);
}
//displays dictionary in ascending order through Inorder traversal
void BST :: Ascending(Node *temp){
	if(temp==NULL)
		return;
	Ascending(temp->left);
	cout<<"Keyword: "<<temp->word<<", Meanings: ";
	for(int i=0;i<temp->n;i++)
		cout<<temp->meaning[i]<<", ";
	cout<<endl;
	Ascending(temp->right);
}
//calls Descending
void BST :: callD(){
	if(root==NULL)
		cout<<"Nothing to display!\n";
	else
		Descending(root);
}
//displays dictionary in descending order through reverse Inorder traversal
//ie traverse right subtree first, then left
void BST :: Descending(Node *temp){
		if(temp==NULL)
			return;
		Descending(temp->right);
		cout<<"Keyword: "<<temp->word<<", Meanings: ";
		for(int i=0;i<temp->n;i++)
			cout<<temp->meaning[i]<<", ";
		cout<<endl;
		Descending(temp->left);
}
//overloads = to copy a dictionary from one object to another
void BST :: operator =(BST temp){
	if(temp.root==NULL)
		return;
	root=temp.root;
	Copy(temp.root->left,root->left);
}
void Copy(Node *temp1, Node *temp2){
	if(temp1==NULL)
		return;
	temp2=new Node();
	temp2=temp1;
	Copy(temp1->left,temp2->left);
	Copy(temp1->right,temp2->right);
}

//calls function to deletes specific keywords
void BST :: callDelete(){
	Node *temp;
	string s2;

	cout<<"Enter the keyword that you want to delete from the dictionary: ";
	cin>>s2;

	temp=Traverse(root,s2);
	if(temp==NULL)
		cout<<"Sorry! The keyword "<<s2<<" does not exist in the dictionary! Cannot delete. \n";
	else
		root=Delete(root,s2);
}
//returns leftmost leaf node (smallest in value in the BST)
Node* BST :: Smallest(Node *temp){
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
Node* BST :: Delete(Node *temp, string s){
	if(temp==NULL)//if nothing
		return temp;
	if(s>temp->word)//picking a subtree
		temp->right=Delete(temp->right,s);
	else if(s<temp->word)//if not right, then left subtree
		temp->left=Delete(temp->left,s);
	else{//word located, now actually delete it
			if(temp->left==NULL){//one child(right) or no children
				Node *node=temp->right;
				delete temp;
				return node;
			}
			else if(temp->right==NULL){//one child(left) or no children
				Node *node=temp->left;
				delete temp;
				return node;
			}
			//two children
			Node *node=Smallest(temp->right);//selects lexicographically smallest word from the right subtree to replace the node that will be deleted
			temp->word=node->word;//copy contents of the smallest node found previously (inorder successor of the deleted node)
			//and then delete the inorder successor(actual value to be deleted has been replaced, now the replacee must be deleted.ss
			temp->right=Delete(temp->right,node->word);
	}
	return temp;
}

int main() {
	int x;
	BST bsT,bsT1;
	cout<<"----------------BINARY SEARCH TREE: DICTIONARY----------------\n";
	do{
		cout<<"\nMenu: "
			<<"\n1.Add new keyword and meaning"
			<<"\n2.Update meaning of keyword"
			<<"\n3.Delete keyword"
			<<"\n4.Copy dictionary"
			<<"\n5.Display in ascending order"
			<<"\n6.Display in descending order"
			<<"\n7.Exit\n";
		cin>>x;
		switch(x){
			case 1: bsT.callAdd();//Add new keywords
					break;
			case 2: bsT.callUpdate();//Update meaning
					break;
			case 3: bsT.callDelete();//Delete keyword
					break;
			case 4: bsT1 = bsT;//operator overloading
					cout<<"Successfully copied! \n";
					bsT1.callA();//display in ascending order
					break;
			case 5: bsT.callA();//display in ascending order
					break;
			case 6: bsT.callD();//display in descending order
					break;
			case 7: break;//exit
			default: cout<<"Invalid! Please enter number between 1 through 6\n";
		}
	}while(x!=7);
	return 0;
}
