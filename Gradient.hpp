//
//  Gradient.hpp
//  First_AI_project 
//
//  Created by Jacopo Zacchigna on 31/01/2021.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once

#include "Net.hpp"

// ********************************************* DEFINITION **********************************************

class Gradient : public Net {
  public:
	Gradient(); // The constructor should get as parameter The Net and informations about the episode 
	void Loss();
	void BackProp();
  protected:
	// activation function derivative in protected maybe
};
