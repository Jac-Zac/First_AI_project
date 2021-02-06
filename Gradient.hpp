//
//  Gradient.hpp
//  AI_Tria 2.0
//
//  Created by Jacopo Zacchigna on 31/01/2021.
//  Copyright © 2020 Jacopo Zacchigna. All rights reserved.
//

#pragma once

#include "Net.hpp"
#include "AI.hpp"

// ********************************************* DEFINITION **********************************************

class Gradient : public Net {
  public:
    Gradient(); // The constructor should get as parameter The Net and informations about the episode 
  protected:
	void Loss();
	void BackProp();
}

// ********************************************* DEFINITION **********************************************

// constructor
inline Gradient::Gradient() {
}
