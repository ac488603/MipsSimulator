#include "load.h"
#include "register.h"
#include <iostream>
using namespace std;

void loadData(std::ifstream &ifs)
{	//data vector represented as bytes 
	while(!(ifs.eof())){
		string convertdata , address; 
		if(! (ifs >> address  >> convertdata))
		break;
		stringstream ss,ss1; 
		ss << hex << convertdata;  
		unsigned n;  ss >> n;  
		bitset<32> binaryNum(n); 
		ss1 << hex << address;
		int add1; ss1 >> add1;
		/// parse string and calculating address 
		int add2 = add1+ 1;
		int add3 = add1 +2;	// 4 bytes for address 
		int add4 = add1 +3;
		string bs = binaryNum.to_string();
		string byte1 = bs.substr(0,8);
		string byte2 = bs.substr(8,8);
		string byte3 = bs.substr(16,8);
		string byte4 = bs.substr(24,8);
		addressBlock temp1;
		temp1.setAddress(add1);
		temp1.setData(byte1);
		data.push_back(temp1);  
		addressBlock temp2;
		temp2.setAddress(add2);
		temp2.setData(byte2);
		data.push_back(temp2);
		addressBlock temp3;
		temp3.setAddress(add3);
		temp3.setData(byte3);
		data.push_back(temp3);
		addressBlock temp4;
		temp4.setAddress(add4);
		temp4.setData(byte4);
		data.push_back(temp4); 
	}	
}
void loadText(std::ifstream &ifs)
{
	string convert; 
	int index = 0;  
	while (!(ifs.eof()))
	{
		ifs >> convert;
		string exit = "DATA";
		/// temp fix string comparison not working  
		if(convert == exit)
		{
			ifs >> convert;
			break;
		}
		stringstream ss; 
		ss << hex << convert; 
		unsigned n; ss >> n;  
		bitset<32> binaryNum(n); 
		addressBlock temp;  
		temp.setData(binaryNum.to_string()); // store binary string as data 
		temp.setAddress(startText + (index * 4)); //  each instruction 4 bytes
		text.push_back(temp);
		index++;
	}	
}

void load(char ** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	loadText(ifs);
	loadData(ifs);
	ifs.close();
}





/*
	while(!(ifs.eof())){
		string convertdata , address; 
		if(! (ifs >> address  >> convertdata))
		break;
		stringstream ss,ss1; 
		ss << hex << convertdata;  
		unsigned n;  ss >> n;  
		bitset<32> binaryNum(n); 
		ss1 << hex << address;
		int add; ss1 >> add;  
		addressBlock temp;
		temp.setAddress(add);
		temp.setData(binaryNum.to_string());
		data.push_back(temp);  
	}	
*/