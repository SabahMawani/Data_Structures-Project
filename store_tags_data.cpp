#include <iostream>
#include <list>
#include <sstream>
#include <fstream>
#include "bst.cpp"
using namespace std;

class Tags{
	public:
	BST bst;
	
	void readTags()
	{
		fstream file;
		file.open("Tags3.csv", ios::in);
		string line;
		int id=0;	
		getline(file, line);
		
		while(!file.eof()){
			getline(file, line, ',');
			stringstream tag_id(line);
			tag_id >> id;
			getline(file, line);
			bst.root = bst.insert(bst.root, line, id);
		}
		
	}
};








