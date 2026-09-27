#include <iostream>
using namespace std;

class Hero
{
protected:
    string name;
    int health;
    int energy;

public:
    Hero(string n, int h, int e)
    {
        name = n;
        health = h;
        energy = e;
    }

    virtual void specialAttack(Hero &enemy)
    {
        cout << name << " attacks normally!\n";
        enemy.health -= 10;
    }

    void showStats()
    {
        cout << "\nHero: " << name
             << "\nHealth: " << health
             << "\nEnergy: " << energy << "\n";
    }

    bool isAlive()
    {
        return health > 0;
    }

    string getName()
    {
        return name;
    }

    friend class SpeedHero;
    friend class FireHero;
    friend class TechHero;
};

class FireHero : public Hero
{
public:
    FireHero(string n) : Hero(n, 120, 100) {}

    void specialAttack(Hero &enemy) override
    {
        cout << name << " uses FIRE BLAST!\n";
        enemy.health -= 30;
        energy -= 20;
    }
};

class SpeedHero : public Hero
{
public:
    SpeedHero(string n) : Hero(n, 100, 120) {}

    void specialAttack(Hero &enemy) override
    {
        cout << name << " uses LIGHTNING STRIKE!\n";
        enemy.health -= 25;
        energy -= 15;
    }
};

class TechHero : public Hero
{
public:
    TechHero(string n) : Hero(n, 110, 110) {}

    void specialAttack(Hero &enemy) override
    {
        cout << name << " launches DRONE ATTACK!\n";
        enemy.health -= 28;
        energy -= 18;
    }
};

int main()
{
    FireHero blaze("Blaze");
    SpeedHero flash("FlashX");

    cout << "===== HERO BATTLE SIMULATOR =====\n";

    blaze.showStats();
    flash.showStats();

    cout << "\nBattle Starts!\n\n";

    blaze.specialAttack(flash);
    flash.specialAttack(blaze);

    cout << "\nAfter Battle:\n";

    blaze.showStats();
    flash.showStats();

    return 0;
}