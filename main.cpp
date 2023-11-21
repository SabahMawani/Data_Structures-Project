#include <iostream>
#include <windows.h>
#include <string>
#include <cwchar>
#include <bits/stdc++.h>
#include "store_answers_data.cpp"

using namespace std;
void SetScreen(CONSOLE_FONT_INFOEX &cfi,int wx,int wy,int x)
{
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = wx;                 
	cfi.dwFontSize.Y = wy;           
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = x;
	wcscpy(cfi.FaceName, L"CALIBRI"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void loadingScreen()
{
	char y = 219;       
	for(int i=0;i<30;i++)
	{
		cout<<y;
		//controlling speed of loading gradually increasing time = 1/speed and vice versa
		if(i<10)
			Sleep(150);      //delaying for 300 ms
		else if(i<20 && i>10)
			Sleep(100);
		else
			Sleep(50);
	}
	system("cls");
}

void showLogo(){
	cout << "\n\n\t    Welcome to STACK OVERFLOW search engine.\n";
}

main(){
	system("Color 70");
	CONSOLE_FONT_INFOEX cfi;
	SetScreen(cfi,35,70,1000);
	cout<<"\n\n\t     W E L C O M E\n\n\t\t  TO\n\n\tS T A C K O V E R F L O W\n";
	
	fflush(stdin);
	getchar();
	system("Color 70");
	
	SetScreen(cfi,0,48,1000);
	system("cls");
	showLogo();
	cout << "\n\n\t\t\tLoading data...\n\n\t\t";
	loadingScreen();
	system("cls");
	SetScreen(cfi,10,25,650);
	StoreAnswers sa;
	sa.readData();
	int opt;
	string str;
	do {
		cout << "\t\t\t";
		showLogo();
		cout << "\n\tType Your Question Below\n\t==> ";
		fflush(stdin);
		getline(cin,str);
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		sa.searchInBst(str);
		system("cls");
		cout << "\t\t\t";
		showLogo();
		cout<<"\n\n\n\tPress 1 to continue\n\tPress 0 to Exit\n\t-->";
		cin>>opt;
		system("cls");
	} while(opt!=0);
	
	SetScreen(cfi,0,50,700);
	cout << "\n\n\n\tTHANK YOU for using STACKOVERFLOW\n\n\n";
	
}








