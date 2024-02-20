#include <iostream>
#include <string>
using namespace std;

class Clothing {
public:
    virtual ~Clothing() {}
    virtual void display() const = 0;
};

class Electronics {
public:
    virtual ~Electronics() {}
    virtual void display() const = 0;
};

class TShirt : public Clothing {
public:
    void display() const override {
        cout << "T-shirt\n";
    }
};

class Pants : public Clothing {
public:
    void display() const override {
        cout << "Pants\n";
    }
};

class Jacket : public Clothing {
public:
    void display() const override {
        std::cout << "Jacket\n";
    }
};

class Smartphone : public Electronics {
public:
    void display() const override {
        cout << "Smartphone\n";
    }
};

class Laptop : public Electronics {
public:
    void display() const override {
        cout << "Laptop\n";
    }
};

class TV : public Electronics {
public:
    void display() const override {
        cout << "TV\n";
    }
};

class FactoryProducts {
public:
    virtual ~FactoryProducts() {}
    virtual Clothing* createClothing() = 0;
    virtual Electronics* createElectronics() = 0;
};

class ClothingFactory : public FactoryProducts {
public:
    Clothing* createClothing() override {
        int choice;
        cout << "Choose clothing: 1. T-shirt, 2. Pants, 3. Jacket: ";
        cin >> choice;

        switch (choice) {
        case 1:
            return new TShirt();
        case 2:
            return new Pants();
        case 3:
            return new Jacket();
        default:
            return nullptr;
        }
    }

    Electronics* createElectronics() override {
        return nullptr;
    }
};

class ElectronicsFactory : public FactoryProducts {
public:
    Clothing* createClothing() override {
        return nullptr;
    }

    Electronics* createElectronics() override {
        int choice;
        cout << "Choose electronics: 1. Smartphone, 2. Laptop, 3. TV: ";
        cin >> choice;

        switch (choice) {
        case 1:
            return new Smartphone();
        case 2:
            return new Laptop();
        case 3:
            return new TV();
        default:
            return nullptr;
        }
    }
};

int main() {
    FactoryProducts* clothingFactory = new ClothingFactory();
    FactoryProducts* electronicsFactory = new ElectronicsFactory();

    Clothing* clothing = clothingFactory->createClothing();

    Electronics* electronics = electronicsFactory->createElectronics();
    system("cls");

    if (clothing) {
        clothing->display();
        delete clothing;
    }

    if (electronics) {
        electronics->display();
        delete electronics;
    }

    delete clothingFactory;
    delete electronicsFactory;

    return 0;
}
