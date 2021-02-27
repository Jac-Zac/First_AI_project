//
//  AI.cpp
//  First_AI_project
//
//  Created by Jacopo Zacchigna on 03/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#include "AI.hpp"

// ********************************************* IMPLEMENTATION **********************************************

AI::AI() {
    std::cout << "\nAI training ... \n";
}

void AI::train_AI() {
    // this is just a test for now

    Net net;
    Net value_net = net; // This will be our target network

    // Iterate over the batch size. That is the number of game we play in this case
	for (uint64_t i = 0; i < batch_size; i++) {
    	episode(net);
		Gradient gradient;
		gradient.Loss();
        net.Feedforward(state);
    }

    net.print_Net();
}

// This is for when we have already trained the Neural Net
void AI::test_AI() {
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


// inoltre doveri sviluppare dele reword
// da correggere
// This is the function for every episode
void AI::episode(Net &net) {
    std::srand((intmax_t)time(0)); // srand for the step function  // forse non
                                   // serve devo controllare !
    while (!won) { // if won == false
        player = (turn % 2 == 0) ? 1 : 2;
        std::cout << "------------------------------\n"
                  << "Player number " << player << " Has the move\n";
        step(net);
        // check if somebody won in this turn
        check_won();

        //	control for draw
        if (turn == 9 && !won) {
            std::cout << "\nGame ended in a draw -------------------------\n\n";
            return;
        }

        // to check if game ended
        if (won) { // if won == true 
            std::cout << "\nPlayer " << player << " won \n\n";
        }
    }
}

// this if the function that allows the AI to play fallowing various rules
void AI::step(Net &net) {
    // I have to check if move is allowed if the slot is != 0 move should be the
    // next best Q_value
    if (turn % 2 == 0) {
        // AI play
        // action = max Q_value (da creare un array Q value per una rete neurale) I have to check when to exploit

        // per adesso è un test ma bisonga ripararlo
        exploiting = rand_exp();
        if (exploiting) { // if exploiting == true
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

bool AI::rand_exp() {
    std::default_random_engine generator;

    std::uniform_real_distribution<double> distribution(
        0.1, 9.9); // median and deviation

    // Initialize with non-deterministic seeds
    generator.seed(std::random_device{}());

    // if we return true than it will exploit else it will explore
    if (distribution(generator) >= threshold) {
        return true; }
		return false;
}

// Chose the best action following the feed forward
void AI::exploit(Net &net) {

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
void AI::explore() {
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

void AI::check_won() {
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
