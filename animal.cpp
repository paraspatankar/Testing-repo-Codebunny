#include <iostream>
#include <string>

using namespace std;

// Base Class
class Animal {
public:
    string name;

    // Constructor for the base class
    Animal(string n) : name(n) {}

    // Virtual function to demonstrate polymorphism (runtime binding)
    virtual void makeSound() {
        cout << name << " makes a generic sound." << endl;
    }

    // A regular function that derived classes can also use
    void sleep() {
        cout << name << " is sleeping." << endl;
    }
};

// Derived Class 1 (inherits from Animal)
class Dog : public Animal {
public:
    // Constructor for the derived class
    Dog(string n) : Animal(n) {}

    // Overriding the base class function to provide a specific behavior
    void makeSound() override {
        cout << name << " says: Woof woof!!" << endl;
    }
};

// Derived Class 2 (inherits from Animal)
class Cat : public Animal {
public:
    // Constructor for the derived class
    Cat(string n) : Animal(n) {}

    // Overriding the base class function
    void makeSound() override {
        cout << name << " says: Meow!" << endl;
    }
};

int main() {
    // 1. Create Objects of the Derived Classes
    Dog myDog("Buddy");
    Cat myCat("Whiskers");

    // 2. Demonstrate Class and Object functionality (without polymorphism yet)
    cout << "--- Class & Object Demonstration ---" << endl;
    myDog.makeSound(); // Calls Dog's makeSound
    myCat.makeSound(); // Calls Cat's makeSound
    myDog.sleep();     // Calls Animal's sleep (inherited)
    cout << endl;

    // 3. Demonstrate Polymorphism
    // Use a base class pointer to refer to derived class objects
    cout << "--- Polymorphism Demonstration ---" << endl;
    Animal* animalPtr; // Pointer of the base class type

    // Point the pointer to the Dog object
    animalPtr = &myDog;
    // Call the virtual function; the output depends on the object type (Dog), not the pointer type
    animalPtr->makeSound(); // Calls Dog's makeSound at runtime

    // Point the same pointer to the Cat object
    animalPtr = &myCat;
    // Call the virtual function again; now it calls Cat's makeSound
    animalPtr->makeSound(); // Calls Cat's makeSound at runtime

    return 0;
}
