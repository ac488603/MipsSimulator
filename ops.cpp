#include "ops.h"
#include "register.h"
#include <iostream>
#include <bitset>
using namespace std; 

// need to add error checking 


//////////////////////////////////////////////////////////////R-type Instructions /////////////////////////////////////////////////////////////////
void sll(int rd, int source, unsigned int shift)
{	//unsigned 
	unsigned int value;
	if (source < 32)
		value = registers[source].getData();
		
		registers[rd].setData( value << shift );
}
void srl(int rd, int source, unsigned int shift)
{ // unsigned 
	unsigned int value;
	if (source < 32)
		value = registers[source].getData();
	
		registers[rd].setData( value >> shift );
}
void sra(int rd, int source, int shift)
{// signed bit shifted in
	int value;
	if (source < 32)
		value = registers[source].getData();
	
		registers[rd].setData( value >> shift );	
}
void sllv(int rd, int source1, int source2 )
{// zeros shifted in
	unsigned int value1, value2; 
	if (source1 < 32)
		value1 = registers[source1].getData();
	if (source2 < 32)
		value2 = registers[source2].getData();
	
		registers[rd].setData( value1 << value2 );
}
void srlv(int rd, int source1, int source2 )
{// zeros shifted in 
	unsigned int value1, value2; 
	if (source1 < 32)
		value1 = registers[source1].getData();
	if (source2 < 32)
		value2 = registers[source2].getData();
	
		registers[rd].setData( value1 >> value2 );
}
void srav(int rd , int source1, int source2)
{	// shifts signed bit
	int value1, value2; 
	if (source1 < 32)
		value1 = registers[source1].getData();
	if (source2 < 32)
		value2 = registers[source2].getData();
	
		registers[rd].setData( value1 >> value2 );
}


void movn(int rd , int source1, int source2)
{//move if value of rt is not zero 
		int value1, value2; 
	if (source1 < 32)
		value1 = registers[source1].getData();
	if (source2 < 32)
		value2 = registers[source2].getData();
	if(value2 != 0)
		registers[rd].setData(value1);
}
void movz(int rd , int source1, int source2)
{ // move if value of rt is zero
		int value1, value2; 
	if (source1 < 32)
		value1 = registers[source1].getData();
	if (source2 < 32)
		value2 = registers[source2].getData();
	if(value2 == 0)
		registers[rd].setData(value1);	
}
void syscall()
{
	if(registers[2].getData() == 1)
	{
		//print_int	1	$a0 = integer to be printed
		 int value = registers[4].getData();
		 cout << value << endl; 
	}
	else if(registers[2].getData() == 4)
	{
		//print_string	4	$a0 = address of string in memory
	}
	else if(registers[2].getData() == 5)
	{
		//read_int	5	integer returned in $v0
		int userInput;
		cin >> userInput;
		registers[2].setData(userInput);
	}
	else if(registers[2].getData() == 8)
	{
			//	read_string	8	"$a0 = memory address of string input buffer $a1 = length of string buffer (n)"
	}
	else if (registers[2].getData() == 10)
	{
			//exit	10	
	}
}	
void mfhi(int rd)
{//move from $HI
	registers[rd].setData(special[0].getData());
}
void mthi(int rd)
{//from rd to $HI
	special[0].setData(registers[rd].getData());
}
void mflo(int rd)
{//move from $LO
	registers[rd].setData(special[1].getData()); 
}
void mtlo(int rd)
{ //from rd to $LO
	special[1].setData(registers[rd].getData());
}

void mult(int source1, int source2)
{// stores result in $LO,signed
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();
	special[1].setData(value1 * value2);
}
void multu(int source1, int source2)
{ // stores result in $LO, unsigned 
	unsigned int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();
	special[1].setData(value1 * value2);
}
void Div(int source1, int source2)
{//signed division, remainder stored in $HI, quotient stored in $LO 
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

	special[1].setData(value1 / value2);
	special[0].setData(value1 % value2);	
}
void divu(int source1, int source2)
{//unsigned division, remainder stored in $HI, quotient stored in $LO 
	unsigned int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

	special[1].setData(value1 / value2);
	special[0].setData(value1 % value2);
} 

void add(int rd, int source1, int source2)
{ //  normal addition 
int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 + value2); 
}
void addu(int rd, int source1, int source2)
{ // unsigned addition
	unsigned int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 + value2); 
}
void sub(int rd, int source1, int source2)
{// normal subtraction
int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 - value2); 	
}
void subu(int rd, int source1, int source2)
{ //  unsigned subtraction
unsigned int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 - value2); 	
}


