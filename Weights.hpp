//
//  Weights.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 24/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include"da_includere.h"

// ********************************************* DEFINITION **********************************************

class Weights{
public:
 
    // I don't really care about input weights since they are the output weight on the previous layer 
    void gen_output(int n, int& index); // this function generate the output weights and fill single_output_weights
    void print_output_single_weights()const;
	void save_weights(std::ofstream& saved_weights);

    //  vector of weight in a single line 
    std::vector<double> single_output_weights;

private:
    double gen_random(int& index);

};

inline void Weights::gen_output(int n,int& index){
     for(int i = 0 ; i < n ; i++){
        single_output_weights.emplace_back(gen_random(index));
     }
}

// ********************************************* IMPLEMENTATION **********************************************

inline double Weights::gen_random(int& index){
  
// normal distribution media = 0, deviation = 1

    std::default_random_engine generator;
    
    //Normal number distribution -> Gaussian
	
	// He-Normal Initialization
   
    // Initialization for ReLU (Xavier initialization)
    
    // index start at 0 which is what I want and go to SIZE - 1 
   
    // I have to fix this 
    std::normal_distribution<double> distribution(0, sqrt(2.0 / (topology[index]))); // median and deviation

	// IMPORTANT DO NOT FORGET TO DIVIDE NOT 2 BUT 2.0 -> IF YOU DO NOT DO THAT IT WILL PERFORM A INT DIVISION 

    //Initialize with non-deterministic seeds
    generator.seed(std::random_device{}());


    return distribution(generator); 
}

inline void Weights::print_output_single_weights()const{
	for(auto& it : single_output_weights){
		std::cout<<it<<" ";
	}
	std::cout<<"\n";
}

// function to save the weights in a file 
inline void Weights::save_weights(std::ofstream& saved_weights){

    for(auto& it : single_output_weights){
		saved_weights << it << "\n";
	}
}
