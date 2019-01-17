#ifndef ops_h
#define ops_h
#include <string>
///////////////////////////////////////R-type Instructions////////////////////////////////
void sll(int rd, int source, unsigned int shift);
void srl(int rd, int source, unsigned int shift);
void sra(int rd, int source,  int shift);
void sllv(int rd, int source1, int source2 );
void srlv(int rd, int source1, int source2 );
void srav(int rd , int source1, int source2);
void movn(int rd , int source1, int source2);  
void movz(int rd , int source1, int source2);
void syscall();
void mfhi(int rd);
void mthi(int rd);
void mflo(int rd);
void mtlo(int rd);
void mult(int source1, int source2);
void multu(int source1, int source2); 
void Div(int source1, int source2);
void divu(int source1, int source2); 
void add(int rd, int source1, int source2);
void addu(int rd, int source1, int source2);
void sub(int rd, int source1, int source2); 
void subu(int rd, int source1, int source2);
void And(int rd, int source1, int source2);  
void Or	(int rd,  int source1, int source2); 
void Xor(int rd,  int source1, int source2);
void nor(int rd,  int source1, int source2);
void slt(int rd, int source1, int source2);
void sltu(int rd, int source1, int source2);

/////////////////////////////////////I-type Instructions////////////////////////////////

void beq(int source1, int source2,  int offset);
void bne(int source1, int source2,  int offset);
void blez(int source1,  int offset);
void bgtz(int source1,  int offset);
void addi(int rd, int source1,  int offset);
void addiu(int rd, int source1,  unsigned int offset);
void slti(int rd, int source1,  int offset);
void sltiu(int rd, int source1,  unsigned int offset);
void andi(int rd, int source1,  int offset);
void ori(int rd, int source1,  int offset);
void xori(int rd, int source1,  int offset);
void lui(int rd, int offset);
void lb(int rd, int offset, int base);
void lh(int rd, int offset, int base);
void lw(int rd, int offset, int base);
void sb(int rd, int offset, int base);
void sh(int rd, int offset, int base);
void sw(int rd, int offset, int base);

////////////////////////////  j-type instructions ////////////////////////////////
void j(int target);
//////////////////////////////// Misc /////////////////////////////////////////////
int locateAddress (int n);
int byteToInt(std::string bs);
int halfToInt(std::string bs);  //load word conversions...
int wordToInt(std::string bs);

#endif