#include <card1/card1.hpp>
#include <eoslib/print.hpp>

namespace card
{
	using namespace eos;

	void sendMsg(const card::Message& msg){
		print(&msg.name);
		printi(msg.count);
		print("\n");
	}
}

using namespace card;

extern "C"{
   
	void init(){

	}

	void apply(uint64_t code, uint64_t action){
		if(code == N(card)){
			if(action == N(start)){
				card::sendMsg(currentMessage< card::Message >());
			}
		}
	}
}