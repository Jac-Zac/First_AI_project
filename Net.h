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
    Net(std::vector<int> topology); // constructor weights need to be initizlized
    Net(std::vector<int> topology, std::ifstream& infile); // constructor weights are alread craeted and saved in another file 
    
    std::vector<Layer> DNN;
    void Feedforward(std::array<int,N>& state);
    // create feed forward and back prop and see what you are missing 
    // create error function
    
    void print_Net();
    
protected:
    double activation_function(double neuron, int type);
    std::vector<int> m_topology; // m_topology beacuase it is a memmber 
};

// constructor to fill the net 
inline Net::Net(std::vector<int> topology)
:m_topology(topology) // member initializer list
{
    for(int j = 0 ; j < m_topology.size(); j++){
        Layer l;
        l.create_layer(m_topology,j);
        DNN.push_back(l);
     }
}

inline Net::Net(std::vector<int> topology, std::ifstream& infile){
// must be filled 
}


// appunti
// scrivu una funzione che faccia RELUE magari cerca su interntet 

inline double Net::activation_function(double neuron, int type){
   if(type == Tanh) return tanh(neuron);
   if(type == ReLU){
      // i have to code ReLU
   }
    // defoult case
    return 0;
}


inline void Net::Feedforward(std::array<int,N>& state){
    // i have to sum the moltiply neuron value to weight and then try this by adding it to the AI class
    // i also have to add the bias to all the neuron and pass everything through relu
    
    //implementation of Feedforward
    
    // fill the neurons of the first layer, I think I have to pass all of this trought a actiavtion function to
    for(size_t i = 0; i < N ; i++){
          DNN[0].layer[i] = state[i]; // fill all the imput neuron with the state that was passed in
      }
    
    for(size_t j = 0 ; j < DNN.size() - 1; j++){
        // loop trought layers
        for(size_t k = 0 ; k < m_topology[j + 1] ; k++){  // loop trought the neurons in the new layer 
            // as a testK
            for(size_t i = 0; i < m_topology[j]; i++){
                DNN[j + 1].layer[k] += DNN[j].layer[i]*DNN[j].output_weights[i].single_output_weights[k];
            }
            // this is just as a test 
            DNN[j + 1].layer[k] = activation_function(DNN[j + 1].layer[k],Tanh); // activation function 
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

    // print matrix of weigths
    for(int i = 0; i < DNN.size(); i++){
        if(i != (DNN.size() - 1)){
            std::cout<<"Print output weights Layer "<<i<<"\n"<<"----------------------------------\n"<<"\n";
            DNN[i].print_output_matrix(m_topology,i);
            std::cout<<"\n";
        }
    }
    
}
