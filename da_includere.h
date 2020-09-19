//
//  da_includere.h
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 02/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include<iostream>
#include<fstream>
#include<array>
#include<vector>
#include<random>
#include<tuple>
#include<stdlib.h>
#include<thread>
#include<algorithm>
#include<random>
#include<time.h>
#include<math.h>
#include<cstdlib>

// here we have the therefore created the macro N 

#define N 9 // N will be the dimension of the board and consequently the input and output number of neuron in this net but can be changed to be applied for other games

#define TEST false // if test is true then we should not save new weight and use the old weight and also not back_prop because we already trained the Net
#define PRINT true  // if PRINT == true -> print the output layer after every Feed Forward of the net
// activation functions
// for now -> than I can add other 
#define ReLU 0
#define Tanh 1

// topology of the network -> this can change I think I will try with {N,12,15,12,N}
#define SIZE 3 // SIZE -> this is the size of the topology
std::array<int,SIZE> topology = {N,3,N}; // for now the number is arbitrary an really low for testing purposes 
