//
//  Layer.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 16/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//
#include "Weights.hpp"

// ********************************************* DEFINITION **********************************************

class Layer{
public:
    std::vector<double> layer; // neurons in a layer 
	void create_layer(size_t& index); // we have to pass the topology this create the layer and the weights 
	void copy_layer(size_t& inedx, std::array<float,TOTAL_W>& save, size_t k); // this is useful tu create a layer form existing weights 

    void print_output_matrix(size_t& index)const; // print matrix of the output weight 
	void save_matrix(size_t& index, std::ofstream& saved_weights);

	std::vector<Weights> output_weights;  
	std::vector<float> saved; // this is a vector that allow us to store the saved weights 
};


// ********************************************* IMPLEMENTATION **********************************************


inline void Layer::create_layer(size_t& index){ // index is the layer that we are on
        // this is for output layers
		for(size_t j = 0; j < topology[index]; j++){ // if I didn't do the check I would go out of bound and I can't do that 
			if(index < SIZE - 1 ){
				Weights o_w; // input weights
				o_w.gen_output(topology[index + 1],index); // since we want the input weight we need to pass the number of neurones of the layer after
				output_weights.emplace_back(o_w);
			}
        }

    // for all layers
    for(size_t k = 0; k < topology[index] ; k++ ){
        layer.emplace_back(0.0);
    }
}

inline void Layer::copy_layer(size_t& index, std::array<float,TOTAL_W>& saved, size_t k){ // index is the layer that we are on
	// this is for output layers weights
	for(size_t j = 0; j < topology[index]; j++){
		// this is to fill the network 
		if(index < SIZE - 1){  // I have to check because if I am at the last layer I can't do topology at index + 1 and it wouldn't even make sens so I have to check the It stops before 
		Weights o_w; // output weights
		o_w.copy_weights(topology[index + 1], saved,k);
		output_weights.emplace_back(o_w);
		k = k + topology[index + 1]; // we have to start reading from the correct part of the array
		}
	}

 // for all layers
    for(size_t k = 0; k < topology[index] ; k++ ){
        layer.emplace_back(0.0);
    }
}

inline void Layer::print_output_matrix(size_t& index) const {
    for(size_t j = 0; j < topology[index]; j++){
        output_weights[j].print_output_single_weights();
    }
    std::cout<<"\n";
}

// save the weight matrix to a file by passing the file std::ostream by reference ! 
inline void Layer::save_matrix(size_t& index, std::ofstream& saved_weights){
    for(size_t j = 0; j < topology[index]; j++){
        output_weights[j].save_weights(saved_weights);
	    saved_weights << "\n";
    }
	saved_weights << "\n";
	std::cout<<"\n";
}
