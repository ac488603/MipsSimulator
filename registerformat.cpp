#include "registerformat.h"
using namespace std; 
	
	registerInfo::registerInfo()
	{
		
	}	
	registerInfo::registerInfo(std::string s)
	{
		regName = s;  
	}	
	void registerInfo::setName(string s)
	{
		regName = s;
	}
	void registerInfo::setData(int d)
	{
		data = d;
	}
	string registerInfo::getName()
	{
		return regName; 
	}
	int registerInfo::getData()
	{
		return data; 
	}
	
	