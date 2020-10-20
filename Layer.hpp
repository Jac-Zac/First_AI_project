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
    void create_layer(int& index); // we have to pass the topology this create the layer and the weights 
	void copy_layer(int& inedx, std::ifstream& previous_weights); // this is useful tu create a layer form existing weights 

    void print_output_matrix(int& index)const; // print matrix of the output weight 
	void save_matrix(int& index, std::ofstream& saved_weights);

	std::vector<Weights> output_weights; 
};


// ********************************************* IMPLEMENTATION **********************************************

inline void Layer::create_layer(int& index){ // index is the layer that we are on
        // this is for output layers
        
        for(int j = 0; j < topology[index]; j++){
            Weights o_w; // input weights
            o_w.gen_output(topology[index + 1],index); // since we want the input weight we need to pass the number of neurones of the layer after
            output_weights.emplace_back(o_w);
        }

    // for all layers
    for(int k = 0; k < topology[index] ; k++ ){
        layer.emplace_back(0.0);
    }
}

inline void Layer::copy_layer(int& index, std::ifstream& previous_weights){ // index is the layer that we are on
		// TESTING **********************
		
        // this is for output layers
        
    for(int j = 0; j < topology[index]; j++){
         Weights o_w; // input weights
		 // I think this is not needed
		// 		 o_w.copy_output(topology[index + 1],index, previous_weights); // since we want the input weight we need to pass the number of neurones of the layer after

		// loop thought the line (It should be based on the number of neuron for the layer )and then create a stream from the line and copy the weights 
		//  you than do not need the copy_output function
		//  for(size_t j = 0 ; j < TOPOLOGY[index + 1]; j++ ]) // loop thought at the weights 
		 // for(size_t i = 0 ; i < $TOPOLIGY[index]; i++)[{std::istringstream in($line);}
		 
		 int s = 1; // testing 

		// this is to fill the network 
		 for(size_t i = 0; i < topology[index + 1]; i++){
			o_w.single_output_weights.emplace_back(s); // this is for testing I have to change it with std::istringstream 
			s++;
		 }
		 output_weights.emplace_back(o_w);
    }

    // for all layers
    for(int k = 0; k < topology[index] ; k++ ){
        layer.emplace_back(0.0);
    }
// TESTING *******************

}

inline void Layer::print_output_matrix(int& index) const {
    for(int j = 0; j < topology[index]; j++){
        output_weights[j].print_output_single_weights();
    }
    std::cout<<"\n";
}

// save the weight matrix to a file by passing the file std::ostream by reference ! 
inline void Layer::save_matrix(int& index, std::ofstream& saved_weights){
    for(int j = 0; j < topology[index]; j++){
        output_weights[j].save_weights(saved_weights);
    }
	std::cout<<"\n";
}
