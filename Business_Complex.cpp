/******************************************************************************
** Program Filename: Business_Complex.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Business_Complex.h"
#include <cstdlib>
#include "space.h"

using namespace std;

/******************************************************************************
** Function: constructor
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
Business_Complex::Business_Complex()
{
    value = rand() % 200000 + 400000;
    duration_mortgage = (int) (value / mortgage);
    num_rooms = rand() % 5  + 1;
    num_tenants = num_rooms;
    tenants = new Tenant[num_rooms];
    spaces = new space[num_rooms];
    rent = 500;
    for(int i = 0 ; i < num_rooms; i++)
    {
      tenants[i].calc_budget(true);
      spaces[i].size = "small";
      spaces[i].rent = 2000;
    }
}

/******************************************************************************
** Function: AOO
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
const Business_Complex& Business_Complex::operator=(const Business_Complex &copy)
{
  value = copy.value;
  location = copy.location;
  mortgage = copy.mortgage;
  num_rooms = copy.num_rooms;
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
  if(spaces != NULL)
    delete [] spaces;
  spaces = new space[num_rooms];
  for(int i = 0; i < num_rooms; i++)
  {
    spaces[i] = copy.spaces[i];
  }
}

Business_Complex::~Business_Complex()
{
  if(spaces != NULL)
    delete [] spaces;
}

/******************************************************************************
** Function: num rooms
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Business_Complex::get_num_rooms()
{
  return num_rooms;
}

/******************************************************************************
** Function: spaces
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
space* Business_Complex::get_spaces()
{
  return spaces;
}
