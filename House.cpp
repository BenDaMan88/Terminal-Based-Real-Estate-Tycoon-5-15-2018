/******************************************************************************
** Program Filename: house.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "House.h"
#include "Property.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/******************************************************************************
** Function: constructor
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
House::House()
{
  is_rented = true;
  value = rand() % 500000 + 100000;
  duration_mortgage = (int) (value / mortgage);
  num_tenants = 1;
  tenants = new Tenant[1];
  tenants[0].calc_budget(true);
  rent = 500;
}

/******************************************************************************
** Function: AOO
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
const House& House::operator=(const House &copy)
{
  this->is_rented = copy.is_rented;
  value = copy.value;
  location = copy.location;
  mortgage = copy.mortgage;
  num_tenants = copy.num_tenants;
  duration_mortgage = copy.duration_mortgage;
  months_payed = copy.months_payed;
  bought = copy.bought;
  rent = copy.rent;
  if(tenants != NULL)
    delete [] tenants;
  tenants = new Tenant[num_tenants];
  for(int i = 0; i < num_tenants; i++)
  {
    tenants[i] = copy.tenants[i];
  }
}

/******************************************************************************
** Function: rent
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
float House::get_rent()
{
  return rent;
}

/******************************************************************************
** Function: set rent
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void House::set_rent(float rent)
{
  this->rent = rent;
}
