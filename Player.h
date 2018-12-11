/******************************************************************************
** Program Filename: player.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "House.h"
#include "Apartment.h"
#include "Business_Complex.h"
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{

  private:
    string name;
    int account;
    House* houses;
    Apartment* apartments;
    Business_Complex* businesses;
    int num_houses;
    int num_apartments;
    int num_businesses;
    House* possible_houses;
    Apartment* possible_apartments;
    Business_Complex* possible_businesses;
    int num_possible_houses;
    int num_possible_apartments;
    int num_possible_businesses;

  public:
    Player(string name);
    ~Player();
    void assess_tax(int &counter);
    bool game_over();
    void set_account(int num);
    int get_account();
    void possible_setup();
    void print_property();
    void adjust_property_value();
    void pay_mortgage();
    void collect_rent();
    void remove_tenants();
    bool can_adjust();
    bool can_adjust_house();
    bool can_adjust_apartment();
    bool can_adjust_business();
    void adjust_rent();
    void adjust_house();
    void adjust_apartment();
    void adjust_business();
    void buy_property();
    void sell_property();
    void sell_house();
    void sell_apartment();
    void sell_business();
    bool can_sell_house();
    bool can_sell_business();
    bool can_sell_apartment();
    bool can_sell_house(House &h);
    bool can_sell_apartment(Apartment &a);
    bool can_sell_business(Business_Complex &b);
    void print_Possible_house(House &h);
    void print_possible_apartment(Apartment &a);
    void print_possible_business(Business_Complex &b);
    int get_property_input();
    void add_house(House &h);
    void add_apartment(Apartment &a);
    void add_business(Business_Complex &b);
    bool valid_input(string input, int num);
    bool is_int(string input);
    int get_int(string input);
    void sell_price(int value);
    void print_account();
    int get_num_houses();
    int get_num_apartments();
    int get_num_businesses();
    House* get_houses();
    Apartment* get_apartments();
    Business_Complex* get_businesses();

};

#endif
