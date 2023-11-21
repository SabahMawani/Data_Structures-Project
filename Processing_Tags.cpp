#include <iostream>
#include <fstream>
#include <string>
#include "AVLTree.cpp"
using namespace std;

void Tags(AVL a);

int main()
{
	AVL a;
	fstream file,file1;
	file.open("Questions3.csv",ios::in);
	string line,line1;
	getline(file,line);
	for(int i=0;i<10976;i++)
	{
		getline(file,line,',');
		cout<<line<<endl;
		a.root=a.insert(line,a.root);
		getline(file,line1);
	}
	Tags(a);
}

void Tags(AVL a)
{
	fstream file,file1;
	file.open("Tags.csv",ios::in);
	file1.open("Tags3.csv",ios::out);
	string line,line1;
	getline(file,line);
	file1<<line<<endl;
//	for(int i=0;i<100;i++)
	while(!file.eof())
	{
		getline(file,line,',');
		cout<<line<<endl<<endl;
		getline(file,line1);
		cout<<line1<<endl<<endl;
		if(a.search(a.root,line))
		{
			file1<<line<<','<<line1<<endl;
		}
	}
	file.close();
	file1.close();
}
