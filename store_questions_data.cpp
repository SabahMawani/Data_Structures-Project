#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "hash_table.cpp"

using namespace std;

class StoreQuestions{
	public:
		string line, date, title, body;
		int question_id, score; 
		HashTable t;
		fstream q_ptr;
		
		StoreQuestions(){
			q_ptr.open("Questions3.csv",ios::in);	
			question_id=0;
			score=0;
			readQuestions();
		}
		
		void storeAnswerList(List li){
			t.insertAnswers(li);
		}
		
		void readQuestions(){
			getline(q_ptr, line);
			while(!q_ptr.eof())
			{
				getline(q_ptr,line,',');
				stringstream ss(line);
				ss >> question_id;
				getline(q_ptr,line,',');
				date=line;
				getline(q_ptr,line,',');
				stringstream sc(line);
				sc >> score;
				getline(q_ptr, line, ',');
				title = line;
				getline(q_ptr, line, '\n');
				for(int i=line.length()-1;i>=0;i--)
				{
					if(line[i]==',')
					{
						line[i]=' ';
					}
				}
				body=line;
				t.insert(question_id,title,date,body,score);
			}
			q_ptr.close();
		}
			
};









