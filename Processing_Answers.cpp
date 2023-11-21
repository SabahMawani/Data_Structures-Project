#include <iostream>
#include <fstream>
#include <string>
#include "AVLTree.cpp"
using namespace std;

void Answers(AVL a);

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
	Answers(a);
}

void Answers(AVL a)
{
	fstream file,file1;
	bool flag=false;
	file.open("Answers.csv",ios::in);
	file1.open("Answers3.csv",ios::out);
	string line,line1,line2,line3;
	char temp,temp1,temp2;
	getline(file,line,',');
	getline(file,line,',');
	getline(file,line,',');
	getline(file,line,',');
	file1<<line<<',';
	getline(file,line,',');
	file1<<line<<',';
	getline(file,line);
	file1<<line<<endl;
	while(!file.eof())
	{
		flag=false;
		getline(file,line1,',');
		cout<<line1<<endl<<endl;
		getline(file,line1,',');
		cout<<line1<<endl<<endl;
		getline(file,line1,',');
		cout<<line1<<endl<<endl;
		getline(file,line2,',');
		cout<<line2<<endl<<endl;
		getline(file,line3,',');
		if(a.search(a.root,line2))
		{
			file1<<line2<<','<<line3<<',';
			flag=true;
		}
		cout<<line3<<endl<<endl;
		getline(file,line,'\n');
		if(flag)
			file1<<line;
		cout<<line;
		file.seekg(-3, ios::cur);
		file.get(temp);
		file.get(temp1);
		file.get(temp2);
		while(temp==temp1 || temp1!='"')
		{
			if(flag)
				file1<<" \\ ";
			cout<<" \\ ";
			getline(file,line,'\n');
			if(flag)
				file1<<line;
			cout<<line;
			file.seekg(-3, ios::cur);
			file.get(temp);
			file.get(temp1);
			file.get(temp2);
		}
		if(flag)
			file1<<endl;
		cout<<endl<<endl<<"break!!"<<endl<<endl;
	}
	file.close();
	file1.close();
}


