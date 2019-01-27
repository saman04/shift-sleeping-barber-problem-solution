//
//  cuslist.cpp
//  shift-barber-problem
//
//  Created by Saman Arora on 1/26/19.
//  Copyright © 2019 Saman Arora. All rights reserved.
//
#include "cuslist.h"
#include "customer.h"

/* * defined 2 extra variables first and check. First is used to monitor if someone new comes in and wakes up  the barber. Check is used to monitor if a customer has left the barbers shop without getting a haircut(display purpose).
*/

using namespace std;
cuslist::cuslist(int n): maxSeats(n),head(NULL), tail(NULL), size(0),first(0),check(0)
{}

// addtotail is responsible for enqueueing new customers to the queue.
void cuslist::addtotail(customer* newOne)
{

  if(head != NULL && size <= maxSeats)
    {
         tail->next = newOne;
         tail=newOne;
         size++;
         first = 0;
    }

    else if(head == NULL)
    {
         head = newOne;
         tail = newOne;
         size++;
         first = 3;
    }


   else
   {
        check = newOne->id;
   }
}
// this prints the Waiting room Queue and also the customers that left without getting their hair cut if no seats available in waiting room.
void cuslist::printwaitingroom()
{
    customer*tp=head;
    cout<<"Waiting Room: ";
    if(tp)
        {
        tp=tp->next;
        while(tp!=0)
            {
                cout<<tp->id<<" ";
                tp=tp->next;
            }
        }
    cout<<" "<<endl;

    if(check)
        {
            cout<<"Customer " << check << " leaving"<<endl;
            check=0;
        }
    cout<<" "<<endl;
}

void cuslist::completedhaircut()
{
 if (head==tail)   //If there is only one customer. we reintialize pointers so that barber status is changed to sleep.
    {
        head=NULL;
        tail=NULL;
        first = 1;
        size--;
    }
    else if(head!=tail)// If there are more than one customers then move to the next customer.
    {
        head=head->next;
        size--;
    }

}

