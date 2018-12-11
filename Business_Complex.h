/******************************************************************************
** Program Filename: Business_Complex.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Property.h"
#include "space.h"

#ifndef BUSINESS_COMPLEX
#define BUSINESS_COMPLEX

using namespace std;

class Business_Complex:public Property
{

  private:
    bool is_empty;
    int num_rooms;
    space* spaces;
    float rent;

  public:
    Business_Complex();
    ~Business_Complex();
    const Business_Complex& operator=(const Business_Complex &copy);
    void increase_property_value();
    int get_num_rooms();
    space* get_spaces();

};

#endif