void And(int rd, int source1, int source2)
{ // bitwise and
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 & value2); 
}
void Or(int rd, int source1, int source2)
{  // bitwise or 
int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 | value2); 		
}
void Xor(int rd,  int source1, int source2)
{ // exclusive or 
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData(value1 ^ value2);
}
void nor(int rd,  int source1, int source2)
{   // bitwise not and bitwise or
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32)
	registers[rd].setData( ~(value1 | value2 ));
}
void slt(int rd, int source1, int source2)
{ // set on less than 
int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32){
	if(value1 < value2)
		registers[rd].setData(1);
	else 
		registers[rd].setData(0);  	
}
}
void sltu(int rd, int source1, int source2)
{//unsigned set on less than 
unsigned int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(rd < 32){
	if(value1 < value2)
		registers[rd].setData(1);
	else 
		registers[rd].setData(0);  	
}
}

//////////////////////////////////////////////////// I-type Instructions  ////////////////////////////////////
void beq(int source1, int source2,  int offset)
{
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();
if(value1 == value2)
{
		int anw = (text[programCounter].getAddress() + offset) - 4;
        programCounter = locateAddress(anw); 
}
}
void bne(int source1, int source2,  int offset)
{
		int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
	
if(source2 < 32)
	value2 = registers[source2].getData();

if(value1 != value2)
{
		int anw = (text[programCounter].getAddress() + offset) - 4;
        programCounter = locateAddress(anw); 
}
}
void blez(int source1,  int offset)
{
	int value1;  
if (source1 < 32)
	value1 = registers[source1].getData();

if(value1 <= 0)
{
		int anw = (text[programCounter].getAddress() + offset) - 4;
        programCounter = locateAddress(anw); 
}
}
void bgtz(int source1,  int offset)
{
	int value1;  
if (source1 < 32)
	value1 = registers[source1].getData();

if(value1 > 0)
{
		int anw = (text[programCounter].getAddress() + offset) - 4;
        programCounter = locateAddress(anw); 
}	
}
void addi(int rd, int source1,  int offset)
{
	int value1;
if (source1 < 32)
	value1 = registers[source1].getData();
if(rd < 32)
	registers[rd].setData(offset + value1);

}
void addiu(int rd, int source1,  unsigned int offset)
{
	unsigned int value1;
if (source1 < 32)
	value1 = registers[source1].getData();
if(rd < 32)
	registers[rd].setData(offset + value1);
}
void slti(int rd, int source1,  int offset)
{
 int value1;
if (source1 < 32)
	value1 = registers[source1].getData();
if(value1 < offset)
	registers[rd].setData(1);
else 
	registers[rd].setData(0);
}
void sltiu(int rd, int source1,  unsigned int offset)
{
	 unsigned int value1;
if (source1 < 32)
	value1 = registers[source1].getData();
if(value1 < offset)
	registers[rd].setData(1);
else 
	registers[rd].setData(0);
}
void andi(int rd, int source1,  int offset)
{
	int value1, value2;  
if (source1 < 32)
	value1 = registers[source1].getData();
if(rd < 32)
	registers[rd].setData(value1 & offset); 
}
void ori(int rd, int source1,  int offset)
{
	int value1;  
if (source1 < 32)
	value1 = registers[source1].getData();
if(rd < 32)
	registers[rd].setData(value1 | offset); 
}
void xori(int rd, int source1,  int offset)
{
	int value1; 
if (source1 < 32)
	value1 = registers[source1].getData();

if(rd < 32)
	registers[rd].setData(value1 ^ offset);
}
void lui(int rd, int offset)
{
	if(rd < 32)
	registers[rd].setData(offset);
}
void lb(int rd, int offset, int base)
{
	if(base == 29)
	{
		int index =  offset; // each element is one word, 24($sp)== 6th instruction
		string bs =  stack[index]; 
		int data  =  halfToInt(bs);
		registers[rd].setData(data);
	}
	else
	{
		int index =  offset;  //each element a byte
		string bs1 =  data[offset].getData();
		string bs2 =  data[offset+1].getData();
		string bs = bs1 + bs2; 
		int data = halfToInt(bs);
		registers[rd].setData(data);
	}
}
void lh(int rd, int offset, int base)
{
	
	if (base == 29)
	{
		// use stack ....
		int index =  offset; // each element is one word, 24($sp)== 6th instruction
		string bs =  stack[index]; 
		string bs1 = stack[index+1];
		string store = bs + bs1;
		int data  =  halfToInt(store);
		registers[rd].setData(data);
		}
	else
	{
		int index =  offset;  //each element a byte
		string bs1 =  data[offset].getData();
		string bs2 =  data[offset+1].getData();
		string bs = bs1 + bs2; 
		int data = halfToInt(bs);
		registers[rd].setData(data);
	}
}
void lw(int rd, int offset, int base)
{
	if (base == 29)
	{
		// use stack ....
		int index =  offset; // each element is one word, 24($sp)== 6th instruction
		string bs =  stack[index];  // byte1
		string bs1 = stack[index+1]; // byte2
		string bs2 = stack[index+2]; // byte3
		string bs3 = stack[index +3]; //byte4
		string store = bs + bs1 + bs2 + bs3; // 32 bit string 
		int data  =  wordToInt(store); // convert to integer and store 
		registers[rd].setData(data); 
	}
	else
	{
		int baseAddr = registers[base].getData();
		int addr = offset + baseAddr;
		int index =  (addr - baseAddr); // each element is a byte 24($sp) == 24 byte or first byte of 6th instruction
		string bs1 =  data[index].getData();  //first byte
		string bs2 =  data[index+1].getData(); //second byte
		string bs3 =  data[index+2].getData(); //third byte
		string bs4 =  data[index+3].getData(); //fourth byte 
		string bs =  bs1 + bs2 + bs3 + bs4 ;  // binary string 
		int data = wordToInt(bs);
		registers[rd].setData(data);
	}
}
void sb(int rd, int offset, int base)
{
		if (base == 29)
	{
		int data = registers[rd].getData(); 
		bitset<8> binary(data); // store a byte
		string bs = binary.to_string();
		int index =  offset;
		stack[index] = bs;
	}
	else
	{
		int datafromreg = registers[rd].getData(); 
		bitset<8> binary(datafromreg); // store a byte
		string bs = binary.to_string();
		int baseAddr = registers[base].getData();
		int addr = offset + baseAddr;
		int index =  (addr - baseAddr);
		data[index].setData(bs);
	}
}
void sh(int rd, int offset, int base)
{
		
	if (base == 29)
	{
		// use stack ....
		int data = registers[rd].getData(); 
		bitset<16> binary(data);
		string bs = binary.to_string();
		string bs1 =  bs.substr(0,8);  //first byte
		string bs2 =  bs.substr(8,8); //second byte
		int index =  offset;
		stack[index] = bs1;
		stack[index+1] = bs2;
		}
	else
	{
		int datafromreg = registers[rd].getData(); 
		bitset<16> binary(datafromreg);
		string bs = binary.to_string();
		string bs1 =  bs.substr(0,8);  //first byte
		string bs2 =  bs.substr(8,8); //second byte
		int baseAddr = registers[base].getData();
		int addr = offset + baseAddr;
		int index =  (addr - baseAddr);
		data[index].setData(bs1);   // two bytes is a half word 
		data[index+1].setData(bs2);
	}
}
void sw(int rd, int offset, int base)
{
		if (base == 29)
	{
		// use stack ....
		int data = registers[rd].getData(); 
		bitset<32> binary(data);
		string bs = binary.to_string();
		string bs1 =  bs.substr(0,8);  //first byte
		string bs2 =  bs.substr(8,8); //second byte
		string bs3 =  bs.substr(16,8); //third byte
		string bs4 =  bs.substr(24,8); //fourth byte 
		int index =  offset;
		stack[index] = bs1;
		stack[index+1] = bs2;
		stack[index+2] = bs3;  //4 bytes is one word 
		stack[index+3] = bs4;
	}
	else
	{	
		int datafromreg = registers[rd].getData(); 
		bitset<32> binary(datafromreg);
		string bs = binary.to_string();
		string bs1 =  bs.substr(0,8);  //first byte
		string bs2 =  bs.substr(8,8); //second byte
		string bs3 =  bs.substr(16,8); //third byte
		string bs4 =  bs.substr(24,8); //fourth byte 
		int baseAddr = registers[base].getData(); // base address stored in register 
		int addr = offset + baseAddr;
		int index =  (addr - baseAddr);
		data[index].setData(bs1);
		data[index+1].setData(bs2);
		data[index+2].setData(bs3);
		data[index+3].setData(bs4);
	}
}

//////////////////////////////////////////////////j-type ///////////////////////////////////
void j(int target)
{
	int currentaddr = (((programCounter)*4)+ startText);
	bitset<32> binary(currentaddr);
	string convert = binary.to_string();
	string bits4 = convert.substr(0,4); //  top 4 of program counter 
	bitset<28> targ(target);			
	string bottomBits = targ.to_string(); // convert address to binary 
	string address =  bits4 + bottomBits;  // concatenate top from of program counter to 28 bit offset;
	bitset<32> addr(address);
	 programCounter = locateAddress((int)addr.to_ulong());
}
///////////////////////////////////////////////////////////////misc ////////////////////////////
int locateAddress (int n)
{  
	return ((n-startText)/4);  
}
int byteToInt(string bs)
{ 
	bitset<8> opi(bs);
	return (int)opi.to_ulong(); 
}
int halfToInt(string bs)
{ 
	bitset<16> opi(bs);
	return (int)opi.to_ulong(); 
}
int wordToInt(string bs)
{ 
	bitset<32> opi(bs);
	return (int)opi.to_ulong(); 
}
