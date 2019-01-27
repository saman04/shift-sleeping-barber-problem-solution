//
//  customer.h
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
using namespace std;

//creates a customer node that stores the customer id, haircut time and a next customer pointer.
class customer
{
    friend class cuslist;

    public:

      customer(int);

    public:
      int id,hairCutTime;
      customer* next;
};



#endif 
