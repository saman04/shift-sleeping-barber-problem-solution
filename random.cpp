//
//  random.cpp
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#include "random.h"
#include <ctime>
#include <cstdlib>

//creates a random value upto the max limit.
int randomvalgen(int MaxLim)
{
    return (rand()% MaxLim + 1);
}
