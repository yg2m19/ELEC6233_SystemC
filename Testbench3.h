#include "systemc.h" //Testbench3.h
SC_MODULE(Testbench3){
	
	sc_out<bool> reset;
	sc_out<bool> error;
	sc_in_clk clk;
	sc_out<sc_logic> TA, TB, TCin; 
	sc_in<sc_logic> TSum, TCout; 


	void testprocess(){
		reset.write(false);
		error.write(false);


		//validation code for combination 000
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_0)
		error.write(false); 
		else error.write(true); 
		

		//validation code for combination 001
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0)
		error.write(false); 
		else error.write(true); 
		
		//validation code for combination 010
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0)
		error.write(false); 
		else error.write(true); 
		
		//validation code for combination 011
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1)
		error.write(false); 
		else error.write(true); 
		
		//validation code for combination 100
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0)
		error.write(false); 
		else error.write(true); 


		//validation code for combination 101
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1)
		error.write(false); 
		else error.write(true); 

		//validation code for combination 110
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1)
		error.write(false); 
		else error.write(true); 

		//validation code for combination 111
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1); 
		wait(10, SC_NS);
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_1)
		error.write(false); 
		else error.write(true); 
	}
	SC_CTOR(Testbench3){
		SC_THREAD(testprocess);
		sensitive << clk.pos();
	}
};