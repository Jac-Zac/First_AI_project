//
//  Net.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 16/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once

#include "Game.h"
#include "Layer.hpp"

// ********************************************* DEFINITION **********************************************

class Net : public Layer {
  public:
    Net(); // constructor weights need to be initialized
    Net(std::ifstream &previous_weights); // constructor weights are already
                                          // created and saved in another file

#if TEST == false
    ~Net();
#endif

    // my neural network is an array of Layer
    std::vector<Layer> DNN;

    void Feedforward(std::array<int, N> &state);

    // TO DO ******************
    // create error function
    // create back prop and see what you are missing
    // ******************

    void print_Net() const;

  public:
    std::array<float, TOTAL_W>
        saved; // this is a vector that allow us to store the saved weights

  protected:
    double activation_function(double neuron, int type);
};
