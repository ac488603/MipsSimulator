#ifndef registers_h
#define registers_h

#include <vector>
#include "addressBlock.h"
#include "registerformat.h"

//32 registers
extern registerInfo registers[32];
extern registerInfo special[2];  
// instructions (text)
extern std::vector<addressBlock> text;  
//  data (static data)
extern std::vector<addressBlock> data;  
//  stack 
extern std::vector<std::string> stack; 
// program counter 
extern int programCounter;
extern int startStack;
extern int startData;
extern int startText;
#endif