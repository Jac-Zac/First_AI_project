//
//  Weights.hpp
//  First_AI_project 
//
//  Created by Jacopo Zacchigna on 24/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "header.h"

// ********************************************* DEFINITION **********************************************

class Weights {
  public:
    // I don't really care about input weights since they are the output weight on the previous layer
    void gen_output(uint64_t n, size_t &index); // this function generate the output weights
                                    // and fill single_output_weights
    void print_output_single_weights() const;
    void save_weights(std::ofstream &saved_weights);
    void copy_weights(uint64_t n, std::array<float, TOTAL_W> &saved, uint64_t k);

    //  vector of weight in a single line
    std::vector<double> single_output_weights;

  private:
    double gen_random(size_t &index);
};
