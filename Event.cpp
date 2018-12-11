/******************************************************************************
** Program Filename: Event.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Event.h"

using namespace std;

/******************************************************************************
** Function: Event constructor
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
Event::Event()
{
  
}

/******************************************************************************
** Function: Event 1
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::hurricane(Player &p)
{
  cout << "\nA hurricane occured!" << endl;
  for(int i = 0; i < p.get_num_houses(); i++)
  {
    if(p.get_houses()[i].get_location() == "SE")
    {
      int num = p.get_houses()[i].get_property_value() 
               -p.get_houses()[i].get_property_value() * .5;
      p.get_houses()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_apartments(); i++)
  {
    if(p.get_apartments()[i].get_location() == "SE")
    {
      int num = p.get_apartments()[i].get_property_value() 
               -p.get_apartments()[i].get_property_value() * .5;
      p.get_apartments()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_businesses(); i++)
  {
    if(p.get_businesses()[i].get_location() == "SE")
    {
      int num = p.get_businesses()[i].get_property_value() 
               -p.get_businesses()[i].get_property_value() * .5;
      p.get_businesses()[i].set_property_value(num);
    }
  }
}

/******************************************************************************
** Function: Event 2
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::tornado(Player &p)
{
  cout << "\nA tornado occured!" << endl;
  for(int i = 0; i < p.get_num_houses(); i++)
  {
    if(p.get_houses()[i].get_location() == "MW")
    {
      int num = p.get_houses()[i].get_property_value() 
               -p.get_houses()[i].get_property_value() * .3;
      p.get_houses()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_apartments(); i++)
  {
    if(p.get_apartments()[i].get_location() == "MW")
    {
      int num = p.get_apartments()[i].get_property_value() 
               -p.get_apartments()[i].get_property_value() * .3;
      p.get_apartments()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_businesses(); i++)
  {
    if(p.get_businesses()[i].get_location() == "MW")
    {
      int num = p.get_businesses()[i].get_property_value() 
               -p.get_businesses()[i].get_property_value() * .3;
      p.get_businesses()[i].set_property_value(num);
    }
  }
}

/******************************************************************************
** Function: Event 3
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::earthquake(Player &p)
{
    cout << "\nA earthquake occured!" << endl;
    for(int i = 0; i < p.get_num_houses(); i++)
    {
      if(p.get_houses()[i].get_location() == "NW")
      {
        int num = p.get_houses()[i].get_property_value() 
                 -p.get_houses()[i].get_property_value() * .1;
        p.get_houses()[i].set_property_value(num);
      }
    }
    for(int i = 0; i < p.get_num_apartments(); i++)
    {
      if(p.get_apartments()[i].get_location() == "NW")
      {
        int num = p.get_apartments()[i].get_property_value() 
                 -p.get_apartments()[i].get_property_value() * .1;
        p.get_apartments()[i].set_property_value(num);
      }
    }
    for(int i = 0; i < p.get_num_businesses(); i++)
    {
      if(p.get_businesses()[i].get_location() == "NW")
      {
        int num = p.get_businesses()[i].get_property_value() 
                 -p.get_businesses()[i].get_property_value() * .1;
        p.get_businesses()[i].set_property_value(num);
      }
    }
}

/******************************************************************************
** Function: Event 4
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::wildfire(Player &p)
{
    cout << "\nA wildfire occured!" << endl;
    for(int i = 0; i < p.get_num_houses(); i++)
    {
      if(p.get_houses()[i].get_location() == "SW")
      {
        int num = p.get_houses()[i].get_property_value() 
                 -p.get_houses()[i].get_property_value() * .25;
        p.get_houses()[i].set_property_value(num);
      }
    }
    for(int i = 0; i < p.get_num_apartments(); i++)
    {
      if(p.get_apartments()[i].get_location() == "SW")
      {
        int num = p.get_apartments()[i].get_property_value() 
                 -p.get_apartments()[i].get_property_value() * .25;
        p.get_apartments()[i].set_property_value(num);
      }
    }
    for(int i = 0; i < p.get_num_businesses(); i++)
    {
      if(p.get_businesses()[i].get_location() == "SW")
      {
        int num = p.get_businesses()[i].get_property_value() 
                 -p.get_businesses()[i].get_property_value() * .25;
        p.get_businesses()[i].set_property_value(num);
      }
    }
}

/******************************************************************************
** Function: Event 5
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::stock_crash(Player &p)
{
  cout << "\nThe stock market crashed" << endl;
  for(int i = 0; i < p.get_num_houses(); i++)
  {
      int num = p.get_houses()[i].get_property_value() 
               -p.get_houses()[i].get_property_value() * .3;
      p.get_houses()[i].set_property_value(num);
  }
  for(int i = 0; i < p.get_num_apartments(); i++)
  {
      int num = p.get_apartments()[i].get_property_value() 
               -p.get_apartments()[i].get_property_value() * .3;
      p.get_apartments()[i].set_property_value(num);
  }
  for(int i = 0; i < p.get_num_businesses(); i++)
  {
      int num = p.get_businesses()[i].get_property_value() 
               -p.get_businesses()[i].get_property_value() * .3;
      p.get_businesses()[i].set_property_value(num);
  }
}

/******************************************************************************
** Function: Event 6
** Description: goes through all things for event number.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
void Event::gentrification(Player &p)
{
  cout << "\ngentrification occured" << endl;
  int num = rand() % 5;
  string locations[] = {"SE", "SW", "NE", "NW", "Midwest"};
  string location = locations[num];
  for(int i = 0; i < p.get_num_houses(); i++)
  {
    if(p.get_houses()[i].get_location() == location)
    {
      int num = p.get_houses()[i].get_property_value() 
               +p.get_houses()[i].get_property_value() * .2;
      p.get_houses()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_apartments(); i++)
  {
    if(p.get_apartments()[i].get_location() == location)
    {
      int num = p.get_apartments()[i].get_property_value() 
               +p.get_apartments()[i].get_property_value() * .2;
      p.get_apartments()[i].set_property_value(num);
    }
  }
  for(int i = 0; i < p.get_num_businesses(); i++)
  {
    if(p.get_businesses()[i].get_location() == location)
    {
      int num = p.get_businesses()[i].get_property_value() 
               +p.get_businesses()[i].get_property_value() * .2;
      p.get_businesses()[i].set_property_value(num);
    }
  }
}

/******************************************************************************
** Function: Random Event
** Description: generates random evemt.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
int Event::get_random_event()
{
  return rand() % 6;
}

