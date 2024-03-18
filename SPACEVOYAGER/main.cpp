#include <iostream>
#include "inc/ship.h"
#include <memory>
#include "inc/event.h"
#include <ctime>
#include <windows.h>


int main() {
    std::srand(std::time(nullptr));
    std::unique_ptr<Event> Event(new class Event());
    std::unique_ptr<IShip> myShip;
    myShip->shipChooser(myShip);
    myShip->displayAllStatus();
    Event->randomEventExecuter(myShip,Event);
    Sleep(2000);
}
