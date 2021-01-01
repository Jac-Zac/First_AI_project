//
//  main.cpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 02/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

// I will see at the end which class should be included here
#include "AI.hpp"

// int main(int argc, const char * argv[]) { // maybe I will need it in the future 
int main(){
	AI obj;
#if TEST == false 
   // train 
	obj.train_AI();    
#else
   // test 
	obj.test_AI();
#endif 
}


