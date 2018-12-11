/******************************************************************************
** Program Filename: Property.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Tenant.h"
#include <string>

#ifndef PROPERTY_H
#define PROPERTY_H

using namespace std;

class Property
{

  protected:
    float value;
    string location;
    float mortgage;
    int num_tenants;
    Tenant* tenants;
    int duration_mortgage;
    int months_payed;
    bool bought;

  public:
    Property();
    ~Property();
    const Property& operator=(const Property &copy);
    void assign_location();
    float get_property_value();
    float get_mortgage();
    string get_location();
    int get_duration_mortgage();
    Tenant* get_tenants();
    int get_num_tenants();
    int get_months_payed();
    bool get_bought();
    void set_bought(bool bought);
    void set_property_value(float value);
    void set_months_payed(int months);

};

#endif
