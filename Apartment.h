/******************************************************************************
** Program Filename: Property.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Property.h"

#ifndef APARTMENT_H
#define APARTMENT_H

using namespace std;

class Apartment:public Property
{

  private:
    bool is_empty;
    int num_rooms;
    float rent;

  public:
    Apartment();
    const Apartment& operator=(const Apartment &copy);
    float get_rent();
    void set_rent(float rent);

};

#endif
