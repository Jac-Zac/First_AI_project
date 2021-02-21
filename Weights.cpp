//
//  Weights.cpp
//  First_AI_project
//
//  Created by Jacopo Zacchigna on 24/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#include "Weights.hpp"

// ********************************************* IMPLEMENTATION  **********************************************

void Weights::gen_output(uint64_t n, size_t &index) {
    for (uint64_t i = 0; i < n; i++) {
        single_output_weights.emplace_back(gen_random(index));
    }
}

void Weights::copy_weights(uint64_t n, std::array<float, TOTAL_W> &saved, uint64_t k) {
    for (uint64_t i = n; i < 2 * n; i++, k++) { // remember that I'm starting from topology[index + 1]
        single_output_weights.emplace_back(saved[k]);
    }
}

double Weights::gen_random(size_t &index) {
    // normal distribution media = 0, deviation = 1

    std::default_random_engine generator;

    // Normal number distribution -> Gaussian

    // He-Normal Initialization

    // Initialization for ReLU (Xavier initialization)

    // index start at 0 which is what I want and go to SIZE - 1

    // I have to fix this
    std::normal_distribution<double> distribution(0, sqrt(2.0 / (topology[index]))); // median and deviation

    // IMPORTANT DO NOT FORGET TO DIVIDE NOT 2 BUT 2.0 -> IF YOU DO NOT DO THAT
    // IT WILL PERFORM A INT DIVISION

    // Initialize with non-deterministic seeds
    generator.seed(std::random_device{}());

    return distribution(generator);
}

void Weights::print_output_single_weights() const {
    for (auto &it : single_output_weights) {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

// function to save the weights in a file
void Weights::save_weights(std::ofstream &saved_weights) {
    for (auto &it : single_output_weights) {
        saved_weights << it << " ";
    }
}
