/******************************************************************************
** Program Filename: player.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Player.h"
#include "Event.h"
#include "House.h"
#include "Apartment.h"
#include "Business_Complex.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: player object.
** Parameters: name
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
Player::Player(string name)
{
  this->name = name;
  account = 500000;
  num_houses = 0;
  num_apartments = 0;
  num_businesses = 0;
  houses = NULL;
  apartments = NULL;
  businesses = NULL;
  possible_setup();
}

/******************************************************************************
** Function: Destructor
** Description: player object.
** Parameters: name
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
Player::~Player()
{
  if(houses != NULL)
    delete [] houses;
  if(apartments != NULL)
    delete [] apartments;
  if(businesses != NULL)
    delete [] businesses;
  delete [] possible_houses;
  delete [] possible_apartments;
  delete [] possible_businesses;
  houses = NULL;
  apartments = NULL;
  businesses = NULL;
  possible_houses = NULL;
  possible_apartments = NULL;
  possible_businesses = NULL;
}

/******************************************************************************
** Function: Setup
** Description: player object.
** Parameters: name
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Player::possible_setup()
{
  num_possible_houses = 3;
  num_possible_apartments = 3;
  num_possible_businesses = 3;
  possible_houses = new House[num_possible_houses];
  possible_apartments = new Apartment[num_possible_apartments];
  possible_businesses = new Business_Complex[num_possible_businesses];
}

/******************************************************************************
** Function: game over
** Description: player object.
** Parameters: name
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
bool Player::game_over()
{
  if(account <= 0 || account >= 1000000)
    return true;
  return false;
}

/******************************************************************************
** Function: tax
** Description: ases tax.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Player::assess_tax(int &counter)
{
  if(counter == 12)
  {
    for(int i = 0; i < num_houses; i++)
    {
      account -= .015 * houses[i].get_property_value();
    }
    for(int i = 0; i < num_apartments; i++)
    {
      account -= .015 * apartments[i].get_property_value();
    }
    for(int i = 0; i < num_businesses; i++)
    {
      account -= .015 * businesses[i].get_property_value();
    }
  }
  counter = 0;
}

/******************************************************************************
** Function: value
** Description: adjust vlaue.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Player::adjust_property_value()
{
  for(int i = 0; i < num_businesses; i++)
  {
    int num = 0;
    for(int j = 0; j < businesses[i].get_num_rooms(); j++)
    {
      if(businesses[i].get_tenants()[j].get_is_there() &&
         businesses[i].get_tenants()[j].get_monthly_rent() >
         businesses[i].get_spaces()[j].rent)
        num++;
    }
    float increase = businesses[i].get_property_value() * num / 100;
    float new_value = businesses[i].get_property_value() + increase;
    businesses[i].set_property_value(new_value);
  }
}

/******************************************************************************
** Function: motgage
** Description: adjust vlaue.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
void Player::pay_mortgage()
{
  for(int i = 0; i < num_houses; i++)
  {
    if(houses[i].get_months_payed() < houses[i].get_duration_mortgage())
    {
      account -= houses[i].get_mortgage();
      houses[i].set_months_payed(houses[i].get_months_payed() + 1);
    }
  }
  for(int i = 0; i < num_apartments; i++)
  {
    if(apartments[i].get_months_payed() < apartments[i].get_duration_mortgage())
    {
      account -= apartments[i].get_mortgage();
      apartments[i].set_months_payed(apartments[i].get_months_payed() + 1);
    }
  }
  for(int i = 0; i < num_businesses; i++)
  {
    if(businesses[i].get_months_payed() < businesses[i].get_duration_mortgage())
    {
      account -= businesses[i].get_mortgage();
      businesses[i].set_months_payed(businesses[i].get_months_payed() + 1);
    }
  }
}

/******************************************************************************
** Function: rent
** Description: collects rent.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent collected.
******************************************************************************/
void Player::collect_rent()
{
  for(int i = 0; i < num_houses; i++)
  {
    if(houses[i].get_tenants()[0].get_is_there() &&
       houses[i].get_tenants()[0].get_monthly_rent() > houses[i].get_rent())
      account += houses[i].get_rent();
  }
  for(int i = 0; i < num_apartments; i++)
  {
    for(int j = 0; j < apartments[i].get_num_tenants(); j++)
    {
      if(apartments[i].get_tenants()[j].get_is_there() &&
         apartments[i].get_tenants()[j].get_monthly_rent() > apartments[i].get_rent())
        account += apartments[i].get_rent();
    }
  }
  for(int i = 0; i < num_businesses; i++)
  {
    for(int j = 0; j < businesses[i].get_num_rooms(); j++)
    {
      if(businesses[i].get_tenants()[j].get_is_there() &&
         businesses[i].get_tenants()[j].get_monthly_rent() > businesses[i].get_spaces()[j].rent)
        account += businesses[i].get_spaces()[j].rent;
    }
  }
}

