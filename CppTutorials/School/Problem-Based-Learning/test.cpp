#include <iostream>
#include <fstream>
#include<string>
#include<windows.h>
#include<iomanip>
using namespace std;
void menuScreen();
void displayMenuScreen();
void showMenu(string code[], string name[], string price[], int n);
void displayMenu(int page, int maxpage, int min, int max,string code[], string name[], string price[]);

int main(){
	menuScreen();
	system("pause");
	return 0;
}

void menuScreen(){
	string fcode[999];
	string fname[999];
	string fprice[999];
	string bcode[999];
	string bname[999];
	string bprice[999]; //9999 will crash the program. probably because lack of memory
	int nFood = 0, nBev = 0;
	int selection;
	ifstream fReader;
	fReader.open("Resource//Menu//Food.txt");
	while(!fReader.eof()){
		fReader >>fcode[nFood] >>fname[nFood] >>fprice[nFood];
		nFood++;
	}
	fReader.close();
	ifstream bReader;
	bReader.open("Resource//Menu//Beverage.txt");
	while(!bReader.eof()){
		bReader >>bcode[nBev] >> bname[nBev] >>bprice[nBev];
		nBev++;
	}
	bReader.close();
	displayMenuScreen();
	cin >>selection;
	while(cin.fail()||!(selection==1||selection==2||selection==0)){
		displayMenuScreen();
		cin>>selection;
	}
	switch(selection){
	case 1:
		showMenu(fcode,fname,fprice,nFood);
		break;
	case 2:
		showMenu(bcode,bname,bprice,nBev);
		break;
	case 0:
		cout <<"Exiting..." <<endl;
		Sleep(1000);
		break;
	}
}

void showMenu(string code[], string name[], string price[], int n){
	bool done = false;
	int selection;
	int min = 0, max = 15;
	int page = 1;
	int maxpage = n/15;
	if(maxpage ==0){
		maxpage = 1;
	}else{
		if(n%15 != 0){
			maxpage++;
		}
	}
	while(!done){
		displayMenu(page,maxpage,min,max,code,name,price);
		cin>>selection;
		while(cin.fail()||!(selection==1||selection==2||selection==0)){
			displayMenu(page,maxpage,min,max,code,name,price);
			cin>>selection;	
		}
		switch(selection){
		case 1:
			if(page-1==0){
				min = 0;
				max = 15;
				page = 1;
			}else{
				min-=15;
				max-=15;
				page -=1;
			}
			break;
		case 2:
			if(page+1>maxpage){
				page = maxpage;
			}else{
				min+=15;
				max+=15;
				page+=1;
			}
			break;
		case 0:
			done = true;
			menuScreen();
			break;
		}
	}
}

void displayMenu(int page, int maxpage, int min, int max,string code[], string name[], string price[]){
	system("cls");
	cout <<"*************************" <<endl;
	cout <<"Jayztech Restaurant Menu:" <<endl;
	cout <<"*************************" <<endl;
	cout <<fixed <<left <<setprecision(2);
	cout <<"Showing page " << page << " of " <<maxpage <<endl;
	cout <<setw(5) <<"Code" <<setw(50)<<"Name" <<right <<setw(6) << "Price" <<endl;
	for(min; min <max; min++){
		cout <<left <<setw(5) <<code[min] <<setw(50) <<name[min] <<right <<setw(6) <<price[min] <<endl;
	}
	cout <<"*****************************" <<endl;
	cout <<"1. Previous Page" <<endl;
	cout <<"2. Next Page" <<endl;
	cout <<"0. return" <<endl;
}

void displayMenuScreen(){
	system("cls");
	cout <<"*************************" <<endl;
	cout <<"Jayztech Restaurant Menu:" <<endl;
	cout <<"*************************" <<endl;
	cout <<"Select Menu" <<endl;
	cout <<"1. Food Menu" <<endl;
	cout <<"2. Beverages Menu" <<endl;
	cout <<"0. return" <<endl;
	cout <<"Selection: ";
}