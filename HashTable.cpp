#include "iostream"
using namespace std;

class Hash_Table;
class Node{
    int key;
    string value;

  public:
    Node(){
        key = -1;
        value = "";
    }
    friend class Hash_Table;
};

class Hash_Table{
    int n;
    int count;
    Node *table;

  public:
    Hash_Table(){
        cout<<"\nSize : ";
        cin>>n;
        table = new Node[n];
        count = 0;
    }
    int hash(int);
    void insert();
    void insert_r();
    int search(int);
    void call_search();
    void delete_entry();
    void call_rehashify();
    void rehashify(int, string);
};

int Hash_Table::hash(int h){
    int x = h%n;
    return x;
}

void Hash_Table::insert(){
    string v; int k;
    cout<<"Enter key: ";
    cin>>k;
    cout<<"Enter value: ";
    cin>>v;

    int h = hash(k);

    if(table[h].key==-1){
        table[h].key=k;
        table[h].value=v;
        count++;
    }
    else{
        h++;
        if(h==n)
            h=0;
        while(true){
            if(table[h].key!=-1){
                table[h].key=k;
                table[h].value=v;
                count++;
            }
            h=(h+1)%n;
        }
    }
}
void Hash_Table::insert_r(){
    string v; int k;
    cout<<"Enter key: ";
    cin>>k;
    cout<<"Enter value: ";
    cin>>v;

    int h = hash(k);

    if(table[h].key==-1){
        table[h].key=k;
        table[h].value=v;
        count++;
    }
    else{
        string v1=table[h].value;
        int k1=table[h].key;
        int h1=hash(k1);
        if(h1==h){
            h++;
            if(h==n)
                h=0;
            while(true){
                if(table[h].key!=-1){
                    table[h].key=k;
                    table[h].value=v;
                    count++;
                }
                h=(h+1)%n;
            }
        }
        else{
            table[h].key=k;
            table[h].value=v;
            count++;
            h1++;
            if(h1==n)
                h1=0;
            while(true){
                if(table[h1].key!=-1){
                    table[h1].key=k1;
                    table[h1].value=v1;
                    count++;
                }
                h1=(h1+1)%n;
            }
        }
    } 
}
int Hash_Table::search(int k){
    int h = hash(k);
    if(table[h].key==k)
        return h;
    else{
        int t = h+1;
        if(t==n)
            h=0;
        while(t!=h){
            if(table[h].key==k)
                return h;
            else
                h=(h+1)%n;
        }
    }
    return -1;
}
void Hash_Table::call_search(){
    int e;
    cout<<"Enter key to search for: ";
    cin>>e;
    if(search(e)==-1)
        cout<<"not found";
    else
        cout<<"found";
}
void Hash_Table::call_rehashify(){
    for(int i=0; i<n; i++){
        if(table[i].key==-1)
            continue;
        rehashify(table[i].key, table[i].value);
    }
}

void Hash_Table::rehashify(int k, string v){
    int h = hash(k);
    if(table[h].key==-1){
        table[h].key=k;
        table[h].value=v;
    }
}

void Hash_Table::delete_entry(){
    int e;
    cout<<"Enter key to delete: ";
    cin>>e;

    if(search(e)==-1)
        cout<<"Does not exist!\n";
    else{
        int h = search(e);
        table[h].key=-1;
        table[h].value="";
    }

}
int main(){
    Hash_Table ht;
    int choice;
    do{
        cout<<"\n1. Insert without replacement"
            <<"\n2. Insert with replacement"
            <<"\n3. Search"
            <<"\n4. Delete"
            <<"\n5. Exit\n";
        cin>>choice;

        switch(choice){
            case 1: ht.insert();
                    break;
            case 2: //ht.insert_r();
                    break;
            case 3: ht.call_search();
                    break;
            case 4: ht.delete_entry();
                    break;
            case 5: cout<<"\nThank you";
                    break;
            default:cout<<"\nWrong Choice";
                    break;
        }
    } while(choice!=5);
}