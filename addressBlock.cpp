#include "addressBlock.h"
using namespace std; 

void addressBlock::setAddress(int s)
{
	address = s; 
}

void addressBlock::setData(string s)
{
	data = s;  
}

string addressBlock::getData()
{
	return data;
}

int addressBlock::getAddress()
{
	return address; 
}