#include <iostream>
#include <string>
using namespace std;

class Component {
public:
    virtual ~Component() {}
    virtual string getInfo() const = 0;
};

class Component1 : public Component {
public:
    string getInfo() const override {
        return "Component1";
    }
};

class Component2 : public Component {
public:
    string getInfo() const override {
        return "Component2";
    }
};

class Component3 : public Component {
public:
    string getInfo() const override {
        return "Component3";
    }
};

class ObjectBuilder {
public:
    virtual ~ObjectBuilder() {}
    virtual void addComponent() = 0;
    virtual string getResult() const = 0;
};

class ObjectDirector {
private:
    ObjectBuilder* builder;

public:
    ObjectDirector(ObjectBuilder* b) : builder(b) {}

    void construct() {
        builder->addComponent();
    }
};

class ConcreteObjectBuilder : public ObjectBuilder {
private:
    string result;

public:
    void addComponent() override {
        Component1 component1;
        Component2 component2;
        Component3 component3;

        result += component1.getInfo() + ", ";
        result += component2.getInfo() + ", ";
        result += component3.getInfo();
    }

    string getResult() const override {
        return result;
    }
};

int main() {
    ObjectBuilder* builder = new ConcreteObjectBuilder();

    ObjectDirector director(builder);

    director.construct();

    string result = builder->getResult();
    cout << "Object components: " << result << endl;

    delete builder;

    return 0;
}
