#include <iostream>
using namespace std;

class Graph{
	int graph[10][10];
	int e,v;
	bool mst[10];
public:
	Graph(){
		cout << "\nNumber of Edges : ";
        cin >> e;
        cout << "\nNumber of Vertices : ";
        cin >> v;

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++)
                graph[i][j] = 0;
        }
        for (int i = 0; i < 10; i++)
            mst[i] = false;
	}
	void Create();
	void Display(int parent[]);
	int minKey(int key[]);
	void Prims();
};

int Graph :: minKey(int key[]){
	int min=9999, min_index;
	for(int i=0; i<v; i++){
		if(mst[i]==false && key[i]<min)
			min=key[i], min_index=i;
	}
	return min_index;
}

void Graph :: Prims(){
	int parent[v];
	int key[v];
	for(int k=0; k<v; k++)
		key[k]=9999;
	parent[0]=-1;
	key[0]=0;
	for(int count=0; count<v-1; count++){
		int u = minKey(key);
		mst[u]=true;
		for(int i=0; i<v; i++){
			if(graph[u][i] && mst[i]==false && graph[u][i]<key[i]){
				key[i]=graph[u][i];
				parent[i]=u;
			}
		}
	}
	Display(parent);
}

void Graph :: Display(int parent[]){
	cout<<"Edges\tWeight\n";
	for(int i=1; i<v; i++){
		cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<" \n";
	}
}

void Graph :: Create(){
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cin>>graph[i][j];
			graph[j][i]=graph[i][j];
		}
	}
}

int main(){
	Graph G;
	G.Create();
	G.Prims();
}