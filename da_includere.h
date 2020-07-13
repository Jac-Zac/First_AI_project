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

// here we have the therfore created the macro N 

#define N 9 // N will be the dimension of the board and consequently teh input and output number of neuron in this net but can be changed to be appield for other games

// funzionalità utlizzata soprattutto per il testing 
#define PRINT true  // if PRINT == true -> print the output layer after every FeedForward of the net
#define SAVE true // if SAVE == true -> the weights are going to be saved in a new file
// activation functions
// for now -> than I can add other 
#define ReLU 0
#define Tanh 1

// topology of the network -> this can change I think I will try with {N,12,15,12,N}
#define SIZE 3 // SIZE -> this is the size of the topology
std::array<int,SIZE> topology = {N,12,N}; // test per adesso
