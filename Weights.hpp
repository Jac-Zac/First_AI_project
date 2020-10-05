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
    double copy_weights(int& index , std::ifstream& previous_weights);

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

// instead of filling the layer with random weight the weight are cherry pick from the previous_weight
inline double Weights::copy_weights(int& index, std::ifstream& previous_weights){
// ********** TESTING 
    float w; // w is a sing weight 

// INVECE DI USARE QUESTA FUNZIONE POSSO ACCEDERCI DIRETTAMENTE DA LAYER.HPP FILE NELLA FUNZIONE COPY LAYER PENSO ! DA PROVARE

// IDEA 
// un idea può essere di leggere i pesi scendendo una linea alla volta ATTENZIONE PERO BISOGNA SALAVARLI NEL POSTO NELLE VARIABILI GIUSTE DOPO TENEDO ANCHE CONTO DELL INDEX 
	
//     while(previous_weights.good()){ // I have to loop through as enough time base on the layer  
//		std::getline(previous_weights, w, ' '); // use ' ' as separator, default is '\n' (newline). Now the first number is saved in w.
	previous_weights >> w; 
	std::cout << w << " ";
	// 	previous_weights >> word;
  //   }
// *************************	
//
//
// std::cout<<"I will save the weights ! But for now I'm just a tester \n";
// I think that maybe I shouldn't pass the previous weight still but only a cut down portion -> the cut should occur before 
//
// *****************
return 9; // for now -> 9 is to now it has been filled 
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

	saved_weights<<"\n";
}
