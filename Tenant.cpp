/******************************************************************************
** Program Filename: Tenant.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Tenant.h"
#include <cstdlib>

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates a tenant.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
Tenant::Tenant()
{
  agreeability_score = rand() % 5 + 1;
  is_there = true;
  monthy_rent = 500;
}

/******************************************************************************
** Function: calc_budget
** Description: random value.
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
void Tenant::calc_budget(bool citizen)
{
  if(citizen)
    monthy_rent = rand() % 4500 + 500;
  else
    monthy_rent = rand() % 8000 + 2000;
}

/******************************************************************************
** Function: is there
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
bool Tenant::get_is_there()
{
  return is_there;
}

/******************************************************************************
** Function: is there
** Description: setter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
void Tenant::set_is_there(bool is_there)
{
  this->is_there = is_there;
}

/******************************************************************************
** Function: agreeability_score
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
int Tenant::get_agreeability_score()
{
  return agreeability_score;
}

/******************************************************************************
** Function: rent
** Description: getter
** Parameters: citizen
** Pre-Conditions: None
** Post-Conditions: generates value.
******************************************************************************/
float Tenant::get_monthly_rent()
{
  return monthy_rent;
}
