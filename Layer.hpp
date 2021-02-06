//
//  Layer.hpp
//  AI_Tria 2.0
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

// ********************************************* IMPLEMENTATION **********************************************

inline void Layer::create_layer(
    size_t &index) { // index allows us to now which layer we are on
    for (uint64_t j = 0; j < topology[index]; j++) {
        if (index < SIZE - 1) { 
			// if I didn't do the check I would go out of bound and I can't do that
            Weights o_w;
            o_w.gen_output(topology[index + 1], index); // since we want the output weight we need to pass the number of neurones of the layer after
            output_weights.emplace_back(o_w);
        }
        layer.emplace_back(0.0); // this initialize to 0.0
    }
}

inline void Layer::copy_layer(
    size_t &index, std::array<float, TOTAL_W> &saved, uint64_t k) {  
				  // index is the layer that we are on
				  // saved is the array that I have filled from the Saved_Weights file, k is helpful to start at the correct index of saved
    // this is for output layers weights because I only need those, else would
    // be redundant
    for (uint64_t j = 0; j < topology[index]; j++) {
        // this is to fill the network
        if (index < SIZE - 1) {  
						 // I have to check because if I am at the last layer I can't do topology at index + 1 and it wouldn't even make sens so I have to check the It stops before
            Weights o_w; // output weights
            o_w.copy_weights(topology[index + 1], saved, k);
            output_weights.emplace_back(o_w);
            k = k + topology[index + 1]; // we have to start reading from the correct part of the array
        }
        layer.emplace_back(0.0);
    }
}

// just printing to screen
inline void Layer::print_output_matrix(size_t &index) const {
    for (uint64_t j = 0; j < topology[index]; j++) {
        output_weights[j].print_output_single_weights();
    }
    std::cout << "\n";
}

// save the weight matrix to a file by passing the file std::ostream by reference !
inline void Layer::save_matrix(size_t &index, std::ofstream &saved_weights) {
    for (uint64_t j = 0; j < topology[index]; j++) {
        output_weights[j].save_weights(saved_weights);
        saved_weights << "\n";
    }
    saved_weights << "\n";
    std::cout << "\n";
}
