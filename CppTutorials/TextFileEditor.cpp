#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    		string user[9999];
		string pass[9999];
		int permission[9999];
		int numElements = 1;
		string userIn, passIn, permissionIn;
		bool done = false;
		char check;
		ifstream reader;
		reader.open("Resource//Login//User.txt");
		while(!reader.eof()){
			reader >>user[numElements] >>pass[numElements] >>permission[numElements];
			numElements++;
		}//import everything into arrays
		reader.close();
		
		cout <<"Adding user system" <<endl;
		cout <<"Enter username: ";
		cin >> userIn;
		cout <<"Enter password: ";
		cin >> passIn;
		cout <<"1 for employee 2 for admin" <<endl;
		
		while(!done){
			cin>>permissionIn;
			if(!permissionIn.compare("1")){
				done = true;
			}else if(!permissionIn.compare("2")){
				done = true;
			}else{
				cout <<"1 for employee 2 for admin" <<endl;
			}
		}
		
		cout <<"Adding username: " <<userIn <<" with password: " <<passIn <<" with permission " <<permissionIn <<endl;
		cout <<"Enter Y to continue, anything to cancel the program" <<endl;
		cin >>check;
		
		if(toupper(check) == 'Y'){
			ofstream writer;
			writer.open("Resource//Login//User.txt");
			for(int x = 1; x <=numElements; x++){
				writer << user[x] <<" " << pass[x] <<" " <<permission[x] <<endl;
			}
			writer << userIn <<" " << passIn<<" " <<permissionIn;
			writer.close();
			cout <<"Operation successful";
		}else{
			cout <<"operation cancelled" <<endl;
		}
}
