//
//  customer.cpp
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#include<iostream>
using namespace std;
#include "random.h"
#include "customer.h"


//Caculating the amount of time for each haircut between [1,5] and seeting the max limit to 5 as specified .

customer::customer(int n):id(n), next(NULL)
{
    hairCutTime= randomvalgen(5);
}

