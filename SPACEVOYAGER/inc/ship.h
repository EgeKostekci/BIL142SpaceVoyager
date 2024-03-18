//
// Created by ÖMER EGE on 11.03.2024.
//

#ifndef NEWPROJECT_SHIP_H
#define NEWPROJECT_SHIP_H
#include <iostream>
#include <memory>

class IShip {
public:
    IShip()=default;
    virtual ~IShip();
    static void shipChooser(std::unique_ptr<IShip>& myShip);
    virtual void loseHealth(int amount)=0;
    void displayAllStatus() const;
    void useFuel(int amount);
    void gainMoney(int amount);
    void giveMoney(int amount);
    [[nodiscard]] int displayFuel()const;
    [[nodiscard]] int displayHealth() const;
    [[nodiscard]] int displayMoney() const;
    [[nodiscard]] int getFuel() const;
    virtual bool run()=0;
private:
protected:
    int health{100};
    int fuel{99};
    int money{0};
};
class fastShip:public IShip{
public:
    void loseHealth (int amount) override;
    bool run() override;
private:
protected:
};

class armoredShip:public IShip{
public:
    void loseHealth (int amount) override;
    bool run() override;
private:
protected:
};

class standartShip:public IShip{
public:
    void loseHealth (int amount) override;
    bool run() override;
private:
protected:
};


#endif //NEWPROJECT_SHIP_H
