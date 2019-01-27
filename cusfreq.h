//
//  cusfreq.h
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#ifndef CUSTOMERFREQUENCY_H_INCLUDED
#define CUSTOMERFREQUENCY_H_INCLUDED
#include<thread>
#include "cuslist.h"

using namespace std;


void thread2(cuslist * cusl3,int & counter1);
//recursively call more threads to simulate the flow of customers.
void customerthread (cuslist * cusl2)
{
    int counter=1;
    while(true)
    {
     thread T2{thread2,cusl2,ref(counter)};
     this_thread::sleep_for(chrono::seconds(3));
     counter ++;
     T2.join();
    }
}
//create a single customers and link then to the queue.
void thread2(cuslist * cusl3,int & counter1)
{
    customer* a= new customer(counter1);
    cusl3->addtotail(a);
}


#endif
