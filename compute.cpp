#include <string>
#include <iostream>
#include <sstream> 
#include <bitset>
#include "compute.h"
#include "parse.h"
#include "ops.h"
#include "register.h"

using namespace std;

void executeOne()
{
	if(programCounter < text.size())
	compute();  
	else 
	cout << "no more Instructions" << endl;  
}
void executeAll()
{
// execute until reach end of data vector 
if(programCounter < text.size())
{
	while(programCounter < text.size())
	compute(); 
} 
	else 
	cout << "no more Instructions" << endl;  
}
 
void compute(){
	string bs = text[programCounter].getData(); 	// get binary string
	programCounter++;
	int opcode = opCode(bs);
	int rs    =  getrs(bs);
	int rt    =  getrt(bs);
	int func  =  getfunc(bs);
	int test;
	stringstream ss;
	ss << bs;  ss >> test;
	cout << dec << opcode << " " << func << endl;  
	if (opcode == 0) // r-type instruction
	{
		//parse string and convert
		int rd    =  getrd(bs);
		int shamt =  getshamt(bs);
		int address = getaddress(bs);
	if (test!=0){	 //  noOp encoding is all zero.  
		switch(func){
			
			case 0:
				//sll
				cout << "sll " << registers[rd].getName() << " " << registers[rt].getName() << " " << shamt << endl;  
				break; 
			case 2:
				//srl
				cout << "srl " << registers[rd].getName() << " " << registers[rt].getName() << " " << shamt << endl;
				break;
			case 3:
				//sra
				cout << "sra " << registers[rd].getName() << " " << registers[rt].getName() << " " << shamt << endl;
				break; 
			case 4: 
				//sllv
				cout << "sllv " << registers[rd].getName() << " " << registers[rt].getName() << " " << registers[rs].getName() << endl;
				break; 
			case 6:
				//srlv
				cout << "srlv " << registers[rd].getName() << " " << registers[rt].getName() << " " << registers[rs].getName() << endl;
				break; 
			case 7:
				//srav
				cout << "srav " << registers[rd].getName() << " " << registers[rt].getName() << " " << registers[rs].getName() << endl;
				break;
			case 8:
				//jr
				cout << "jr " << address << endl;
				break;
			case 9:
				//jalr
				cout << "jalr " << address << endl;  
				break;
			case 10:
				cout << "Movz " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				//movz
				break;  
			case 11:
				//movn 
				cout << "movn " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break; 
			case 12:
				//syscall
				cout << "SYSCALL" << endl;  
				break;  
			case 16:
				//mfhi
				cout << "mfhi " << registers[rd].getName() << endl;
				break;
			case 17:
				//mthi
				cout << "mthi " << registers[rd].getName() << endl;
				break;
			case 18:
				//mflo 
				cout << "mflo " << registers[rd].getName() << endl;
				break;
			case 19:
				//mtlo
				cout << "mtlo " << registers[rd].getName() << endl;
				break; 
			case 24: 
				//mult
				cout << "mult "<< registers[rs].getName() << " " << registers[rt].getName() << endl;
				break; 
			case 25: 
				//multu
				cout << "multu "<< registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 26:
				//div 
				cout << "div "<< registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 27: 
				//divu
				cout << "divu "<< registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 32:
				//add 
				cout << "add " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 33:
				//addu 
				cout << "addu " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 34:
				//sub
				cout << "sub " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;
			case 35:
				//subu
				cout << "subu " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;
			case 36:
				//and
				cout << "and " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 37:
				//or
				cout << "or " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 38:
				//xor
				cout << "xor " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break; 
			case 39:
				//nor
				cout << "nor " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 42:
				//slt
				cout << "slt " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break;  
			case 43:
				//sltu
				cout << "sltu " << registers[rd].getName() << " " << registers[rs].getName() << " " << registers[rt].getName() << endl;
				break; 
			default:
				cout << "UNKNOWN OPCODE " << endl; 
				break;
			
		}	
	}
	}
	else if (opcode == 2 || opcode ==  3) // j-type instructions  
	{
		// parse string
		int address =  getaddress(bs);
		address = address << 2;  
		if( opcode == 2)
		{
			cout << "j " << address << endl;
		}
		else 
		{
			cout << "jal " << address << endl;  
		}	
	}
	else // i-type instruction  (op code not zero)
	{
		// parse string 
		int offset =  getoffset(bs); 
		int addr;  

	switch(opcode)
	{ 
		case 4:
		//beq 
		offset = offset << 2;
		cout << "beq "<< registers[rs].getName() << " " << registers[rt].getName()<< " " << offset << endl;  
			break;
		case 5:
		//bne
		offset = offset << 2;
		cout << "bne "<< registers[rs].getName() << " " << registers[rt].getName()<< " " << offset << endl;
			break;  
		case 6:
			//blez
		offset = offset << 2;
		cout << "blez "<< registers[rs].getName() << " " << offset << endl;
			break;
		case 7:
			//bgtz
			cout << "bgtz "<< registers[rs].getName() << " " << offset << endl;
			break;  
		case 8:
			//addi
			cout << "addi " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;  
 			break;  
		case 9:
			//addiu 
			cout << "addiu " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break;  
		case 10:
			//slti
			cout << "slti " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break; 
		case 11:
			//sltiu
			cout << "sltiu " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break;
		case 12:
			//andi 
			cout << "andi " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break;
		case 13:
			//ori 
			cout << "ori " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break; 
		case 14:
			//xori
			cout << "xori " << registers[rt].getName() << " " << registers[rs].getName() << " " << offset << endl;
			break;  
		case 15:
			//lui
			offset = offset << 16;  
			cout << "lui " << registers[rt].getName() << " " << offset << endl;
			break; 
		case 32:
			//lb
			cout << "lb " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break;
		case 33:
			//lh
			cout << "lh " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break;
		case 34:
			//lwl
			//do not implement 
			break; 
		case 35:
			//lw
			cout << "lw " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			addr =  (offset/4);
			cout << "address" << addr << endl; 
			break;  
		case 36:
			//lbu
			cout << "lbu " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break;  
		case 37:
			//lhu
			cout << "lhu " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break;  
		case 38:
			//lwr
			//do not implement 
			break;
		case 40:
			//sb
			cout << "sb " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break;
		case 41:
			//sh
			cout << "sh " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break; 
		case 42:
			//swl
			//do not implement 
			break;  
		case 43:
			//sw
			cout << "sw " << registers[rt].getName() << " "<< offset << "(" << registers[rs].getName()<< ")" << endl;
			break; 
		case 46:
			//swr
			//do not implement
			break;  
		default: 
			//  some error message
				break; 
	}
	}
}