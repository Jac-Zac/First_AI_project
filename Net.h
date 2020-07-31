//
//  Net.h
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 16/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include "Layer.h"
#include "game.h"

class Net : public Layer
{
public:
    Net(); // constructor weights need to be initialized

#if SAVE == true
	~Net();
#endif

	Net(std::ifstream& previous_weights); // constructor weights are already created and saved in another file 

  // devo creare un copy constructor per il primo tipo per creare un value net 

    std::vector<Layer> DNN;
    void Feedforward(std::array<int,N>& state);
    // test feed forward and create back prop and see what you are missing 
    // create error function
    
    void print_Net();
    
protected:
    double activation_function(double neuron, int type);
};

// constructor to fill the net 
inline Net::Net()
{
    for(int j = 0 ; j < SIZE ; j++){  // SIZE is the size of the topology  
        Layer l;
        l.create_layer(j);
        DNN.push_back(l);
     }
}

// testing this right now I have to implement it on other files 
// posso usare le condizioni tipo save file in da_includere per mettere a posto nel file AI.h e main.h 

inline Net::Net(std::ifstream& previous_weights){
  // questo constructor serve per qunado il modello ha gia fatto training e quindi posso inserire i pesi gia calcolati   
		
  // this is just to test
		std::string word; 
		while(previous_weights.good()){
				std::cout << word << " ";
				previous_weights >> word;
		}


  // end testing
   // deve chiamare una nuova funzione dentro Layer.h che serve a prendere i pesi da l' input_file 
}


inline double Net::activation_function(double neuron, int type){
   if(type == Tanh) return tanh(neuron);
   if(type == ReLU) return (neuron <= 0) ? 0 : neuron; // ternary operator implementation 
     
    // I can add other activation function
    // default case
    return 0;
}


inline void Net::Feedforward(std::array<int,N>& state){
    // I have to test it and add comments 
    //
    //implementation of Feedforward
    
    // fill the neurons of the first layer, I think I have to pass all of this trough an activation function to
    for(size_t i = 0; i < N ; i++){
       DNN[0].layer[i] = state[i]; // fill all the input neuron with the state that was passed in
    }
    
    for(size_t j = 0 ; j < DNN.size() - 1; j++){
        // loop trough layers
        for(size_t k = 0 ; k < topology[j + 1] ; k++){  // loop trough the neurons in the new layer 
            // as a test
            for(size_t i = 0; i < topology[j]; i++){
                DNN[j + 1].layer[k] += DNN[j].layer[i]*DNN[j].output_weights[i].single_output_weights[k];
            }
            // this is just as a test 
            DNN[j + 1].layer[k] = activation_function(DNN[j + 1].layer[k],ReLU); // activation function 
        }
    }
     
// if in print mode print the output layer 
#if PRINT == true
    // print the last layer neurons
    for(size_t i = 0; i < N ; i++){
       std::cout<<"The value of the neuron number "<<i<<" is = "<<DNN.back().layer[i]<<"\n"; // back because we care only about the last layer
    }
#endif

    // after every Feedforward all neuron should be -> 0
    // the one in the first layer are not a problem 
    for(size_t j = 0 ; j < DNN.size() - 1; j++){
        // loop trough layers
        for(size_t k = 0 ; k < topology[j + 1] ; k++){  // loop trough the neurons in the new layer 
            DNN[j + 1].layer[k] = 0.0 ;
        }
    }
}


// function to print the net structure 
inline void Net::print_Net(){
    // print neuron structure
    for(int i = 0; i < DNN.size(); i++){ // for all the layer in a Network 
        std::cout<<"Layer number "<<i<<"\n"<<"--------------------\n";
        for(size_t j = 0; j < DNN[i].layer.size() ; j++){ // for all the neuron in a layer
            std::cout<<"Neuron number "<<j<<" = "<<DNN[i].layer[j]<<"\n";
        }
        std::cout<<std::endl;
    }

    // print matrix of weights
    for(int i = 0; i < DNN.size(); i++){
        if(i != (DNN.size() - 1)){
            std::cout<<"Print output weights Layer "<<i<<"\n"<<"----------------------------------\n"<<"\n";
            DNN[i].print_output_matrix(i);
            std::cout<<"\n";
        }
    }
}

// I can decide if I want to save the weights or not at compile time and this function allows me to save them in a file 
#if SAVE == true
inline Net::~Net(){
	std::ofstream saved_weights;
	saved_weights.open ("Saved_Weights");

	for(int i = 0; i < DNN.size(); i++){
		if(i != (DNN.size() - 1)){
			DNN[i].save_matrix(i,saved_weights);
        }
    }
	saved_weights << "\n";
	saved_weights.close();
}
#endif 
