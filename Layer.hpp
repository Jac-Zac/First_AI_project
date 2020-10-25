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
	void copy_layer(size_t& inedx, std::array<float,TOTAL_W>& save); // this is useful tu create a layer form existing weights 

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

inline void Layer::copy_layer(size_t& index, std::array<float,TOTAL_W>& saved){ // index is the layer that we are on
	// TESTING **********************
		
    // this is for output layers weights 
        
    for(size_t j = 0; j < topology[index]; j++){
         Weights o_w; // input weights

		// this is to fill the network 

		// I HAVE TO FIX THIS PART 
		 
		if(index == 0){
			for(size_t i = 0; i < topology[index + 1]; i++){
				o_w.single_output_weights.emplace_back(saved[i]); 
			}
		}else{
			if(index < SIZE -1){  // I have to check because if I am at the last layer I can't do topology at index + 1 and it wouldn't even make sens so I have to check the It stops before 
				for(size_t j = topology[index + 1] ; j < 2*topology[index + 1] ; j++){ // I start from topology[index + 1 ] because I want to be sure that that if I'm reading from the vector I'm not starting from the first place 
					o_w.single_output_weights.emplace_back(saved[j]);  // this is for testing
				}
			}
		}
	
		 output_weights.emplace_back(o_w);
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
    }
	std::cout<<"\n";
}
