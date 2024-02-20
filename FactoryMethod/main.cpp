#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:
    virtual ~Weapon() {}
    virtual void attack() const = 0;
    virtual string getType() const = 0;
};

class Sword : public Weapon {
public:
    void attack() const override {
        cout << "Sword attack!\n";
    }
    string getType() const override {
        return "Sword";
    }
};

class Bow : public Weapon {
public:
    void attack() const override {
        cout << "Bow attack!\n";
    }
    string getType() const override {
        return "Bow";
    }
};

class Dagger : public Weapon {
public:
    void attack() const override {
        cout << "Dagger attack!\n";
    }
    string getType() const override {
        return "Dagger";
    }
};

class WeaponFactory {
public:
    virtual ~WeaponFactory() {}
    virtual Weapon* createWeapon() = 0;
};

class SwordFactory : public WeaponFactory {
public:
    Weapon* createWeapon() override {
        return new Sword();
    }
};

class BowFactory : public WeaponFactory {
public:
    Weapon* createWeapon() override {
        return new Bow();
    }
};

class DaggerFactory : public WeaponFactory {
public:
    Weapon* createWeapon() override {
        return new Dagger();
    }
};

int main() {
    WeaponFactory* factory = new BowFactory();
    Weapon* playerWeapon = factory->createWeapon();
    if (playerWeapon) {
        playerWeapon->attack();
        cout << "Player equipped with: " << playerWeapon->getType() << endl;
        delete playerWeapon;
    }
    delete factory;

    return 0;
}