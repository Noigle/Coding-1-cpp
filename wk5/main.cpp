// Matthew Knight Spring 2026 Coding 1
// Classes today!

// self-documenting code means the copde acan only do ONE thing, 
// or be used ONE way

#include<iostream>
#include<string>
#include<ctime>

using namespace std;

// classes are custom variable types
// variables
// functions

// constructors
// getters and setters (privacy)

class robot {
private:
    // data members
    string name;
    int charge;
    int boredom;

    public:
    // constructor, sets up the class with input variables
    // doesn't have a return type, must be named same as class
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    // default constructor
    robot() {
        name = "Rob";
        charge = 10;
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if(boredom < 5) cout << "happy";
        else if(boredom < 10) cout << "bored";
        else if(boredom < 15) cout << "frustrated";
        else cout << "ENRAGED";

        cout << ".\n"; // end of the sentence
    }

    // Getters
    string getName(){
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }

    // Setters
    void setName(string givenName) {
        if(givenName.size() <= 5){
            name = givenName;
        }
        else {
            cout << "error: " << givenName << " is too long.\n";
        }
    }
    void setBoredom(int givenBoredom) {
        if(givenBoredom < 0){
            boredom = 0;
        }
        else boredom = givenBoredom;
        }

    void setCharge(int givenCharge) {
        // clamp charge to between 0 and 100
        if (givenCharge < 0) {
            charge = 0;
        }
        else if(givenCharge > 100) {
            charge = 100;
        }
        else charge = givenCharge;
    }

    // get AND set at the same time.
    void changeChargeBy(int amount = 1) {
        setCharge(charge += amount);
    }
}; // end of robot class

int main() {
    cout << "------------------------------------\n";
    cout << "Classes!\n";

    // create our first instance of a robot.
    robot artoo("R2-D2", 45, 3);
    // artoo.name = "R2-D2";   // dot syntax goes from large to small
    // artoo.charge = 45;
    // artoo.boredom = 3;

    cout << "Artoo has " << artoo.getName().size() << " letters in their name.\n";

    robot threepio;
    threepio.setName("C-3PO");
    threepio.setCharge(2);
    threepio.setBoredom(12);

    artoo.status();
    threepio.status();

    cout << "Threepio has low battery, let's have artoo charge him up!\n";

    while(threepio.getCharge() < 15) {
        if (artoo.getCharge() > 1){
            artoo.changeChargeBy(-1);
            threepio.changeChargeBy(1);
    }
    else {
        cout << "Artoo is out of energy!\n";
        break;
    }
    }

    artoo.status();
    threepio.status();

    robot ted;
    robot fourthbot;

    cout << "------------------------------------\n";
    return 0;
}