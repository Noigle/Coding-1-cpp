// Matthew Knight Coding 1 Spring 2026
/*Create a .cpp program that allows the player to 

name a 'critter' (or 'monster', or 'robot', or 'slime', or 'puppy' - 
whatever you like!)
-feed their critter
--train their critter (chance to increase health or damage)
---listen to their critter (display health, damage, and hunger)
----battle other critters, with options to
-----attack
------heal
-------run away

-----   Your program needs the following features  -----

a randomized list of names must be read from a separate text file
setters and getters must be implemented for all class variables 
(class variables should be private)
critter class must have a constructor
each battle or training adds 1 to the critter's hunger.
if their hunger is greater than 10, they can't train or battle.
if their hunger is greater than 5, 
they'll mention it each time they train or battle*/


#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// global variables that our class can see too.
vector<string> names;


void read(vector<string>& names, string path = "names.txt") {   
    string Line;
    ifstream readFile(path);  
    if(readFile.is_open()){
        cout << "The file is open.\n";
        while(getline(readFile, Line)) {
            names.push_back(Line);
        }
    }
    else {
        cout << "Couldn't read that file.\n";
    }

    // after we are done reading the file, close it!!
    readFile.close();
}

class baseSlime {
private:
    string name;
    int speed;
    int hunger;
    int health;
    int damage;

    public:
    // default constructor
    baseSlime() {
        cout << "A new slime has been ecountered.\n";
        name = names[rand() % names.size()];
        speed = 2;
        hunger = 5;
        health = 5;
        damage = 2;
    }


    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << speed <<" speed " << hunger << " hunger ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    bool attack(baseSlime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if (opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    string getName(){
        return name;
    }

    int getSpeed() {
        return speed;
    }

    int getHunger() {
        return hunger;
    }

    int getHealth() {
        return health;
    }
    
    int getDamage() {
        return damage;
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
    void setSpeed(int givenSpeed) {
        if(givenSpeed < 0){
            speed = 0;
        }
        else speed = givenSpeed;
    }

    void setHunger(int givenHunger) {
        if (givenHunger < 0) {
            hunger = 0;
        }
        else hunger = givenHunger;
    }

    void setHealth(int givenHealth) {
        if (givenHealth < 0) {
            health = 0;
        }
        else health = givenHealth;
    }

    void setDamage(int givenDamage) {
        if (givenDamage < 1) {
            damage = 1;
        }
        else damage = givenDamage;
    }
    
};

class myPet {
private:
    string name;
    int speed;
    int hunger;
    int health;
    int damage;

    public:

    //myPet constructor
    myPet(string givenName, int givenSpeed, int givenHunger, int givenHealth,
        int givenDamage ) {
        name =  givenName; // getline(cin, input);
        speed = givenSpeed;
        hunger = givenHunger;
        health = givenHealth;
        damage = givenDamage;
    }
    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << speed <<" speed " << hunger << " hunger ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    bool attack(myPet& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if (opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // getters
    string getName(){
        return name;
    }

    int getSpeed() {
        return speed;
    }

    int getHunger() {
        return hunger;
    }

    int getHealth() {
        return health;
    }
    
    int getDamage() {
        return damage;
    }
// Setters
    void setName(string givenName) {
        if(givenName.size() <= 12){
            name = givenName;
        }
        else {
            cout << "error: " << givenName << " is too long.\n";
        }
    }
    void setSpeed(int givenSpeed) {
        if(givenSpeed < 0){
            speed = 0;
        }
        else speed = givenSpeed;
    }

    void setHunger(int givenHunger) {
        if (givenHunger < 0) {
            hunger = 0;
        }
        else hunger = givenHunger;
    }

    void setHealth(int givenHealth) {
        if (givenHealth < 0) {
            health = 0;
        }
        else health = givenHealth;
    }

    void setDamage(int givenDamage) {
        if (givenDamage < 1) {
            damage = 1;
        }
        else damage = givenDamage;
    }
    

};

int main() {

    cout << "------------------------------------\n";
    string input = "asdf";


    myPet(input, 1,1,1,1);

    cout << "Your pet's egg has hatched, what would you like to name them?\n";
    
    getline(cin, input);

    myPet(setName).push_back("input");



    

    // makes sure enemySlime stats change based off its name

    // have player name a pet
    // show stats of pet
    // ask player what they want to do
    // options to do inlcude:
    //     fight
    //          run away
    //     rest(recover hp)
    //     train
    //          train which stat? (speed, hunger, damage, health)
    //     feed
    //     quit
    //     show stats


    // during battle, create enemy slime of random name from text file
    // whoever has higher speed will go first
    // enemy slime will perform random action
    // 





cout << "------------------------------------\n";
    return 0;
}






