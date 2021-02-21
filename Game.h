//
//  Game.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 02/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "header.h"

// player 1 -> 1
// player 2 -> -1

class Game {
  public:
    void print_board() const;
    std::array<int, N> state = {0}; // initializing with 0 which means non of those are utilized spaces yet
};

inline void Game::print_board() const {
	for (uint64_t j = 0; j < N; j = j + 3) {
		for (uint64_t i = 0; i < 3; i++) {
			std::cout << state[i + j] << " ";
		}
		std::cout << "\n";
	}
}
