//
//  topology.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 23/10/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

// here we have the therefore created the macro N

#define N 9 // N will be the dimension of the board.
	  // consequently the input and output number of neuron in this net but can be changed to be applied for other games

#define TEST false // if test is true then we should not save new weight and use the old
          // weight and also not back_prop because we already trained the Net
#define PRIT false // if PRINT == true -> print the output layer after every Feed Forward
          // of the net
// activation functions
// for now -> than I can add other
#define ReLU 0
#define Tanh 1

// topology of the network -> this can change I think I will try with
// {N,12,15,12,N}
#define SIZE 3 // SIZE -> this is the size of the topology
constexpr std::array<const size_t, SIZE> topology = {N, 2,N}; // for now the number is arbitrary an really low for testing purposes

constexpr int64_t count(size_t i){ // this function count the number of weights for a any point
    // that we have passed (doesn't check for index out of bound)
    int64_t sum = 0;
    for (; i > 0; i--) {
        sum = sum + (topology[i] * topology[i - 1]);
    }
    return sum;
}

#define TOTAL_W count(SIZE - 1) // total wights
