#include "Counter8bit.h"
#include "Testbench3.h"
#include"Adder.h"

SC_MODULE(CounterMain3){
	//Declare signals to be tied to the modules
	sc_clock clock;
	sc_signal<sc_logic> A_s, B_s;
	sc_signal<bool> reset_s; //enable_s;
	sc_signal<bool> error_s;
	sc_signal<sc_logic> CIN_s, SUM_s, COUT_s;
	sc_signal<sc_uint <8> > counter_out_s;
	
	Counter8bit counter;
	Adder adder;
	Testbench3 test1;

	//Instantiate Adder and Bind Ports
	SC_CTOR(CounterMain3): clock("SystemClock", 10, 0.5, true), counter("Counter1"), test1("Test1"), adder("Adder1")
	{
	  adder.A(A_s);
	  adder.B(B_s);
	  adder.Cin(CIN_s);
	  adder.sum(SUM_s);
	  adder.Cout(COUT_s);

	  counter.clock(clock);
	  counter.reset(reset_s);
	  counter.enable(error_s);
	  counter.counter_out(counter_out_s);
	  
	  //Instantiate Testbench And Bind Ports
	  //test1.enable(enable_s);
	  test1.reset(reset_s);
	  test1.clk(clock);
	  test1.error(error_s);
	  test1.TA(A_s);
	  test1.TB(B_s);
	  test1.TCin(CIN_s);
	  test1.TSum(SUM_s);
	  test1.TCout(COUT_s);

	}
};

SC_MODULE_EXPORT(CounterMain3);
