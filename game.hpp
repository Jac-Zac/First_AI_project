//
//  game.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 02/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "da_includere.hpp"

// player 1 -> 1
// player 2 -> -1

class game{
public:
    void print_board() const;
    std::array<int,N> state = {0,0,0,0,0,0,0,0,0};
};


// printing board function
inline void game::print_board() const {
    for(size_t j = 0; j < N; j = j+3){
        for(size_t i = 0; i < 3; i++){
            std::cout<<state[i + j]<<" ";
        }
        std::cout<<"\n";
    }
}
