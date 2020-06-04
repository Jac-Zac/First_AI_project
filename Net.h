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
    Net(std::vector<int> topology); // constructor
    
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
    //prossima cosa bisogna svilupparlo fai un disegno per avere una idea miglore
/*
    for(size_t i = 0 ; i < DNN.size() ; i++){
       for(size_t j = 0 ; j < m_topology ; j++){
           DNN[i + 1].layer[j] 
           // for the last layer not + 1 I have to check 
        }
    }
*/
      // for now as a test we fill the first neurons 
      for(size_t i = 0; i < N ; i++){
          DNN[0].layer[i] = state[i] + 1 ; // fill all the imput neuron with the state
          // + 1 is to simulate a bias neuron that has the value of 1  
      }

      // this is just a test we can immagin 1 as the input neuron and than a weight
      std::cout<<"\n"<<"The output of the first test moltiplication is: \n"<<activation_function(DNN[0].layer[0]*DNN[0].output_weights[0].single_output_weigths[0],Tanh)<<"\n";  
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
