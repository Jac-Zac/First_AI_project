//
//  AI.hpp
//  First_AI_project 
//
//  Created by Jacopo Zacchigna on 03/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "Gradient.hpp"

// ********************************************* DEFINITION **********************************************

// AI class
class AI : public Game {
  public:
    AI();
    void step(Net &net);
    void episode(Net &net);
    void check_won();
    void train_AI();
    void test_AI();

  protected:
    uint64_t batch_size = 1; // for now batch size is only 1
    uint_fast16_t turn = 0;
    uint_fast16_t player;
    uint_fast16_t action_1 = 0;
    uint_fast16_t action_2 = 1;
    bool won = false; // if won == true game is ended else we should end
    void exploit(Net &net);
    void explore();
    double threshold = 0; // should be 0.1 and increment as the training progress so every episode, when <= exploit()
    bool rand_exp(); // random number to test if I want to explore or exploit
    bool exploiting; // variable to see if it will exploit or explore
};
