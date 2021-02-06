//
//  AI.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 03/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "Net.hpp"
#include "Game.hpp"

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

// ********************************************* IMPLEMENTATION **********************************************

inline AI::AI() {
    std::cout << "\nAI training ... \n";
}

// Chose the best action following the feed forward
inline void AI::exploit(Net &net) {
    // IMPORTANT for later *************************
    // devo ancora mondifcarla per fare sapere alla rete neurale se sto facendo
    // un azione casuale perchè quelle che mi ha dato la rete neurale era
    // pessima lui non stava suggerendo una buona mosssa
    // **********************************************

    //  we pass through the network
    net.Feedforward(state);

    if (turn % 2 == 0) { // check the turn
        // this is for player 1
        action_1 = std::distance(net.DNN.back().layer.begin(),std::max_element(net.DNN.back().layer.begin(),net.DNN.back().layer.end())); // back get the last of a list and thous the output layer

        // if the space on the board is already fill then choose a random action
        if (state[action_1] != 0) {
            explore();
        }
    } else {
        // this is for player 2
        action_2 = std::distance(net.DNN.back().layer.begin(),std::max_element(net.DNN.back().layer.begin(),net.DNN.back().layer.end()));

        // if the space on the board is already fill then choose a random action
        if (state[action_2] != 0) {
            explore();
        }
    }
}

// explore in a random manner
inline void AI::explore() {
    if (turn % 2 == 0) {
        do {
            action_1 = rand() % 9; // random move (between 1 and 9) -> this is for the first player
        } while (state[action_1] != 0);
    } else {
        do {
            action_2 = rand() % 9;      // random
        } while (state[action_2] != 0); // random move for the second player
    }
}

// inoltre doveri sviluppare dele reword
// da correggere
// This is the function for every episode
inline void AI::episode(Net &net) {
    std::srand((intmax_t)time(0)); // srand for the step function  // forse non
                                   // serve devo controllare !
    while (won == false) {
        player = (turn % 2 == 0) ? 1 : 2;
        std::cout << "--------------------\n"
                  << "Player number " << player << " Has the move\n";
        step(net);
        // check if somebody won in this turn
        check_won();

        //	control for draw
        if (turn == 9 && won == false) {
            std::cout << "Game ended in a draw --------------------\n";
            return;
        }

        // to check if game ended
        if (won == true) {
            std::cout << "Player " << player << " won \n";
        }
    }
}

inline bool AI::rand_exp() {
    std::default_random_engine generator;

    std::uniform_real_distribution<double> distribution(
        0.1, 9.9); // median and deviation

    // Initialize with non-deterministic seeds
    generator.seed(std::random_device{}());

    // if we return true than it will exploit else it will explore
    if (distribution(generator) >= threshold)
        return true;
    else {
        return false;
    }
}

// this if the function that allows the AI to play fallowing various rules
inline void AI::step(Net &net) {
    // I have to check if move is allowed if the slot is != 0 move should be the
    // next best Q_value
    if (turn % 2 == 0) {
        // AI play
        // action = max Q_value (da creare un array Q value per una rete neurale) I have to check when to exploit

        // per adesso è un test ma bisonga ripararlo
        exploiting = rand_exp();
        if (exploiting == true) {
            exploit(net);
        } else
            explore();

        // exploit if the number random number that I got is >= compared to the threshold
        state[action_1] = 1;
    } else {
        // I play for now than 2 AI will play

        exploit(net); // the second agent is always exploiting

        state[action_2] = -1;
    }
    print_board();
    turn++;
}

inline void AI::check_won() {
    // this is too check if anyone won the game
	// No loops to check because of worst time complexity

	// check rows
    if ((state[0] == 1 && state[1] == 1 && state[2] == 1) ||
        (state[3] == 1 && state[4] == 1 && state[5] == 1) ||
        (state[6] == 1 && state[7] == 1 && state[8] == 1))
        won = true;
    if ((state[0] == -1 && state[1] == -1 && state[2] == -1) ||
        (state[3] == -1 && state[4] == -1 && state[5] == -1) ||
        (state[6] == -1 && state[7] == -1 && state[8] == -1))
        won = true;
    // check columns
    if ((state[0] == 1 && state[3] == 1 && state[6] == 1) ||
        (state[1] == 1 && state[4] == 1 && state[7] == 1) ||
        (state[2] == 1 && state[5] == 1 && state[8] == 1))
        won = true;
    if ((state[0] == -1 && state[3] == -1 && state[6] == -1) ||
        (state[1] == -1 && state[4] == -1 && state[7] == -1) ||
        (state[2] == -1 && state[5] == -1 && state[8] == -1))
        won = true;
    // check crosses
    if ((state[0] == 1 && state[4] == 1 && state[8] == 1) ||
        (state[2] == 1 && state[4] == 1 && state[6] == 1))
        won = true;
    if ((state[0] == -1 && state[4] == -1 && state[8] == -1) ||
        (state[2] == -1 && state[4] == -1 && state[6] == -1))
        won = true;
}

inline void AI::train_AI() {
    // this is just a test for now

    Net net;
    Net value_net = net;

    // Now we should also create a target network which is helpful to calculate the Loss function
    episode(net);

    for (uint64_t i = 0; i < batch_size; i++) {
        net.Feedforward(state);
    }
    net.print_Net();
}

// This is for when we have already trained the Neural Net
inline void AI::test_AI() {
    std::ifstream previous_weights("Saved_Weights");
    Net net(previous_weights);
    previous_weights.close();
    std::cout << "\n";
    episode(net);

    for (uint64_t i = 0; i < batch_size; i++) {
        net.Feedforward(state);
    }

    net.print_Net(); // in this case the Net that get printed is the new Net
}
