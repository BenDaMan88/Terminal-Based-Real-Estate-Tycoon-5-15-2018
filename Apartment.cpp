/******************************************************************************
** Program Filename: Apartment.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Apartment.h"
#include <cstdlib>

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates an apartment.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
Apartment::Apartment()
{
  value = rand() % 300000 + 300000;
  duration_mortgage = (int) (value / mortgage);
  num_rooms = rand() % 10 + 1;
  num_tenants = num_rooms;
  rent = 500;
  tenants = new Tenant[num_rooms];
  for(int i = 0 ; i < num_rooms; i++)
  {
    tenants[i].calc_budget(true);
  }
}

/******************************************************************************
** Function: AOO
** Description: creates an apartment.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
const Apartment& Apartment::operator=(const Apartment &copy)
{
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
** Function: get rent
** Description: creates an apartment.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
float Apartment::get_rent()
{
  return rent;
}

/******************************************************************************
** Function: set rent
** Description: creates an apartment.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: rent set.
******************************************************************************/
void Apartment::set_rent(float rent)
{
  this->rent = rent;
}
