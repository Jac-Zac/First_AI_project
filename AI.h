//
//  AI.h
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 03/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "game.h"
#include "Net.h"

class AI : public game {
public:
    // ai class
    AI();
    void step(Net& net);
    void episode(Net& net);
    void check_won();
    void train_AI();
protected:
    size_t batch_size = 1; // for now bactch size is only 1
    unsigned short turn = 0;
    unsigned short player;
    unsigned short action_1 = 0;
    unsigned short action_2 = 1;
    bool won = false; // if won == true game is ended else we should end
    void exploit(Net& net);
    void explore();
};
    
inline AI::AI()
{
    std::cout<<"\n";
    std::cout<<"Ai trianing ... \n";
}

// un idea può essere di avere una batch size di tipo 5 che viene processata in parallelo da mutlithreading però ricordati di cambiare alive in non static e anche state 

// chose the best action following the feed forward
inline void AI::exploit(Net& net){
    // to implement 
    net.Feedforward(state);
}

// explore in a random manner 
inline void AI::explore(){
    if(turn % 2 == 0){
        do{
            action_1 = rand() % 9;
        }while(state[action_1] != 0);
    }else{
        do{
            action_2 = rand() % 9;
        }while(state[action_2] != 0);
    }
}

// inoltre doveri sviluppare dele reword 
// da correggere 
inline void AI::episode(Net& net){ // this should be an episode not an epoche
    std::srand((unsigned)time(0));
    while(won == false){
        player = (turn % 2 == 0) ? 1 : 2;
        std::cout<<"--------------------"<<"\n"<<"Player number "<< player<<" Has the move"<<"\n";
        step(net);
        // check if somebody won in this turn
        check_won();

        // control for draw
        if(turn == 9 && won == false){
            std::cout<<"Game ended in a draw --------------------\n";
            return;
        }
        
        // to check if game ended
        if(won == true) {
            std::cout<<"Player "<<player<<" won \n";
        }
    }
}

// this should not be an episode but is just 1 step 
inline void AI::step(Net& net){
    //funzione per giocare
    
    // i have to check if move is allowd if the slot is != 0 move should be the next best Q_value
    if(turn % 2 == 0){
        // ai play
        // action = max Q_value (da creare un array Q value per una rete neuraler)
        // I have to check when to exploit
        explore();
        // exploit se il numero random è maggiore della soglia 
        state[action_1] = 1;
    }else{
        // i play for now than 2 ai will play
        explore();
        state[action_2] = -1;
    }
    print_board();
    turn++;
}


inline void AI::check_won(){
    
    // this is too check if anyone won the game this turn I't can be coded with a loop but that make the time complezity higher
    // check rows
    
    if((state[0] == 1 && state[1] == 1 && state[2] == 1) || (state[3] == 1 && state[4] == 1 && state[5] == 1) || (state[6] == 1 && state[7] == 1 && state[8] == 1)) won = true;
    if((state[0] == -1 && state[1] == -1 && state[2] == -1) || (state[3] == -1 && state[4] == -1 && state[5] == -1) || (state[6] == -1 && state[7] == -1 && state[8] == -1)) won = true;
    // check columns
    if((state[0] == 1 && state[3] == 1 && state[6] == 1) || (state[1] == 1 && state[4] == 1 && state[7] == 1) || (state[2] == 1 && state[5] == 1 && state[8] == 1)) won = true;
    if((state[0] == -1 && state[3] == -1 && state[6] == -1) || (state[1] == -1 && state[4] == -1 && state[7] == -1) || (state[2] == -1 && state[5] == -1 && state[8] == -1))  won = true;
    // check crosses
    if((state[0] == 1 && state[4] == 1 && state[8] == 1) || (state[2] == 1 && state[4] == 1 && state[6] == 1)) won = true;
    if((state[0] == -1 && state[4] == -1 && state[8] == -1) || (state[2] == -1 && state[4] == -1 && state[6] == -1)) won = true;
    
}


inline void AI::train_AI(){
// this is just a test for now 
// I think the topology should be N, 12 , 15 , 9 but for testing it will be simpler
    std::vector<int> topology;
    topology.push_back(N);
    topology.push_back(12);
    topology.push_back(N);
    Net net(topology);
    episode(net);
    
    for(size_t i = 0 ; i < batch_size ; i++ ){
        net.Feedforward(state);
    }
    
    net.print_Net();
   
}
