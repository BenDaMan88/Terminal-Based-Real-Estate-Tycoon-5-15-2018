/******************************************************************************
** Program Filename: house.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Property.h"

#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

class House:public Property
{

  private:
    bool is_rented;
    float rent;

  public:
    House();
    const House& operator=(const House &copy);
    float get_rent();
    void set_rent(float rent);

};

#endif
