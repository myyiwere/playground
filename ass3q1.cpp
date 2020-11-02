#include <iostream> //preprocessor for input/ouput
#include <cmath>    //include library for math functions
//Declare variables to be used
double y_inc;  //yearly income
double m_inc;  //monthly income
double state_tax;  //state taxes
double ret;  //retirement deductions
double soc_sec;  //social security and medical deductions
double fed; //federal taxes
double utilities;  //total monthly utility cost
double water;  //monthly water bill
double b_water = 17.25;  //monthly base water bill
double u_water;  //unit water cost
double gas;  //monthly gas bill
double b_gas = 10;  //monthly base gas bill
double u_gas = 1.0964;  //unit gas cost
double elec;  //monthly electricity bill
double b_elec = 14;  //monthly base electricity bill
double u_elec = 0.07948;  //unit electricity cost
double cable;  //monthly cable and internet bill
double b_cable = 74.99;  //monthly base cable and internet bill
double u_cable = 4.49;  //unit cable and internet cost
double food = 350;  //monthly food bill
double d_milage;  //daily car milage
double car;  //monthly car bill
double b_car = 158;  //monthly base car bill
double u_car = 0.081;  //unit gas cost per mile for car
double take_home; //take-home salary

//main function here
int main(){
    //get user yearly income
    std::cout<<"What is your gross yearly income?: \n";
    std::cin>>y_inc;
    m_inc = y_inc/12;   //compute gross monthly income
    std::cout<<"Gross Monthly Income: "<<m_inc<<std::endl;
    //get user gas usage
    std::cout<<"How many units of gas did you use this month?: \n";
    std::cin>>gas;
    //get user electricity usage
    std::cout<<"How many units of electricity did you use this month?: \n";
    std::cin>>elec;
    //get user movie rental usage
    std::cout<<"How many movies did you rent this month?: \n";
    std::cin>>cable;
    //get user water usage
    std::cout<<"How many units of water did you use this month?: \n";
    std::cin>>water;
    //get user daily car milage
    std::cout<<"How many miles per day do you drive?: \n";
    std::cin>>d_milage;
    //compute monthly car milage
    car = 30 * d_milage;
    state_tax = m_inc * 0.1;    //compute state taxes
    ret = m_inc * 0.06;  //compute retirement deductions
    soc_sec = m_inc * 0.04; //compute social security and medical deductions

    //compute federal tax deductions
    if (y_inc > 510300)
        fed = m_inc * 0.37;
    else if (y_inc > 204100)
        fed = m_inc * 0.35;
    else if (y_inc > 160725)
        fed = m_inc * 0.32;
    else if (y_inc > 82400)
        fed = m_inc * 0.24;
    else if (y_inc > 39475)
        fed = m_inc * 0.22;
    else if (y_inc > 9700)
        fed = m_inc * 0.12;
    else
        fed = m_inc * 0.1; 

    //compute total utility cost
    //set unit cost for water
    if(water<=6)
        u_water = 2.17; 
    else
        u_water = 3.12;
    water = u_water * water + b_water; //compute water bill
    gas = u_gas * gas + b_gas; //compute gas bill
    elec = u_elec * elec + b_elec;   //compute electricity bill
    cable = u_cable * cable + b_cable;  //compute cable & internet bill
    car = car * u_car + b_car;  //compute car bill
    utilities = water + gas + elec + cable + car +food;

    //compute take-home salary
    take_home = m_inc - fed - state_tax - soc_sec - ret - utilities;
    if(take_home<0)
        std::cout<<"You don't have enough money to pay your bills.\n";
    else
        std::cout<<"Your take-home salary is: "<<take_home<<std::endl;

    return 0;
}
