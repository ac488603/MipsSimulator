#ifndef parse_h
#define parse_h
#include <string>


int opCode(std::string bs); 
int getrs(std::string bs);
int getrt(std::string bs);
int getrd(std::string bs);
int getshamt(std::string bs); 
int getfunc(std::string bs);
int getaddress(std::string bs);
int getoffset(std::string bs);

#endif