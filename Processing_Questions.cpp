#include <iostream>
#include <fstream>
#include <string>
#include "AVLTree.cpp"
using namespace std;

void Questions(void);

int main()
{
	Questions();
}

void Questions(void)
{
	fstream file,file1;
	bool flag=false;
	file.open("Questions.csv",ios::in);
	file1.open("Questions3.csv",ios::out);
	string line,line1,line2,line3,line4;
	char temp,temp1,temp2;
	int x;
	getline(file,line,',');
	file1<<line<<',';
	getline(file,line,',');
	getline(file,line,',');
	file1<<line<<',';
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
		getline(file,line2,',');
		cout<<line2<<endl<<endl;
		getline(file,line3,',');
		cout<<line3<<endl<<endl;
		getline(file,line2,',');
		cout<<line2<<endl<<endl;
		getline(file,line4,',');
		x=stoi(line4);
		if(x>=20&&x<=500)
		{
			file1<<line1<<','<<line3<<','<<line4<<',';
			flag=true;
		}
		cout<<line4<<endl<<endl;
		file.get(temp);
		cout<<temp;
		if(flag)
			file1<<temp;
		getline(file,line,'"');
		if(flag)
			file1<<line;
		cout<<line;
		if(flag==true&&temp=='"')
		{
			file1<<'"';
			cout<<'"';
		}
		file.get(temp);
		while(temp=='"')
		{
			if(flag)
				file1<<'"';
			cout<<'"';
			getline(file,line,'"');
			if(flag)
				file1<<line<<'"';
			cout<<line<<'"';
			file.get(temp);
		}
		cout<<endl<<endl<<"break!!"<<endl<<endl<<temp;
		if(flag)
			file1<<'"'<<temp;
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
