#ifndef rf_h
#define rf_h

#include <string>
class registerInfo
{
	std::string regName;
	int data;  
	public:
	registerInfo(); 
	registerInfo(std::string); 
	void setName(std::string s);
	void setData(int d);
	std::string getName();
	int getData(); 
};
#endif 