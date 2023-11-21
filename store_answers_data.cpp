#include <iostream>
#include<fstream>
#include<sstream>
#include "store_questions_data.cpp"
#include "store_tags_data.cpp"
using namespace std;
class Sort{
	public:
		Sort(){}	
		
		void merge(TableEntry *arr, int low, int mid, int high)
		{
			int subArray1 = mid - low +1;
			int subArray2 = high - mid;
			
			TableEntry *leftArray = new TableEntry [subArray1];
			TableEntry *rightArray = new TableEntry [subArray2];
			
			for(int i=0;i<subArray1;i++)
			{
					leftArray[i].id = arr[low + i].id;
					leftArray[i].score = arr[low + i].score;
					leftArray[i].date = arr[low + i].date;
					leftArray[i].title = arr[low + i].title;
					leftArray[i].body = arr[low + i].body;
					leftArray[i].li = arr[low + i].li;
			}
			for(int i=0;i<subArray2;i++)
			{
					rightArray[i].id = arr[mid+1+i].id;
					rightArray[i].score = arr[mid+1+i].score;
					rightArray[i].date = arr[mid+1+i].date;
					rightArray[i].title = arr[mid+1+i].title;
					rightArray[i].body = arr[mid+1+i].body;
					rightArray[i].li = arr[mid+1+i].li;
			}
			int indexofleft = 0;
			int indexofright = 0;
			int indexofMergeArr = low;
			while(indexofleft < subArray1 && indexofright < subArray2)
			{
					if(leftArray[indexofleft].score >= rightArray[indexofright].score)
					{
						arr[indexofMergeArr].id = leftArray[indexofleft].id;
						arr[indexofMergeArr].score = leftArray[indexofleft].score;
						arr[indexofMergeArr].date = leftArray[indexofleft].date;
						arr[indexofMergeArr].title = leftArray[indexofleft].title;
						arr[indexofMergeArr].body = leftArray[indexofleft].body;
						arr[indexofMergeArr].li = leftArray[indexofleft].li;
						indexofleft++;
					}
					else
					{
						arr[indexofMergeArr].id = rightArray[indexofright].id;
						arr[indexofMergeArr].score = rightArray[indexofright].score;
						arr[indexofMergeArr].date = rightArray[indexofright].date;
						arr[indexofMergeArr].title = rightArray[indexofright].title;
						arr[indexofMergeArr].body = rightArray[indexofright].body;
						arr[indexofMergeArr].li = rightArray[indexofright].li;
						indexofright++;
					}
					indexofMergeArr++;
			}
			while(indexofleft < subArray1)
			{
					arr[indexofMergeArr].id = leftArray[indexofleft].id;
					arr[indexofMergeArr].score = leftArray[indexofleft].score;
					arr[indexofMergeArr].date = leftArray[indexofleft].date;
					arr[indexofMergeArr].title = leftArray[indexofleft].title;
					arr[indexofMergeArr].body = leftArray[indexofleft].body;
					arr[indexofMergeArr].li = leftArray[indexofleft].li;
					indexofleft++;
					indexofMergeArr++;
			}
			while(indexofright < subArray2)
			{
					arr[indexofMergeArr].id = rightArray[indexofright].id;
					arr[indexofMergeArr].score = rightArray[indexofright].score;
					arr[indexofMergeArr].date = rightArray[indexofright].date;
					arr[indexofMergeArr].title = rightArray[indexofright].title;
					arr[indexofMergeArr].body = rightArray[indexofright].body;
					arr[indexofMergeArr].li = rightArray[indexofright].li;
					indexofright++;
					indexofMergeArr++;
			}
		}
		
		void mergesort(TableEntry *arr,int low,int high)
		{
			if(low < high)
			{
				int mid = (low+high) /2;
				mergesort(arr,low,mid);
				mergesort(arr,mid+1,high);
				merge(arr,low,mid,high);
			}
		}

};