/******************************************************************************
** Function: tenants
** Description: collects rent.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent collected.
******************************************************************************/
void Player::remove_tenants()
{
  for(int i = 0; i < num_houses; i++)
  {
    if(houses[i].get_tenants()[0].get_agreeability_score() > 2 && 
       houses[i].get_tenants()[0].get_monthly_rent() < houses[i].get_rent())
       houses[i].get_tenants()[0].set_is_there(false);
  }
  for(int i = 0; i < num_apartments; i++)
  {
    for(int j = 0; j < apartments[i].get_num_tenants(); j++)
    {
      if(apartments[i].get_tenants()[j].get_agreeability_score() > 2 && 
         apartments[i].get_tenants()[j].get_monthly_rent() < apartments[i].get_rent())
         apartments[i].get_tenants()[j].set_is_there(false);
    }
  }
  for(int i = 0; i < num_businesses; i++)
  {
    for(int j = 0; j < businesses[i].get_num_tenants(); j++)
    {
      if(businesses[i].get_tenants()[j].get_agreeability_score() > 2 && 
         businesses[i].get_tenants()[j].get_monthly_rent() < businesses[i].get_spaces()[j].rent)
         businesses[i].get_tenants()[j].set_is_there(false);
    }
  }
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
bool Player::can_adjust()
{
  if(num_houses == 0 && num_apartments == 0 && num_businesses == 0)
    return false;
  return true;
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
bool Player::can_adjust_house()
{
  if(num_houses > 0)
    return true;
  return false;
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
bool Player::can_adjust_apartment()
{
  if(num_apartments > 0)
    return true;
  return false;
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
bool Player::can_adjust_business()
{
  if(num_businesses > 0)
    return true;
  return false;
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
void Player::adjust_rent()
{
  if(!can_adjust()) return;
  cout << "\nDo you want to adjust the rent of any property? (y for yes, n for no): ";
  string input;
  getline(cin, input);
  while(input != "y" && input != "n")
  {
    cout << "invalid input. give valid input. ";
    getline(cin, input);
  }
  if(input == "n") return;
  bool flag = false;
  while(!flag)
  {
    cout << "\nWould you like to adjsut a house (h), apartment (a), or business (b)? ";
    getline(cin, input);
    while(input != "h" && input != "a" && input != "b")
    {
      cout << "invald input. Please give valid input. ";
      getline(cin, input);
    }
    if(input == "h" && can_adjust_house()) {adjust_house(); flag = true;}
    if(input == "a" && can_adjust_apartment()) {adjust_apartment(); flag = true;}
    if(input == "b" && can_adjust_business()) {adjust_business(); flag = true;}
  }
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
void Player::adjust_apartment()
{
  cout << endl;
  for(int i = 0; i < num_apartments; i++)
  {
    cout << i+1 << ". location: " <<apartments[i].get_location() << " property value: " <<
      apartments[i].get_property_value() << " mortgage: " << apartments[i].get_mortgage()
            << " duration of mortgage: " << apartments[i].get_duration_mortgage()
            << " rent: "<<apartments[i].get_rent() << endl;
  }
  cout << "\nWhich apartment's rent do you want to change? ";
  string input;
  getline(cin, input);
  while(!valid_input(input, num_apartments))
  {
    cout << "invalid input. give valid input. ";
    getline(cin, input);
  }
  int num = get_int(input) - 1;
  cout << "\nwhat is the new value for rent? ";
  getline(cin, input);
  while(!is_int(input))
  {
    cout << "invalid input. give valid input. ";
    getline(cin, input);
  }
  int new_rent = get_int(input);
  apartments[num].set_rent(new_rent);
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
void Player::adjust_house()
{
  cout << endl;
  for(int i = 0; i < num_houses; i++)
  {
    cout << i+1 << ". location: " << houses[i].get_location() << " property value: " <<
            houses[i].get_property_value() << " mortgage: " << houses[i].get_mortgage()
            << " duration of mortgage: " << houses[i].get_duration_mortgage()
            << " rent: "<<houses[i].get_rent() << endl;
  }
  cout << "\nWhich house's rent do you want to change? ";
  string input;
  getline(cin, input);
  while(!valid_input(input, num_houses))
  {
    cout << "invalid input. give valid input. ";
    getline(cin, input);
  }
  int num = get_int(input) - 1;
  cout << "\nwhat is the new value for rent? ";
  getline(cin, input);
  while(!is_int(input))
  {
    cout << "invalid input. give valid input. ";
    getline(cin, input);
  }
  int new_rent = get_int(input);
  houses[num].set_rent(new_rent);
}

/******************************************************************************
** Function: adjust
** Description: adjusts rent
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: rent adjusted..
******************************************************************************/
void Player::adjust_business()
{
  cout << endl;
  for(int i = 0; i < num_businesses; i++)
  {
    cout << i+1 << ". location: " << businesses[i].get_location() << " property value: " <<
      businesses[i].get_property_value() << " mortgage: " << businesses[i].get_mortgage()
            << " duration of mortgage: " << businesses[i].get_duration_mortgage() << " Spaces: ";
    for(int j = 0; j < businesses[i].get_num_rooms(); j++)
    {
      cout << j+1 << ". " << businesses[i].get_spaces()[j].rent << " ";
    }cout << endl;
  }
  cout << "\nWhich business' rent do you want to change? ";
  string input; getline(cin, input);
  while(!valid_input(input, num_businesses))
  {
    cout << "invalid input. give valid input. "; getline(cin, input);
  }
  int num = get_int(input) - 1;
  cout << "\nWhich space's rent do you want to change? "; getline(cin, input);
  while(!valid_input(input, businesses[num].get_num_rooms()))
  {
    cout << "invalid input. give valid input. "; getline(cin, input);
  }
  int index = get_int(input) - 1;
  cout << "\nwhat is the new value for rent? "; getline(cin, input);
  while(!is_int(input))
  {
    cout << "invalid input. give valid input. "; getline(cin, input);
  }
  int new_rent = get_int(input); businesses[num].get_spaces()[index].rent = new_rent;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
void Player::sell_property()
{
  cout << "\nDo you want to sell a property? (y for yes, n for no): ";
  string input; getline(cin, input);
  while(input != "y" && input != "n")
  {
    cout << "invald input. Please give valid input. ";
    getline(cin, input);
  }
  if(input == "n") return;
  cout << "\nwould you like to sell a house (h), apartment (a), or business (b)? ";
  getline(cin, input);
  while(input != "h" && input != "a" && input != "b")
  {
    cout << "invald input. Please give valid input. ";
    getline(cin, input);
  }
  if(input == "h") sell_house();
  if(input == "a") sell_apartment();
  if(input == "b") sell_business();
}

/******************************************************************************
** Function: is int
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::is_int(string input)
{
  if(input.length() < 1)
    return false;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] < '0' || input[i] > '9')
      return false;
  }
  if(get_int(input) <= 0)
    return false;
  return true;
}

/******************************************************************************
** Function: vlaid input
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::valid_input(string input, int num)
{
  if(input.length() < 1)
    return false;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] < '0' || input[i] > '9')
      return false;
  }
  if(get_int(input) > num || get_int(input) <= 0)
    return false;
  return true;
}

/******************************************************************************
** Function: get int
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
int Player::get_int(string input)
{
  int total = 0;
  for(int i = 0; i < input.length(); i++)
  {
    total += (input[i]-48) * pow(10, input.length() - i - 1);
  }
  return total;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_house()
{
  bool flag = false;
  for(int i = 0; i < num_houses; i++)
  {
    for(int j = 0; j < houses[i].get_num_tenants(); j++)
    {
        if(!houses[i].get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
    flag = false;
  }
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_apartment()
{
  bool flag = false;
  for(int i = 0; i < num_apartments; i++)
  {
    for(int j = 0; j < apartments[i].get_num_tenants(); j++)
    {
        if(!apartments[i].get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
  }
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_business()
{
  bool flag = false;
  for(int i = 0; i < num_businesses; i++)
  {
    for(int j = 0; j < businesses[i].get_num_tenants(); j++)
    {
        if(!businesses[i].get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
  }
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_house(House &h)
{
  bool flag = false;
    for(int j = 0; j < h.get_num_tenants(); j++)
    {
        if(!h.get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_apartment(Apartment &a)
{
  bool flag = false;
    for(int j = 0; j < a.get_num_tenants(); j++)
    {
        if(!a.get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
bool Player::can_sell_business(Business_Complex &b)
{
  bool flag = false;
    for(int j = 0; j < b.get_num_tenants(); j++)
    {
        if(!b.get_tenants()[j].get_is_there())
          flag = true;
    }
    if(!flag)
      return true;
  return false;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
void Player::sell_price(int value)
{
  cout << "\nWhat is your asking price? ";
  string input;
  getline(cin, input);
  while(!is_int(input))
  {
    cout << "invalid input. give me valid input. ";
    getline(cin, input);
  }
  int asking = get_int(input);
  int num = rand() % 3;
  if(num == 0) account += value * .9;
  if(num == 1) account += value;
  if(num == 2) account += asking;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
void Player::sell_house()
{
  if(!can_sell_house()) {cout << "\nYou can not sell any of your houses." <<endl; return;}
  for(int i = 0; i < num_houses; i++)
  {
    cout << i+1 << ". "; print_Possible_house(houses[i]);
  }
  int num = -1, counter = 0; bool flag = false;
  do
  {
    if(flag) cout << "You can't sell that house." << endl;
    cout << "\nWhich house would you like to sell? ";
    string input; getline(cin, input);
    while(!valid_input(input, num_houses))
    {
      cout << "invalid input. give valid input. "; getline(cin, input);
    }
    flag = true; num = get_int(input)-1;
  } while(!can_sell_house(houses[num]));
  int value = houses[num].get_property_value();
  sell_price(value);
  if(num_houses == 1) {delete [] houses; houses = NULL; num_houses = 0; return;}
  House* temp = new House[num_houses - 1];
  for(int i = 0; i < num_houses; i++)
  {
    if(i != num){temp[counter] = houses[i]; counter++;}
  }
  houses = temp; num_houses--;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
void Player::sell_apartment()
{
  if(!can_sell_apartment()) {cout << "\nYou can not sell any of your apartments." << endl; return;}
  for(int i = 0; i < num_apartments; i++)
  {
    cout << i+1 << ". "; print_possible_apartment(apartments[i]);
  }
  int num = -1, counter = 0; bool flag = false;
  do
  {
    if(flag) cout << "You can't sell that house." << endl;
    cout << "\nWhich house would you like to sell? ";
    string input; getline(cin, input);
    while(!valid_input(input, num_apartments))
    {
      cout << "invalid input. give valid input. "; getline(cin, input);
    }
    flag = true; num = get_int(input)-1;
  } while(!can_sell_apartment(apartments[num]));
  int value = apartments[num].get_property_value();
  sell_price(value);
  if(num_apartments == 1) {delete [] apartments; apartments = NULL; num_apartments = 0; return;}
  Apartment* temp = new Apartment[num_apartments - 1];
  for(int i = 0; i < num_apartments; i++)
  {
    if(i != num){temp[counter] = apartments[i]; counter++;}
  }
  apartments = temp; num_apartments--;
}

/******************************************************************************
** Function: sell
** Description:  sells property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property sold.
******************************************************************************/
void Player::sell_business()
{
    if(!can_sell_business()) {cout << "\nYou can not sell any of your businesses." << endl; return;}
    for(int i = 0; i < num_businesses; i++)
    {
      cout << i+1 << ". "; print_possible_business(businesses[i]);
    }
    int num = -1, counter = 0; bool flag = false;
    do
    {
      if(flag) cout << "You can't sell that house." << endl;
      cout << "\nWhich house would you like to sell? ";
      string input; getline(cin, input);
      while(!valid_input(input, num_businesses))
      {
        cout << "invalid input. give valid input. "; getline(cin, input);
      }
      flag = true; num = get_int(input)-1;
    } while(!can_sell_business(businesses[num]));
    int value = businesses[num].get_property_value();
    sell_price(value);
    if(num_businesses == 1) {delete [] businesses; businesses = NULL; num_businesses = 0; return;}
    Business_Complex* temp = new Business_Complex[num_businesses - 1];
    for(int i = 0; i < num_businesses; i++)
    {
      if(i != num){temp[counter] = businesses[i]; counter++;}
    }
    businesses = temp; num_businesses--;
}

/******************************************************************************
** Function: buy
** Description:  buy property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property bought.
******************************************************************************/
void Player::buy_property()
{
  cout << "\nDo you want to buy a property? (y for yes, n for no): ";
  string input; getline(cin, input);
  while(input != "y" && input != "n")
  {
    cout << "invald input. Please give valid input. ";
    getline(cin, input);
  }
  if(input == "n") return;
  int num1 = rand() % 3, num2 = rand() % 3, num3 = rand() % 3;
  cout << "\n1. House: "; print_Possible_house(possible_houses[num1]);
  cout << "2. Apartment: "; print_possible_apartment(possible_apartments[num2]);
  cout << "3. Business: "; print_possible_business(possible_businesses[num3]);
  cout << "\nwhich property would you like to buy? ";
  int num = get_property_input();
  if(num == 1) {add_house(possible_houses[num1]); House h; possible_houses[num1] = h;}
  if(num == 2) {add_apartment(possible_apartments[num2]); Apartment a; possible_apartments[num2] = a;}
  if(num == 3) {add_business(possible_businesses[num3]); Business_Complex b; possible_businesses[num3] = b;}
}

/******************************************************************************
** Function: buy
** Description:  buy property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property bought.
******************************************************************************/
void Player::add_house(House &h)
{
  num_houses++;
  House* temp = new House[num_houses];
  for(int i = 0; i < num_houses - 1; i++)
  {
    temp[i] = houses[i];
  }
  temp[num_houses-1] = h;
  if(houses != NULL)
    delete []  houses;
  houses = temp;
}

/******************************************************************************
** Function: buy
** Description:  buy property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property bought.
******************************************************************************/
void Player::add_apartment(Apartment &a)
{
  num_apartments++;
  Apartment* temp = new Apartment[num_apartments];
  for(int i = 0; i < num_apartments - 1; i++)
  {
    temp[i] = apartments[i];
  }
  temp[num_apartments-1] = a;
  if(apartments != NULL)
    delete [] apartments;
  apartments = temp;
}

/******************************************************************************
** Function: buy
** Description:  buy property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property bought.
******************************************************************************/
void Player::add_business(Business_Complex &b)
{
  num_businesses++;
  Business_Complex* temp = new Business_Complex[num_businesses];
  for(int i = 0; i < num_businesses - 1; i++)
  {
    temp[i] = businesses[i];
  }
  temp[num_businesses-1] = b;
  if(businesses != NULL)
    delete [] businesses;
  businesses = temp;
}

/******************************************************************************
** Function: input
** Description:  buy property.
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property bought.
******************************************************************************/
int Player::get_property_input()
{
  string input = "";
  getline(cin, input);
  while(input != "1" && input != "2" && input != "3")
  {
    cout << "invalid input. enter valid input. ";
    getline(cin, input);
  }
  if(input == "1") return 1;
  if(input == "2") return 2;
  if(input == "3") return 3;
}

/******************************************************************************
** Function: print
** Description:  print property
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property printed.
******************************************************************************/
void Player::print_Possible_house(House &h)
{
  cout << "location: " << h.get_location() << " property value: " <<
        h.get_property_value() << " mortgage: " << h.get_mortgage()
        << " duration of mortgage: " << h.get_duration_mortgage() << endl;
}

/******************************************************************************
** Function: print
** Description:  print property
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property printed.
******************************************************************************/
void Player::print_possible_apartment(Apartment &a)
{
  cout << "location: " << a.get_location() << " property value: " <<
        a.get_property_value() << " mortgage: " << a.get_mortgage()
        << " duration of mortgage: " << a.get_duration_mortgage() << endl;
}

/******************************************************************************
** Function: print
** Description:  print property
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property printed.
******************************************************************************/
void Player::print_possible_business(Business_Complex &b)
{
  cout << "location: " << b.get_location() << " property value: " <<
        b.get_property_value() << " mortgage: " << b.get_mortgage()
        << " duration of mortgage: " << b.get_duration_mortgage() << endl;
}

/******************************************************************************
** Function: print
** Description:  print property
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: property printed.
******************************************************************************/
void Player::print_property()
{
  for(int i = 0; i < 3; i++)
  {
    cout <<"House: " <<possible_houses[i].get_property_value() <<" " << 
    possible_houses[i].get_location() <<" " << possible_houses[i].get_mortgage() 
    << " "<< possible_houses[i].get_duration_mortgage()<< endl;
    cout << "Apartment: " << possible_apartments[i].get_property_value() <<" " 
    << possible_apartments[i].get_location() <<" "<<possible_apartments[i].get_mortgage() 
    <<" "<< possible_apartments[i].get_duration_mortgage()<< endl;
    cout << "Busines: " << possible_businesses[i].get_property_value() <<" " <<
     possible_businesses[i].get_location() <<" "<<possible_businesses[i].get_mortgage() 
     <<" "<< possible_businesses[i].get_duration_mortgage()<< endl;
  }
}

/******************************************************************************
** Function: print
** Description:  print account
** Parameters: counter
** Pre-Conditions: None
** Post-Conditions: account printed.
******************************************************************************/
void Player::print_account()
{
  cout << "\n" << name << "'s Account Value: " << account << endl;
  cout << "\n=========================================================" << endl;
}

/******************************************************************************
** Function: setter
** Description:  sets value
** Parameters: new value.
** Pre-Conditions: None
** Post-Conditions:value set.
******************************************************************************/
void Player::set_account(int num)
{
  account = num;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
int Player::get_account()
{
  return account;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
int Player::get_num_houses()
{
  return num_houses;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
int Player::get_num_apartments()
{
  return num_apartments;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
int Player::get_num_businesses()
{
  return num_businesses;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
House* Player::get_houses()
{
  return houses;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
Apartment* Player::get_apartments()
{
  return apartments;
}

/******************************************************************************
** Function: getter
** Description:  returns value
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions:value returned.
******************************************************************************/
Business_Complex* Player::get_businesses()
{
  return businesses;
}