#include <iostream>
#include "register.h"
#include "load.h"

using namespace std;

int main(int argc, char** argv)
{
	load(argv);
	
	for(int i = 0;  i < text.size();  i++)
	{
		cout << hex << text[i].getAddress() << " " << text[i].getData() << endl;
	}
	cout << "Data Segment" << endl;  
	for(int i =0;  i < data.size(); i++)
	{
		cout << hex << data[i].getAddress() << " " << data[i].getData() << endl; 
	}
	return 0; 
}