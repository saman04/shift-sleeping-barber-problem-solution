//
//  cuslist.h
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include "customer.h"
//We create an object class cuslist to mimic the queue at the barbers shop.
class cuslist
{
    public:
        cuslist(int);
        void addtotail(customer* newOne);
        void printwaitingroom();
        void completedhaircut();
        customer* gethead(){return head;}
        int getid(){return head->id;}
        int gettime(){return head->hairCutTime;}
        int getcheck(){return first;}
        void setcheck(){first=0;}

    public:
        customer* head;
        customer* tail;
        int size, maxSeats,first,check;
};

#endif 
