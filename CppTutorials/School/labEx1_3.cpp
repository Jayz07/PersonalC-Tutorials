// labEx1_3 page 9-15
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	//declaring all the variables needed in this program
	int ID;
	double purchaseAmount,rebate;
	char member;
	double totalRebate = 0;
	double highestRebate = 0;
	int numberOfMembers = 0;

	/*fstream = in/output file data well... you may use istream it doesnt matter.
	however, I'm not using inFile. I'm using reader. This proves that the following code
	is like declaring a variable.
	Right now I am declaring a fstream type variable with the variable name reader.*/

	ifstream reader;
	reader.open("purchase.txt"); //the reader variable opens the file purchase.txt must located in the same place where this cpp file is located

	if(!reader){ //checks if the file can be read or not. it's a fail safe design
		cout <<"Unable to read File";

	}else{ //this is where the real thing happens. if reader can read the file it will run this chunk.

		//Just basic stuff on the top of the output
		cout <<fixed <<left <<setprecision(2);
		cout <<setw(20) <<"Customer ID" << setw(20) <<"Member" <<setw(20) <<"Purchase Amount" <<setw(10) <<"Rebate" <<endl;

		/*This repeat is used to read the file. while the reader is not at the eof (end of file) it will return true and run the loop repeatedly
		until the eof is true*/

		while(!reader.eof()){
			/*this statement resembles the cin >> statement where the reader takes the input from purchase.txt
			if we were to take the ID, member and purchaseAmount from cin. it looks something like this:
			cin >> ID >> member >>purchaseAmount;
			that looks like the same thing as the code below
			*/
			reader >> ID >> member >> purchaseAmount; 

			if(member == 'Y'){ //this checks whether it is a member
				numberOfMembers++;

				if(purchaseAmount >100){//notice this if statement is nested inside the if(member == 'Y') code.
					rebate = purchaseAmount * 8.0/100;
				}else{//rebate is 0 if purhcaseAmount <100
					rebate = 0;
				}//end of if(purchaseAmount >100)
			}else{//this code is for if member equals to 'N'
				rebate = 0;
			}//end of if(member == 'Y)

			//prints out the results
			cout <<setw(20) <<ID << setw(20) <<member <<setw(20) <<purchaseAmount <<setw(10) <<rebate <<endl;

			//this happens before all the print out because this will be used outside the while() statement;

			//the following code determines the highest rebate. the highest rebate is initially set to 0. (all the way up top)
			if(rebate > highestRebate){
				highestRebate = rebate;
			}//end of if(rebate >highestRebate)

			//computes the total rebate
			totalRebate += rebate;

		}//end of while(!reader.eof()) (loop for reading the file ends here)

		//cout all the final values required for the question.
			cout <<"Total rebate = $" <<totalRebate <<endl
					<<"Highest rebate = $" <<highestRebate <<endl
					<<"Number of members = " <<numberOfMembers <<endl;

	}//end of if(!reader)

	system("pause");
	return 0;
}//end of main()
