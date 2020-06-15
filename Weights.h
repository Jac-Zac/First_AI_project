//
//  Weights.h
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 24/05/2020.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once
#include"da_includere.h"

class Weights{
public:
    std::vector<double> single_output_weights;
    
    void gen_output(int n, int& index); // this function generate the output weights and fill single_output_weights
    double gen_random(int& index);
    void print_output_single_weights()const;
};

inline void Weights::gen_output(int n,int& index){
     for(int i = 0 ; i < n ; i++){
        single_output_weights.emplace_back(gen_random(index));
     }
}

inline double Weights::gen_random(int& index){
  
// normal distribution media = 0, diviation = 1

    std::default_random_engine generator;
    
    //Normal number distributon -> gaussian
    std::normal_distribution<double> distribution(0,1); // median and deviationn     

    //Initialize with non-deterministic seeds
    generator.seed(std::random_device{}());

    // Inizialization for ReLu (Xavier initialization)
    
    // index start at 0 which is what I want and go to SIZE - 2
    
    // I have to fix this 
    return distribution(generator)*sqrt(2/topology[index]);
}

inline void Weights::print_output_single_weights()const{
    for(auto& it : single_output_weights){
    std::cout<<it<<" ";
  }
  std::cout<<"\n";
}
