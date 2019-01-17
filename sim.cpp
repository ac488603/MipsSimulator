#include <iostream>
#include "register.h"
#include "ops.h"
#include "addressBlock.h"
#include "load.h"
#include "parse.h"
#include "compute.h"

using namespace std; 


// compile string 
//g++ parse.cpp addressBlock.cpp register.cpp registerformat.cpp ops.cpp load.cpp sim.cpp compute.cpp -std=c++11

int main(int argc, char** argv)
{
	char userInput;
	string ui;

 //  read instructions from file 
 //  put instructions in correct array 
 //load file (static data and text data)
	load(argv);

	bool cond = true; 
	while(cond)
	{
		cout << "print: 'p'" << endl;
		cout << "Display Register: 'd'" << endl; 
		cout << "Execute single instruction: 's'" << endl;
		cout << "Execute all instructions: 'a'" << endl;
		cout << "Exit : 'e'" << endl; 
		cout << "input:"; 
		cin >> userInput; 
		cout << endl; 
		switch(userInput)
		{
			case 'p':
					cout << "reg or all " << endl; 
					cout << "input:" << endl; cin >> ui; 
					cout << endl;  
					if(ui == "all")
					{
						for(int i = 0;  i < 32; i++)
							cout << registers[i].getName() << " => " << registers[i].getData() << endl;  
					}
					else 
					{
						stringstream ss;
						int reg;
						ss << ui;ss >>reg; 
						cout << registers[reg].getName() << " => " << registers[reg].getData() << endl;
					}
				break; 
			case 'd':
				// ask user for memory address
				//print contents of memory address
				break;
			case 's':
				executeOne(); 
				break;  
			case 'a':
				executeAll(); 
				break; 
			case 'e':
				cout << "Exiting..." << endl;  
				cond = false; 
				break;  
			default: 
			// add case for exiting 
				cout << " some error message" << endl;  
		}
		cout << endl << endl;  
	}
	return 0;  
}