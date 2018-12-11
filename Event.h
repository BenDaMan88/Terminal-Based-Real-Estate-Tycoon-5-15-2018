/******************************************************************************
** Program Filename: Event.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Player.h"

#ifndef EVENT_H
#define EVENT_H

using namespace std;

class Event
{

  private:

  public:
    Event();
    int get_random_event();
    void hurricane(Player &p);
    void tornado(Player &p);
    void earthquake(Player &p);
    void wildfire(Player &p);
    void stock_crash(Player &p);
    void gentrification(Player &p);

};

#endif
