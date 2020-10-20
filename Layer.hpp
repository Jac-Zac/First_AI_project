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
	void copy_layer(int& inedx, std::vector<float>& save); // this is useful tu create a layer form existing weights 

    void print_output_matrix(int& index)const; // print matrix of the output weight 
	void save_matrix(int& index, std::ofstream& saved_weights);

	std::vector<Weights> output_weights;  
	std::vector<float> saved; // this is a vector that allow us to store the saved weights 
protected: 
	int count(int i); // this function count the number of weights for a at any point that we have passed (doesn't check for index out of bound)
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

int Layer::count(int i){ // implementation
	int sum = 0;
		for( ; i > 0 ; i--){
			sum = sum + (topology[i] * topology[i - 1]);
		}
	return sum;
}

inline void Layer::copy_layer(int& index, std::vector<float>& saved){ // index is the layer that we are on
	// TESTING **********************
		
    // this is for output layers weights 
        
    for(int j = 0; j < topology[index]; j++){
         Weights o_w; // input weights

		// loop thought the line (It should be based on the number of neuron for the layer )and then create a stream from the line and copy the weights 
		//  you than do not need the copy_output function
		//  for(size_t j = 0 ; j < TOPOLOGY[index + 1]; j++ ]) // loop thought at the weights 
		// for(size_t i = 0 ; i < $TOPOLIGY[index]; i++)[{std::istringstream in($line);}
	    
		// Loop throughout the whole file and create an vector of float and then get values from that vector to fill the network's weighs 

		// this is to fill the network 

		// I HAVE TO FIX THIS PART 
		 
		if(index == 0){
			for(size_t i = 0; i < topology[index + 1]; i++){
				o_w.single_output_weights.emplace_back(saved[i]); 
			}
		}else{
			for(size_t j = topology[index + 1] ; j < 2*topology[index + 1] ; j++){ // I start from topology[index + 1 ] because I want to be sure that that if I'm reading from the vector I'm not starting from the first place 
				o_w.single_output_weights.emplace_back(3);  // this is for testing
			}
		}
	
		 output_weights.emplace_back(o_w);
    }

    
// for all layers
    for(int k = 0; k < topology[index] ; k++ ){
        layer.emplace_back(0.0);
    }
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
