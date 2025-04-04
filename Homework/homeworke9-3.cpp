/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Homework E9.3

This program implements a class Circuit to simulate a hallway light
that has switches at both ends of the hallway. Each switch can be up or down, and the 
light can be on or off. Toggling either switch turns the lamp on or off.
*/

#include <iostream>
using namespace std;

class Circuit
{
    public:
        Circuit(); //default constructor. both switches down (0) and light off
        int get_first_switch_state() const;  //0 for down, 1 for up
        int get_second_switch_state() const;
        int get_lamp_state() const; //0 for off, 1 for on
        void toggle_first_switch();
        void toggle_second_switch();
    private:
        bool lightSwitch1, lightSwitch2, lamp;
};

int main()
{
    Circuit light;
    cout << "First switch: " << light.get_first_switch_state() << endl;
    cout << "Second switch: " << light.get_second_switch_state() << endl;
    cout << "Lamp state: " << light.get_lamp_state() << endl;
    light.toggle_first_switch();
    cout << "First switch: " << light.get_first_switch_state() << endl;
    cout << "Second switch: " << light.get_second_switch_state() << endl;
    cout << "Lamp state: " << light.get_lamp_state() << endl;
    light.toggle_second_switch();
    cout << "First switch: " << light.get_first_switch_state() << endl;
    cout << "Second switch: " << light.get_second_switch_state() << endl;
    cout << "Lamp state: " << light.get_lamp_state() << endl;

    return 0;
}

Circuit::Circuit() 
{
    lightSwitch1 = lightSwitch2 = lamp = 0;
}

int Circuit::get_first_switch_state() const
{
    return lightSwitch1;
}

int Circuit::get_second_switch_state() const
{
    return lightSwitch2;
}

int Circuit::get_lamp_state() const
{
    return lamp;
}

void Circuit::toggle_first_switch()
{
    if(get_first_switch_state() == 1){
        lightSwitch1 = 0;
    }
    else {
        lightSwitch1 = 1;
    }
    if (get_lamp_state() == 1){
        lamp = 0;
    }
    else{
        lamp = 1;
    }
    //lamp is opp what it was
}

void Circuit::toggle_second_switch()
{
    if(get_second_switch_state() == 1){
        lightSwitch2 = 0;
    }
    else {
        lightSwitch2 = 1;
    }    
    
    if (get_lamp_state() == 1){
        lamp = 0;
    }
    else{
        lamp = 1;
    }
    //lamp is opp what it was
}