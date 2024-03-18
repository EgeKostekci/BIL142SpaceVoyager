//
// Created by ÖMER EGE on 11.03.2024.
//
#include <iostream>
#include "../inc/event.h"
#include <windows.h>
#include <memory>

void Event::randomEventExecuter( std::unique_ptr<IShip>& myShip,std::unique_ptr<Event> &myEvent) {
    while (myEvent->eventCounter < 5 && myShip->getFuel() != 0) {
        int eventChooser{0};
        eventChooser = rand() % 3;
        if (eventChooser == 0) {
            asteroidZone obj;
            std::cout << "Your ship just got into an asteroid zone hold tight!!\n";
            obj.takeDamageOrNot(myShip);
            Sleep(2000);
        } else if (eventChooser == 1) {
            abandonedPlanet obj;
            std::cout << "You have found a abandoned planet and landed\n";
            obj.getMoneyByChance(myShip);
            Sleep(2000);
        } else {
            spacePirates obj;
            std::cout << "You encountered space pirates. What is your plan?\n";
            obj.RunBattleBargain(myShip);
            Sleep(2000);
        }
        myEvent->eventCounter++;
        std::cout<<"\n\n";
    }
}
void asteroidZone::takeDamageOrNot( std::unique_ptr<IShip>& myShip) {
    for (int asteriodCounter = 0; asteriodCounter < 3; ++asteriodCounter) {
        int luckNumber{0};
        luckNumber = std::rand() % 2;
        if (luckNumber == 1) {
            myShip->loseHealth(10);
            std::cout<<"Your ship has been hit you have lost some health\n";
            myShip->displayHealth();
            Sleep(400);
        }
        else
            std::cout<<"Nice maneuvers you dodged an asteroid\n";
            Sleep(400);
            continue;
    }
}

void spacePirates::RunBattleBargain( std::unique_ptr<IShip>& myShip) {
    if(myShip->getFuel()<=33) {
        std::cout << "For bargaining press B, for fighting press F\n";
    }
    else if(myShip->displayMoney()==0){
        std::cout<<"For running press R, for fighting press F\n";
    }
    else {
        std::cout<<"For running press R,for fighting press F,for bargaining press B\n";
    }
    char choice;
    std::cin>>choice;
    int healthAmount{30};
    int fuelAmount{33};
    int moneyAmount{0};
    int moneyLuck{0};
    moneyLuck = rand() % 3;
    int damageLuck{0};
    damageLuck = rand() % 2;
    switch (choice) {
        case 'R':
            if(myShip->getFuel()>33){
                myShip->useFuel(fuelAmount);
                if(myShip->run()==true){
                    break;
                }
                else{
                    myShip->displayFuel();
                    spacePirates obj;
                    obj.RunBattleBargain(myShip);
                }
            }
            else{
                std::cout<<"Not enough fuel\n";
                spacePirates obj;
                obj.RunBattleBargain(myShip);
            }
            break;

        case 'B':
            if(myShip->displayMoney()>0) {
                if (moneyLuck == 0) {
                    moneyAmount = 10;
                } else if (moneyLuck == 1) {
                    moneyAmount = 20;
                } else {
                    moneyAmount = 30;
                }
                myShip->giveMoney(moneyAmount);
                myShip->displayMoney();
                break;
            }
            else{
                std::cout<<"Not enough money\n";
                spacePirates obj;
                obj.RunBattleBargain(myShip);
            }
        case 'F':
            if(damageLuck==0){
                myShip->loseHealth(healthAmount);
                std::cout<<"Your ship got damage\n";
                myShip->displayHealth();
            }
            else{
                std::cout<<"You beat Space Pirates\n";
            }
            break;

        default:
            std::cout<<"Invalid choice\n";
            spacePirates obj;
            obj.RunBattleBargain(myShip);
            break;
    }
}
void abandonedPlanet::getMoneyByChance(std::unique_ptr<IShip>& myShip) {
    int moneyLuck=rand()%2;
    int amount{10};
    if(moneyLuck==0){
        myShip->gainMoney(amount);
        std::cout<<"You were lucky, you found some coins\n";
        myShip->displayMoney();
    }
    else if(moneyLuck==1)
    {
        std::cout<<"You weren't so lucky this time you have encountered Space Pirates\n";
        spacePirates obj;
        obj.RunBattleBargain(myShip);
    }
}
