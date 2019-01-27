//
//  main.cpp
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//

#include <iostream>
using namespace std;

#include<thread>
#include "random.h"
#include "cusfreq.h"
#include "barstatus.h"

//we have a thread T1 responsible for creating more threads T2 to simulate the flow of customers
//we have a thread T3 imitating the barber which performs the 3 tasks sleeping, waking up and working.
/* * Note: In case of compiler issue due to thread library.. kindly do the following... project-> build options-> select the C++11 compiler.
 */
int main()
{
    int seats;
    
    cout<<"Enter Size of the Waiting Room: ";
    cin>>seats;
    cout<<endl;
    
    cuslist * cusl= new cuslist(seats + 1);
    
    thread T3{barstatus,cusl};
    thread T1{customerthread,cusl};
    
    T1.join();
    T3.join();
    
    return 0;
}
