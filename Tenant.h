/******************************************************************************
** Program Filename: Tenant.h
** Author: Ben Johnson
** Date: May 14, 2018
** Description: real estate tycoon.
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

using namespace std;

#ifndef TENANT_H
#define TENANT_H

class Tenant
{

  private:
    float agreeability_score;
    float monthy_rent;
    bool is_there;

  public:
    Tenant();
    void calc_budget(bool citizen);
    bool get_is_there();
    void set_is_there(bool is_there);
    int get_agreeability_score();
    float get_monthly_rent();
};

#endif
