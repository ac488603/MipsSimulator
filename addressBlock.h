#ifndef block_h
#define block_h
#include <string>

//used for data 
class addressBlock
{
	int address;
	std::string data;  
	public:
	std::string getData();
	int getAddress();
	void   setAddress(int s);
	void   setData(std::string  s); 
}; 

#endif