class StoreAnswers{
	public:
		fstream file;
		List l;
		string body;
		int score, parent_id;
		int j;
		int i;
		string line;
		StoreQuestions sq;
		Tags t;
		StoreAnswers(){
			t.readTags();
			file.open("Answers3.csv", ios::in);
			j=0;
			i=0;
		}	
	
		void readData(){
			int i=0;
			getline(file, line);
			while(!file.eof()){
				getline(file,line,',');
				stringstream ss(line);
				ss >> parent_id;
				if(parent_id!=l.getID())
				{
					sq.storeAnswerList(l);
					l.head=NULL;
				}
				i++;
				getline(file,line,',');
				stringstream sc(line);
				sc >> score;
				
				getline(file,line,'\n');
				for(int j=line.length()-1;j>=0;j--)
				{
					if(line[j]==',')
					{
						line[j]=' ';
					}
				}
				body=line;
				if(l.head==NULL)
					l.add_node_head(parent_id,score,body);
				else
					l.add_node_tail(parent_id,score,body);	
			}
		}
		
		
		void LinkTags(BNode *root, BST &bst)
		{
			TableEntry *temp1;
			list<int>::iterator it;
			for(it = root->id.begin(); it != root->id.end(); it++){
				bst.root = bst.insertId(bst.root, *it);
			}	
			
			
		}
		
		void storeID(BNode *root, TableEntry *arr){
			TableEntry *temp;
			if(root == NULL){
				return;
			}
			
			storeID(root->left, arr);
		
			temp = sq.t.search(root->tag_id);
			if(temp != NULL){
				arr[i].id = temp->id;
				arr[i].date = temp->date;
				arr[i].score = temp->score;
				arr[i].title = temp->title;
				arr[i].body = temp->body;
				arr[i].li = temp->li;
			}
			i++;
			storeID(root->right, arr);
			return;
		}
		
		void printData(TableEntry *arr, int i){
				sq.t.display(arr[i]);
				cout << "\n\n";
		}
		
	void searchInBst(string str){
		BST bst2;
		stringstream ss(str);
		string tags;
		int flag = 0;
		while(ss >> tags){
			BNode *n = t.bst.search(t.bst.root, tags);
			if(n != NULL){
				flag = 1;
				LinkTags(n, bst2);
			}
		}
		bst2.inorderTags(bst2.root);
		TableEntry *temp;
		int IdCount = bst2.getCount();
		
			if(IdCount == 0){
			cout << "\tNO RECORD FOUND!" << endl << endl;
			cout << "\t";
			system("pause");
			return;
			}
			
		cout << endl << "\t" << IdCount << " Records found!" << endl ;
		cout << endl << endl << "\t";
		system("pause");
		TableEntry *arr;
		arr = new TableEntry[IdCount];
		i=0;
		storeID(bst2.root, arr);
		Sort sort;
		sort.mergesort(arr, 0, IdCount-1);
	
		show_menu(IdCount,arr);
	
		
	}
	void show_menu(int IdCount,TableEntry *arr)
	{
		int opt;
		if(IdCount>=15)
		{
			IdCount=15;
		}
	
	
		do{
			system("cls");
			cout << "\n\t\t\t TITLE PAGE";
			cout<<"\n\n\tCHOOSE THE TITLE\n\t(most relevant questions selected)\n\n";
			for(int i=0;i<IdCount;i++)
			{
				cout<<"\t( "<<i+1<<" )  "<< arr[i].title <<"\n";
			}
			cout<< "\t( 0 )  Go back to home screen\n" <<endl;
			cout<<"\tSelect the title number: ";
			cin>>opt;
		}while(opt<0 || opt>IdCount);
		
		if(opt==0)
		{
			return;
		}
		opt=opt-1;
		fflush(stdin);
		system("cls");
		printData(arr, opt);
		fflush(stdin);
		system("cls");
		show_menu(IdCount,arr);
		
	}
};

