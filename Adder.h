#include"systemc.h"
SC_MODULE(Adder)
{ sc_out<sc_logic> sum, Cout; 
sc_in<sc_logic> A, B, Cin; 


void add(){ sc_logic tempC, tempD, tempE; 
tempC = A.read() & B.read(); 
tempD = A.read() ^ B.read();
tempE = Cin.read() | tempD;  //original 
sum.write(tempD ^ Cin.read());
Cout.write(tempC | tempE); 
}
SC_CTOR(Adder){ 
SC_METHOD(add); 
sensitive << A << B << Cin; 
}
}; 
