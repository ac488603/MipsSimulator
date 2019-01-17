#include "parse.h"
#include "bitset"
using namespace std;

int opCode(std::string bs)
{ // gets op code 
	string op = bs.substr(0,6);
	bitset<6> opi(op);
	return (int)opi.to_ulong(); 
}
int getrs(std::string bs)
{ // gets first sources reg
	string op = bs.substr(6,5);
	bitset<5> opi(op);
	return (int)opi.to_ulong(); 
}
int getrt(std::string bs)
{ //  gets second source reg
	string op = bs.substr(11,5);
	bitset<5> opi(op);
	return (int)opi.to_ulong(); 
}
int getrd(std::string bs)
{ //gets destination register
	string op = bs.substr(16,5);
	bitset<5> opi(op);
	return (int)opi.to_ulong(); 
}
int getshamt(std::string bs)
{	//  gets shift amount
	string op = bs.substr(21,5);
	bitset<5> opi(op);
	return (int)opi.to_ulong(); 	
}
int getfunc(std::string bs)
{	//gets function code 
	string op = bs.substr(26,6);
	bitset<6> opi(op);
	return (int)opi.to_ulong(); 
}
int getoffset(std::string bs)
{// gets offset in I-type instructions
	string op = bs.substr(16,16);
	bitset<16> opi(op);
	return (int)opi.to_ulong();
}
int getaddress(std::string bs)
{	//gets address for j-type instructions
	string op = bs.substr(6,26);
	bitset<26> opi(op);
	return (int)opi.to_ulong(); 
}