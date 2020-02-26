#include <iostream>
#include <queue>
#define MAX 10
using namespace std;

class node{
	string city;
	int cost;
	node *next;
public:
	node(){city=""; cost=0; next=NULL;}
	node(string c, int cost){
		city=c;
		this->cost=cost;
		next=NULL;
	}
	friend class graph;
};

class graph{
	node *head[MAX];
	int n;
	bool visited[MAX];
public:
	void addCity();
	void addFlight(string,string,int);
	void display();
	int inDegree(string);
	int outDegree(string);
	void callDFS();
	void dfs(int v);
	void bfs();
	void deleteCity(string);
	void deleteFlight(string,string);
};
void graph :: addFlight(string s, string d,int c){
	int i,j;
	node *temp=new node(d,c);

	for(i=0; i<n; i++){
		if(head[i]->city==s)
			break;
	}

	if(i==n){
		cout<<"Source City does not exist! Flight cannot be Added\n";
		return;
	}

	for(j=0; j<n; j++){
		if(head[j]->city==d)
			break;
	}

	if(j==n){
		cout<<"Destination City does not exist! Flight cannot be Added\n";
		return;
	}

	node *p=head[i];

	while(p->next!=NULL)
		p=p->next;

	p->next=temp;
}

void graph :: display(){
	node *p;
	for(int i=0; i<n; i++){
		p=head[i];
		cout<<p->city;
		p=p->next;
		while(p!=NULL){
			cout<<"\t("<<p->cost<<") "<<p->city;
			p=p->next;
		}
		cout<<"\n";
	}
}

int graph :: inDegree(string s){
	int i,count=0;
	node *p;
	for(i=0; i<n; i++){
		p=head[i];
		p=p->next;
		while(p!=NULL){
			if(p->city==s)
				count++;
			p=p->next;
		}
	}
	return count;
}

int graph :: outDegree(string s){
	int i,count=0;
	node *p;
	for(i=0; i<n; i++){
		if(head[i]->city==s){
			p=head[i];
			p=p->next;
			while(p!=NULL){
				if(p->city==s)
					count++;
				p=p->next;
			}
		}
	}
	return count;
}

