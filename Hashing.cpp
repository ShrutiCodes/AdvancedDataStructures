#include "iostream"
#include "fstream"
using namespace std;

class FileOps;

class Student{
	int roll, div;
	string name;
public:
	Student(){
		name="";
		div=0;
		roll=0;
	}
	void getData();
	void putData();
	friend class FileOps;
};

void Student::getData(){
	cout << "\nName : ";
	cin>>name;
    cout << "\nRoll Number : ";
    cin>>roll;
    cout << "\nDivision : ";
	cin>>div;
}

void Student::putData(){
	cout << "\nName : " << name;
    cout << "\nRoll Number : " << roll;
    cout << "\nDivision : " << div;
}

class FileOps{
public:
	void Read();
	void Write();
	bool Search(int num);
	void Delete();
};

void FileOps::Write(){
	char ch;
	ofstream f;
	f.open("data.txt", ios::out|ios::binary);
	do{
		Student s;
		s.getData();
		f.write((char*)&s, sizeof(s));
		cout<<"Enter another record? y/n \n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	f.close();
}

void FileOps::Read(){
	ifstream f;
	Student s;
	f.open("data.txt", ios::in|ios::binary);
	while(f.read((char *)&s, sizeof(s))){
		s.putData();
	}
	f.close();
}

bool FileOps::Search(int num){
	Student s;
	ifstream f;
	f.open("data.txt", ios::in|ios::binary);

	while(f.read((char*)&s, sizeof(s))){
		if(s.roll==num)
			return true;
	}
	f.close();
	return false;
}

void FileOps::Delete(){
	int n;
	fstream f1, f2;
	Student s1, s2,s;

	cout<<"Enter roll number of record you want to delete: ";
	cin>>n;
	if(!Search(n))
		cout<<"Sorry! This record does not exist.\n";
	else{
		f1.open("data.txt", ios::in|ios::binary);
		f2.open("file.txt", ios::out|ios::binary);
		while(f1.read((char*)&s1, sizeof(s1))){
			if(s1.roll!=n){
				s2=s1;
				f2.write((char*)&s2, sizeof(s2));
			}
		}
		f1.close();
		f2.close();
		f2.open("file.txt", ios::in|ios::binary);
		while(f2.read((char*)&s, sizeof(s)))
			s.putData();
		f2.close();
	}

}

int main(){
	int num;
	FileOps obj;

	obj.Write();

	obj.Read();

	cout<<"Enter roll number of record you want to search: ";
	cin>>num;
	if(obj.Search(num))
		cout<<"Found\n";
	else
		cout<<"not found\n";

	obj.Delete();
}