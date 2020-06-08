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
    
    double gen_random();
    void gen_output(int n);
    void print_output_single_weights()const;
};

inline void Weights::gen_output(int n){
     for(int i = 0 ; i < n ; i++){
        single_output_weights.emplace_back(gen_random());
     }
}

inline double Weights::gen_random(){
  
  // min and max sohuldn't be too extream to avoid vanishing weigths

    //Type of random number distribution
    std::uniform_real_distribution<double> dist(0.1,0.9);  //(min, max)

    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng;

    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}());

    return dist(rng);
}

inline void Weights::print_output_single_weights()const{
    for(auto& it : single_output_weights){
    std::cout<<it<<" ";
  }
  std::cout<<"\n";
}
