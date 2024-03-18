//2
// Created by ÖMER EGE on 11.03.2024.
//

#ifndef NEWPROJECT_EVENT_H
#define NEWPROJECT_EVENT_H
#include "../inc/ship.h"
#include <memory>

class Event {
public:
    Event()=default;
    static void randomEventExecuter( std::unique_ptr<IShip>& myShip,std::unique_ptr<Event> &myEvent);
private:
    int eventCounter{0};
protected:

};

class asteroidZone:public Event{
public:
    asteroidZone()=default;
    static void takeDamageOrNot(std::unique_ptr<IShip>& myShip);
private:
protected:
};

class abandonedPlanet:public Event{
public:
    abandonedPlanet()=default;
    static void getMoneyByChance( std::unique_ptr<IShip>& myShip);
private:
protected:
};

class spacePirates:public Event{
public:
    spacePirates()=default;
    static void RunBattleBargain( std::unique_ptr<IShip>& myShip);
private:
protected:
};


#endif //NEWPROJECT_EVENT_H
