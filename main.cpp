//
//  main.cpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 02/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

// I will see at the end which class should be included here
#include "AI.hpp"

int main(int argc, const char * argv[]) {
	// int z = 2;
	// for(size_t i = 0 ; i < 2*topology[z + 1 ] ; i++){
	// std::cout<<"topology : "<<i<<"\n";} 
	AI obj;
#if TEST == false 
   // train 
	obj.train_AI();    
#else
   // test 
	obj.test_AI();
#endif 
}


// when I have time I have to code back pro and test it rigorously  
// and also unite everything together

// To do for the future 

// create a replay buffer class and the related components 
// create a multi-threaded function to call epoch with replay buffers with perhaps a large batch size but I have pay attention to the alive variable 

// when you will have finished try to implement it for different tic tac toe rules like the game NOTAKTO 
