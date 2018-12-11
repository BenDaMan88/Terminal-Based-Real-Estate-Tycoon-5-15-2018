/******************************************************************************
** Program Filename: Property.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Property.h"
#include <cstdlib>

/******************************************************************************
** Function: Constructor
** Description: property
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
Property::Property()
{
  int num = rand() % 5;
  if(num == 0) location = "SE";
  if(num == 1) location = "NE";
  if(num == 2) location = "MW";
  if(num == 3) location = "SW";
  if(num == 4) location = "NW";
  mortgage = rand() % 5000 + 1;
  months_payed = 0;
  bought = false;
}

/******************************************************************************
** Function: Destructor
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
Property::~Property()
{
  if(tenants != NULL)
  {
    delete [] tenants;
    tenants = NULL;
  }
}
/******************************************************************************
** Function: AOO
** Description: asginment
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
const Property& Property::operator=(const Property &copy)
{
  value = copy.value;
  location = copy.location;
  mortgage = copy.mortgage;
  num_tenants = copy.num_tenants;
  duration_mortgage = copy.duration_mortgage;
  months_payed = copy.months_payed;
  bought = copy.bought;
  if(tenants != NULL)
  {
    delete [] tenants;
    tenants = NULL;
  }  
  tenants = new Tenant[num_tenants];
  for(int i = 0; i < num_tenants; i++)
  {
    tenants[i] = copy.tenants[i];
  }
}

/******************************************************************************
** Function: property_value
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
float Property::get_property_value()
{
  return value;
}

/******************************************************************************
** Function: mortgage
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
float Property::get_mortgage()
{
  return mortgage;
}

/******************************************************************************
** Function: location.
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
string Property::get_location()
{
  return location;
}

/******************************************************************************
** Function: get_duration_mortgage
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Property::get_duration_mortgage()
{
  return duration_mortgage;
}

/******************************************************************************
** Function: num_tenants
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
Tenant* Property::get_tenants()
{
  return tenants;
}

/******************************************************************************
** Function: num_tenants
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Property::get_num_tenants()
{
  return num_tenants;
}

/******************************************************************************
** Function: months_payed
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Property::get_months_payed()
{
  return months_payed;
}

/******************************************************************************
** Function: bought
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
bool Property::get_bought()
{
  return bought;
}

/******************************************************************************
** Function: set bought
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Property::set_bought(bool bought)
{
  this->bought = bought;
}

/******************************************************************************
** Function: property_value
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Property::set_property_value(float value)
{
  this->value = value;
}

/******************************************************************************
** Function: months payed.
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Property::set_months_payed(int months)
{
  months_payed = months;
}
