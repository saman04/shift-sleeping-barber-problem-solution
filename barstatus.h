//
//  barstatus.h
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#ifndef BARBERSTATUS_H_INCLUDED
#define BARBERSTATUS_H_INCLUDED
#include<thread>

#include "customer.h"



//Barber Status. As given Barber can either sleep, wakeup, or cut the hair of a single customer.
void barstatus (cuslist * cusl4)
{
    cout<<"Barber is sleeping"<<endl;   //initial position of the barber
    cusl4->printwaitingroom();
    while (true)
    {
        customer* status= cusl4->gethead();
        int flag=cusl4->getcheck();

           if (status==NULL && flag==1)  //SLEEPING: here we checks if the head pointer in cuslist is NULL.
           {
               cout<<"Barber is sleeping"<<endl;
               cusl4->printwaitingroom();
               cusl4->setcheck();
           }

           else if (flag==3)   //WAKING UP: flag= 3 indicates that a new customer has arrived. Hence the barber needs to gets up and cut the hair of the customer. Once the haircut is done we terminate the the thread of the customer by using completehaircut function.
           {
                cout<<"Barber is Waking up "<< endl;
                cusl4->setcheck();
                cout<<"Barber is cutting the hair of customer "<<cusl4->getid()<<endl;
                cusl4->printwaitingroom();
                int a =cusl4->gettime();
                this_thread::sleep_for(chrono::seconds(a));
                cusl4->completedhaircut();
            }

            else if(status !=NULL)  //WORKING: if currently barber is busy it will inform the user that the barber is busy so that the program is able to add the new customer to a new postion in the waiting room.
            {
               cout<<"Barber is cutting the hair of customer "<<cusl4->getid()<<endl;
               cusl4->printwaitingroom();
               int a =cusl4->gettime();
               this_thread::sleep_for(chrono::seconds(a));
               cusl4->completedhaircut();
            }
    }
}





#endif 
