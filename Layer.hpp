//
//  Layer.hpp
//  First_AI_project 
//
//  Created by Jacopo Zacchigna on 16/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//
#include "Weights.hpp"

// ********************************************* DEFINITION **********************************************

class Layer {
  public:
    std::vector<double> layer;        // neurons in a layer
    void create_layer(size_t &index); // This function creates layers
                                      // initialize weights at training time
    void copy_layer(size_t &inedx, std::array<float, TOTAL_W> &save, uint64_t k); // this is useful tu create a layer form existing weights at test time for example

    void print_output_matrix(size_t &index) const; // print matrix of the output weight
    void save_matrix(size_t &index,std::ofstream &saved_weights); // save the matrix of the output weights into the Saved_Weights file

    std::vector<Weights> output_weights; // this is a vector of instance of the Weighs class
    std::vector<float> saved; // this is a vector that allow us to store the saved weights
};
