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
        name = names[rand() % names.size()];
        speed = 20;
        hunger = 5;
        health = 35;
        damage = 10;
    }


    void enemyHello() {
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
        if(givenName.size() <= 30){
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
        cout << "I'm your pet " << name << ", with " << health << " health ";
        cout << speed <<" speed " << hunger << " hunger ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    bool petAttack(myPet& opponent) {
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
        else if(givenHealth > 100) {
            health = 100;
        }
        else health = givenHealth;
    }

    void setDamage(int givenDamage) {
        if (givenDamage < 1) {
            damage = 1;
        }
        else damage = givenDamage;
    }
    void changeHungerBy(int amount = 1) {
        setHunger(hunger += amount);
    }
    void changeHealthBy(int amount = 10) {
        setHealth(health += amount);
    }
    void changeDamageBy(int amount = 5) {
        setDamage(damage += amount);
    }
    void changeSpeedBy(int amount = 5) {
        setSpeed(speed += amount);
    }
};

int main() {
    cout << "------------------------------------\n";
    read(names);
    string input;   


    myPet yourpet (input, 30,3,75,20);
    // have player name a pet
    cout << "Your pet's egg has hatched, what would you like to name them?\n";
    cout << "Please use 1-12 characters for your pet's name\n";
    
    getline(cin, input);

    yourpet.setName(input);
    // show stats of pet
    yourpet.hello();
    // makes sure enemySlime stats change based off its name
    // ask player what they want to do
    do{
        if(yourpet.getHealth() <= 0) {
            cout << "Sadly " << yourpet.getName() << " has died...\n";
            cout << "You can try again in the next game.\n";
            break;
        }
        cout << "--------------------------------------------------------\n";
        cout << "What would you like to do with your pet?\n";
        cout << "You can 'fight', 'bulk', 'train', 'feed',";
        cout << "'show stats', 'rename', or 'quit'\n";
    
        getline(cin, input);
        // during battle, create enemy slime of random name from text file
        // whoever has higher speed will go first
        // enemy slime will perform random action
        //     fight
        //          run away
        //          attack
        //          
        if(input == "fight") {
            srand(time(0 % 1000));
            baseSlime slimer;

            if(yourpet.getHunger() >= 10) {
                cout << yourpet.getName() << " is too hungry to fight.\n";
                continue;
            }
            else if(yourpet.getHunger() >=5) {
                cout << "Hey owner, I'm starting to get hungry, please feed me.\n";
            }
            else if(yourpet.getHunger() < 5) {
                cout << "I'm ready for a fight, let's to this!\n";
            }
            
            // name based stats
            if(slimer.getName() == "Reverse Flash The Yellow Slime") {
                slimer.setSpeed(100);
            }
            else if(slimer.getName() == "Mark The Blue Slime") {
                slimer.setSpeed(70);
                slimer.setDamage(24);
                slimer.setHealth(75);
            }
            else if(slimer.getName() == "Spyro The Purple Slime") {
                slimer.setSpeed(40);
                slimer.setDamage(15);
                slimer.setHealth(50);
            }
            else if(slimer.getName() == "Shrek The Green Slime") {
                slimer.setSpeed(15);
                slimer.setDamage(15);
                slimer.setHealth(45);
            }
            else if(slimer.getName() == "Eve The Pink Slime") {
                slimer.setSpeed(60);
                slimer.setDamage(20);
                slimer.setHealth(68);
            }
            else if(slimer.getName() == "Alfred The Black Slime") {
                slimer.setSpeed(20);
                slimer.setDamage(10);
                slimer.setHealth(30);
            }
            else if(slimer.getName() == "Walter The White Slime") {
                slimer.setSpeed(15);
                slimer.setDamage(15);
                slimer.setHealth(30);
            }
            else if(slimer.getName() == "Styles The Hairy Slime") {
                slimer.setSpeed(25);
                slimer.setDamage(15);
                slimer.setHealth(40);
            }
            else if(slimer.getName() == "Jabba The Brown Slime") {
                slimer.setSpeed(0);
                slimer.setDamage(20);
                slimer.setHealth(120);
            }
            else if(slimer.getName() == "Nolan The Red Slime") {
                slimer.setSpeed(90);
                slimer.setDamage(35);
                slimer.setHealth(120);
            }
            //  make fight code here
            do{
                auto& a = yourpet;
                auto& b = slimer;
                yourpet.petAttack(b);
                slimer.enemyHello();
                if(a.getSpeed() > b.getSpeed()) {
                    cout << "You are faster, what would you like to do?\n";
                    cout << "You can 'attack' or 'run away'.\n";
                    getline(cin, input);
                    if(input == "attack") {
                        a.petAttack(b);
                        cout << a.getName() << " does " << a.getDamage() << " damage to " << b.getName() << ".\n";
                        cout << b.getName() << " has " << b.getHealth() << " health left.\n";

                    }
                    else if(input == "run away") {
                        cout << "You run away with your pet, your pet grows hungier.\n";

                        yourpet.changeHungerBy();
                        break;
                    }
                }
                else if(b.getSpeed() > a.getSpeed()) {
                    cout << b.getName() << " is faster.\n";
                    b.attack(a);
                    cout << b.getName() << " does " << b.getDamage() << " damage to " << a.getName() << ".\n";
                    cout << a.getName() << " has " << a.getHealth() << " health left.\n";
                    cout << "You can 'attack' or 'run away'.\n";
                    getline(cin, input);
                    if(input == "attack") {
                        a.petAttack(b);
                        cout << a.getName() << " does " << a.getDamage() << " damage to " << b.getName() << ".\n";
                        cout << b.getName() << " has " << b.getHealth() << " health left.\n";

                    }
                    else if(input == "run away") {
                        cout << "You run away with your pet, your pet grows hungier.\n";
                        yourpet.changeHungerBy();
                        break;
                    }
                }
            if (slimer.getHealth() <= 0) {
                cout << "Victory is yours.\n";
            cout << "What skill would you like to increase?\n";
            cout << "'damage' or 'speed'.\n"; 

                do {
                    getline(cin,input);
                    if(input == "damage") {
                    yourpet.changeDamageBy(8);
                    cout << yourpet.getName() << "'s damage was increased to " << yourpet.getDamage() << ".\n";
                    break;
                    }
                    else if(input == "speed") {
                    yourpet.changeSpeedBy(8);
                    cout << yourpet.getName() << "'s speed was increased to " << yourpet.getSpeed() << ".\n";

                    break;
                     }
                    
                } while(input != "damage" && input != "speed");
            }
                

            }while(yourpet.getHealth() > 0 && slimer.getHealth() > 0);


            // have yourpet's hunger increase after every battle
            yourpet.changeHungerBy();
            
        } // end of fight
        else if(input == "rename"){
                cout << "What would you like to rename " << yourpet.getName() << " to?\n";
                getline(cin, input);
                yourpet.setName(input);
                yourpet.hello();
                continue;
        } // end of rename
        //     rest(recover hp)
        else if(input == "rest") {
            cout << "You have chosen to increase your HP\n";
            if(yourpet.getHealth() >= 100) {
                cout << yourpet.getName() << "'s health is already at max.\n";
                continue;
            }
            yourpet.changeHealthBy();
            cout << yourpet.getName() << "'s health was increaed by 10.\n";
            // make rest code here
        } // end of rest
        //     train
        //          train which stat? (speed, hunger, damage, health)
        else if(input == "train") {
            if(yourpet.getHunger() >= 10) {
                cout << yourpet.getName() << " is too hungry to train.\n";
                continue;
            }
            cout << "You have chosen to train your pet.\n";
            cout << "What skill would you like to train?\n";
            cout << "'damage' or 'speed'.\n";
            getline(cin, input);
            if(input == "damage") {
                yourpet.changeDamageBy();
                continue;
            }
            else if(input == "speed") {
                yourpet.changeSpeedBy();
                continue;
            }
            else {
                cout << "Sorry, that is not a skill you can change.\n";
                continue;
            }
            // make train code here
        } // end of train
        //     feed
        else if(input == "feed") {
            cout << "You have chose to feed your pet\n";
            cout << yourpet.getName() << "'s hunger has been lowered by '1'.\n";
            // make feed code here
            yourpet.changeHungerBy(-1);
        }   // end of feed
        //     show stats
        else if(input == "show stats") {
            cout << "Here are your pet's stats\n";
            // make show stats code(.hello)
            yourpet.hello();
        }   // end of show stats
        //     quit
        else if(input == "quit") {
            cout << "Thank you for playing the game!\n";
            break;
        } // end of quit
        else{
            cout << "I did not recognise that command.\n";
        }
    } while(true);





cout << "------------------------------------\n";
    return 0;
}   // end of int main






