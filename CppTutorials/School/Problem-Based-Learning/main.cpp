#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include<direct.h>
using namespace std;
void loginScreen();
void doLogin();
void addUser();
void logOut();
void employeeScreen(string user, string permissionName);
void adminScreen(string user, string permissionName);
void employeeSelection(int option, string user, string permissionName);
void takeOrder(string user, string permissionName);
void closeOrder();
void modifyOrder();
void showMenu();

int main(){
	loginScreen();
	cout <<"Press Enter to Continue";
	cin.ignore();
	cin.get();
	return 0;
}

void doLogin(){
	string userIn, passIn, user, pass, permissionName;
	int permission;
	int loginStatus;
	ifstream reader;
	reader.open("Resource//Login//User.txt");
	if(!reader){
		cout <<"WARNING FILE NOT FOUND" <<endl;
		cout <<"executing admin mode" <<endl;
		adminScreen("DEBUG","DEBUG");
	}
	cout << "Username: ";
	cin>>userIn;
	cout << "Password: ";
	cin >>passIn;
	while(true){
		reader >>user >>pass >>permission;
		if(!(user.compare(userIn)) && !(pass.compare(passIn))){
			loginStatus = 1;
			break;
		}
		if(reader.eof()){
			loginStatus = 2;
			break;
		}
	}
		switch(loginStatus){
		case 1:
			Sleep(1000);
			cout <<"Login Success" <<endl
					<<"Welcome " <<userIn <<endl;
			Sleep(1000);
			break;
		case 2:
			Sleep(1000);
			cout <<"Invalid username or password" <<endl;
			Sleep(1000);
			loginScreen();
			break;
		}//end of login

		//Enter screen depending on permission
		switch(permission){
		case 1:
			permissionName = "EMPLOYEE";
			employeeScreen(user,permissionName);
			break;
		case 2:
			//adminScreen(user,permissionName);
			break;
		}
}

void employeeScreen(string user, string permissionName){
	int option;
	system("cls");
	cout <<"Jayztech Restaurant Management System" <<endl;
	cout <<"Welcome " <<user <<". You are logged in as " <<permissionName <<endl;
	cout <<"---------------------------------" <<endl;
	cout <<"Please select option" <<endl
			<<"1. Take Order" <<endl
			<<"2. Close Order" <<endl
			<<"3. Modify Order" <<endl
			<<"4. Show Menu" <<endl
			<<"5. Logout" <<endl
			<<"---------------------------------" <<endl;
	cout <<"Option: ";
	cin>>option;
	while(cin.fail()){
		cin.clear();
		cin.ignore();
		employeeScreen(user, permissionName);
	}
	employeeSelection(option, user, permissionName);
}

void loginScreen(){
	system("cls");
	cout <<"Welcome to Jayztech Restaurant Management System" <<endl
			<<"Please Login" <<endl;
	doLogin();
}

void employeeSelection(int option, string user, string permissionName){
	switch(option){
	case 1:
		takeOrder(user, permissionName);
		break;
	case 2:
		//closeOrder();
		break;
	case 3:
		//modifyOrder();
		break;
	case 4:
		//showMenu();
		break;
	case 5:
		logOut();
		break;
	default:
		cout <<"Incorrect Input" <<endl;
		Sleep(1000);
		employeeScreen(user,permissionName);
	}
}

void takeOrder(string user, string permissionName){
	int table, customer;
	ofstream order;
	system("cls");
	cout <<"Jayztech Restaurant Management System" <<endl;
	cout <<"Welcome " <<user <<". You are logged in as " <<permissionName <<endl;
	cout <<"---------------------------------" <<endl;
	cout <<"Table: ";
	cin >>table;
	while(cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout <<"Please input Number";
		cout <<"Table: ";
		cin >>table;
	}
	cout <<"Number of Customers: ";
	cin>>customer;
}

void logOut(){
	cout <<"Logging Out....." <<endl;
	Sleep(2000);
	loginScreen();
}

void addUser(){
		string user[9999];
		string pass[9999];
		string permission[9999];
		int numElements = 0;
		string userIn, passIn;
		int permissionIn;
		char check;
		ifstream reader;
		reader.open("Resource//Login//User.txt");
		if(!reader){
			cout <<"File not found" <<endl <<"Making new file...."<<endl;
			ofstream makeFile;
			int check = _mkdir("Resource");
			check = _mkdir("Resource//Login");
			makeFile.open("Resource//Login//User.txt");
			makeFile.close();
			if(check == 0){
				cout <<"File successfully made" <<endl;
			}
		}else{
			while(!reader.eof()){
				reader >>user[numElements] >>pass[numElements] >>permission[numElements];
				numElements++;
			}
		}
		reader.close();
		cout <<"Adding user system" <<endl;
		cout <<"Enter username: ";
		cin >> userIn;
		cout <<"Enter password: ";
		cin >> passIn;
		cout <<"1 for employee 2 for admin" <<endl;
		cin >>permissionIn;
		while(cin.fail()||!(permissionIn == 1||permissionIn ==2)){
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout <<"1 for employee 2 for admin" <<endl;
			cin>>permissionIn;
		}
		cout <<"Adding username: " <<userIn <<" with password: " <<passIn <<" with permission " <<permissionIn <<endl;
		cout <<"Enter Y to continue, anything to cancel the program" <<endl;
		cin >>check;
		if(toupper(check) == 'Y'){
			ofstream writer;
			writer.open("Resource/Login/User.txt");
			for(int x = 0; x <numElements; x++){
				writer << user[x] <<" " << pass[x] <<" " <<permission[x] <<endl;
			}
			writer << userIn <<" " << passIn<<" " <<permissionIn;
			writer.close();
			cout <<"Operation successful";
		}else{
			cout <<"operation cancelled" <<endl;			
		}
}

void showMenu(){
	string fcode[99999];
	string fname[99999];
	double fprice[99999];
	string bcode[99999];
	string bname[99999];
	double bprice[99999];
	ifstream fReader;
	fReader.open("Resource//Menu//Food.txt");
	//not done yet

}
