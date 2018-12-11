/******************************************************************************
** Program Filename: Main.cpp
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Event.h"

using namespace std;

//functions
void start_game();
void play_game(Player &p);
void next_turn(Player &p, int &counter);
void random_event(Player &p);

/******************************************************************************
** Function: Start Game
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Game is over.
******************************************************************************/
void start_game()
{
  cout << "\nWelcome to Real Estate Tycoon!" << endl;
  cout << "\nWhat is your name? ";
  string name;
  getline(cin, name);
  Player p(name);
  play_game(p);
}

/******************************************************************************
** Function: Play Game
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Game is over.
******************************************************************************/
void play_game(Player &p)
{
  int counter = 0;
  while(!p.game_over())
  {
    counter++;
    next_turn(p, counter);
    //p.set_account(p.get_account()+100000);
    p.print_account();
  }
}

/******************************************************************************
** Function: Next Turn
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Game is over.
******************************************************************************/
void next_turn(Player &p, int &counter)
{
  p.adjust_property_value();
  p.assess_tax(counter);
  p.pay_mortgage();
  p.remove_tenants();
  p.collect_rent();
  random_event(p);
  p.buy_property();
  p.sell_property();
  p.adjust_rent();
}

/******************************************************************************
** Function: Random Event
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: new event
******************************************************************************/
void random_event(Player &p)
{
    Event e;
    int num = e.get_random_event();
    if(num == 0) e.hurricane(p);
    if(num == 1) e.tornado(p);
    if(num == 2) e.earthquake(p);
    if(num == 3) e.wildfire(p);
    if(num == 4) e.stock_crash(p);
    if(num == 5) e.gentrification(p);
}

/******************************************************************************
** Function: Main
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Game is over.
******************************************************************************/
int main()
{
  srand(time(NULL));
  start_game();
}
