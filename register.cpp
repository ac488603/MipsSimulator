#include "register.h"

using namespace std; 
// start address of text segment
// each instruction takes 32 bit so
// 1 hex digit is one byte so one instuction is every 4 bytes 
// + 4 to get to next instruction  
int startText = 0x00400000;
vector<addressBlock> text;  

//start address of data segment
//each index of element is 1  
// next data is + 1 
int startData = 0x10010000;
vector<addressBlock> data; 

//start address of stack data 
// starts at high address grows down 
// everything on stack is 32 bits, 4 bytes  
//next thing on stack is -4 , previous is + 4
// first addressable address is at 0x7fffeffc
int startStack =  0x7fffefff;   // stack is empty at this position
vector<string> stack;  

// program counter 
int programCounter = 0;  

//compile using -std=c++11 
//initializing register names 
registerInfo registers[32] = {
								{"$zero"}, // 0
								{"$at"}, //1
								{"$v0"},{"$v1"}, // 2-3 
								{"$a0"},{"$a1"},{"$a2"},{"$a3"}, //4-7
								{"$t0"},{"$t1"},{"$t2"},{"$t3"},{"$t4"},{"$t5"},{"$t6"},{"$t7"}, //8-15
								{"$s0"},{"$s1"},{"$s2"},{"$s3"},{"$s4"},{"$s5"},{"$s6"},{"$s7"},//16-23
								{"$t8"},{"$t9"}, // 24-25
								{"$k0"},{"$k1"}, // 26-27
								{"$gp"}, // 28
								{"$sp"}, // 29
								{"$fp"}, //30
								{"$ra"}}; //31 

registerInfo special[2] = {
	{"$HI"},{"$LO"}
};