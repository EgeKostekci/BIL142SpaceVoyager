//
// Created by ÖMER EGE on 11.03.2024.
//

#include "../inc/ship.h"
#include <iostream>
#include <windows.h>
#include <memory>


IShip::~IShip(){
    std::cout<<"Game is finished this is your score:"<<(this->fuel*5)+(this->health*10)+(this->money*10)<<"\n";
    Sleep(1000);
    std::cout<<"\n \nTHANK YOU FOR PLAYING \nSPACE VOYAGER";
}

void IShip::shipChooser( std::unique_ptr<IShip>& myShip) {
    std::cout<<"WELCOME TO SPACE VOYAGER\n\n\n";
    Sleep(2000);
    std::cout << "Choose a ship\n";
    std::cout << "Enter F for Fast Ship, S for Armored Ship, R for Standard Ship \n ";
    char chooser{'a'};
    while (chooser != 'F' && chooser !='f' && chooser != 'S' && chooser !='s' && chooser != 'R' && chooser !='r') {
        std::cin >> chooser;
        if (chooser == 'F' || chooser == 'f') {
            myShip=std::make_unique<fastShip>();
            std::cout<<"You have chosen the Fast Ship\n";
            break;
        } else if (chooser == 'S' || chooser == 's') {
            myShip=std::make_unique<armoredShip>();
            std::cout<<"You have chosen the Armored Ship\n";
            break;
        } else if (chooser == 'R' || chooser == 'r') {
            myShip=std::make_unique<standartShip>();
            std::cout<<"You have choosen the Standart Ship\n";
            break;
        } else {
            std::cout << "Invalid ship type\n";
        }
    }
    Sleep(2000);
}
void fastShip::loseHealth(int amount) {
    this->health-=static_cast<double>(amount)*(1.5);
}

void armoredShip::loseHealth(int amount) {
    this->health-=static_cast<double>(amount)*(0.5);
}

void standartShip::loseHealth(int amount) {
    this->health-=static_cast<double>(amount);
}

void IShip::useFuel(int amount) {
    this->fuel-=amount;
}

void IShip::gainMoney(int amount){
    this->money+=amount;
}

void IShip::giveMoney(int amount) {
    this->money-=amount;
}

int IShip::displayFuel() const  {
    std::cout<<"Remaining Fuel:"<<this->fuel<<"\n";
    return this->fuel;
}

int IShip::displayHealth() const {
    std::cout<<"Remaining Health:"<<this->health<<"\n";
    return this->health;
}

int IShip::displayMoney() const {
    std::cout<<"Remaining Money:"<<this->money<<"\n";
    return this->money;
}

bool fastShip::run() {
    int luck{0};
    luck = rand() % 4;
    if (luck != 0) {
        std::cout << "Running failed\n";
        return false;
    } else {
        std::cout << "You have successfully runned\n";
        return true;
    }
}
bool armoredShip::run(){
    int luck{0};
    luck=rand()%4;
    if(luck ==0){
        std::cout<<"You have succesfully runned\n";
        return true;
    } else{
      std::cout<<"Running failed\n";
      return false;
    }
}

bool standartShip::run() {
    int luck{0};
    luck=rand()%2;
    if(luck==0){
        std::cout<<"You have successfully runned\n";
        return true;
    }else{
        std::cout<<"Running failed\n";
        return false;
    }
}
int IShip::getFuel() const {
    return this->fuel;
}

void IShip::displayAllStatus() const{
    std::cout<<"This is the status of your ship at beginning\n";
    std::cout<<"Health: "<<this->health<<"\n";
    Sleep(500);
    std::cout<<"Money: "<<this->money<<"\n";
    Sleep(500);
    std::cout<<"Fuel: "<< this->fuel<<"\n\n\n";
    Sleep(2000);
}



