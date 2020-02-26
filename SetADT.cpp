/*
To create ADT that implements the SET concept.
a)Add (new Element)-Place a value into the set
b)Remove (element) Remove the value
c)Contains (element) Return true if element is in collection
d)Size () Return number of values in collection,
  Iterator () Return an iterator used to loop over collection
e)Intersection of two sets, 
f)Union of two sets,
g)Difference between two sets,
h)subset
*/
#include<iostream>
using namespace std;
class SET;
class Element{
	int e;
	Element *next;
public:
	Element(){
		e=-100;
		next=NULL;
	}
	Element(int x){
		e=x;
		next=NULL;
	}
	friend class SET;
};
class SET{
	Element *start;
	int Crd;
public:
	SET(){
		start=NULL;
		Crd=0;
	}
	void InsertElement(int data);
	void RemoveElement();
	bool SearchElement(int data);
	void Union(SET B);
	void Intersection(SET B);
	void Difference(SET B);
	void Subset(SET B);
	void Display();
};

void SET :: Display(){
	Element *temp=start;
	while(temp!=NULL){
		cout<<temp->e<<" ";
		temp=temp->next;
	}
}

bool SET :: SearchElement(int data){
	Element *temp=start;
	while(temp!=NULL){
		if(temp->e==data)
			return true;
		temp=temp->next;
	}
	return false;
}

void SET :: InsertElement(int data){
	char choice;
	if(SearchElement(data))
			cout<<"Sorry! This element already exists in the set!\n";
	else{
		if(start==NULL){
			start=new Element();
			start->e=data;
			Crd++;
		}
		else{
			Element *p=start;
			Element *temp=new Element(data);
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
			Crd++;
		}
	}
}

void SET :: RemoveElement(){
	int data;
	cout<<"Enter element you want to remove: ";
	cin>>data;
	if(!SearchElement(data))
		cout<<"No such element exists in this set!\n";
	else{
		Element *temp=start;
		if(start->e==data){
			Element *p=start->next;
			delete start;
			Element *start = new Element();
			start=p;
		}
		else{
			while(temp){
				if(temp->next->e==data)
					break;
				else
					temp=temp->next;
			}
			if(temp->next->e==data){
				Element *p=temp->next->next;
				delete temp->next;
				temp->next=p;
			}
		}
	}
}

void SET :: Union(SET B){
	Element *tempA=start;
	Element *tempB=B.start;
	SET C;
	while(tempA!=NULL){
		C.InsertElement(tempA->e);
		tempA=tempA->next;
	}
	while(tempB!=NULL){
		if(!C.SearchElement(tempB->e))
			C.InsertElement(tempB->e);
		tempB=tempB->next;
	}
	C.Display();
}
void SET :: Intersection(SET B){
	Element *tempA=start;
	Element *tempB=B.start;
	SET C;
	while(tempA!=NULL){
		if(B.SearchElement(tempA->e))
			C.InsertElement(tempA->e);
		tempA=tempA->next;
	}
	C.Display();
}
void SET :: Difference(SET B){
	Element *tempA=start;
	SET C;
	while(tempA!=NULL){
		if(!B.SearchElement(tempA->e))
			C.InsertElement(tempA->e);
		tempA=tempA->next;
	}
	C.Display();
}
void SET :: Subset(SET B){
	int count=0;
	Element *tempA=start;
	while(tempA!=NULL){
		if(B.SearchElement(tempA->e))
			count++;
		tempA=tempA->next;
	}
	if(count==Crd)
		cout<<"A is a subset of B";
	else
		cout<<"A is not a subset of B";
}

int main(){
	int choice, temp;
	char ch;
	SET A, B;
	do{
		cout<<"\n1.InsertElement \n2.RemoveElement \n3.SearchElement \n4.Union \n5.Intersection \n6.Difference \n7.Subset \n8.Exit\n";
		cin>>choice;
		switch(choice){
			case 1: do{
						cout<<"Enter element you want to insert: ";
						cin>>temp;
						A.InsertElement(temp);
						cout<<"Do you want to enter another element? Enter y/n: ";
						cin>>ch;
					}while(ch=='Y'||ch=='y');
					A.Display();
					break;
			case 2: A.RemoveElement();
					break;
			case 3: cout<<"Enter element to search: ";
					cin>>temp;
					if(A.SearchElement(temp))
						cout<<"Found!\n";
					else
						cout<<"Not found!\n";
					break;
			case 4: cout<<"Enter Set B to union with previous set: ";
					do{
						cout<<"Enter element you want to insert: ";
						cin>>temp;
						B.InsertElement(temp);
						cout<<"Do you want to enter another element? Enter y/n: ";
						cin>>ch;
					}while(ch=='Y'||ch=='y');
					B.Display();
					A.Union(B);
					break;
			case 5: A.Intersection(B);
					break;
			case 6: A.Difference(B);
					B.Difference(A);
					break;
			case 7: A.Subset(B);
					break;
			case 8: break;
			default: cout<<"Invalid! Enter again.\n";
		}
	}while(choice!=8);
	return 0;
}