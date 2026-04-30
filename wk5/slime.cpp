// Matthew Knight Coding 1 Spring 2026



#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

vector<string> names = {"Snake Mama ", "Grand Elder Splid ", 
    "Splid ", "Grand Elder Splidette ", "Viper Baby "};

class baseSlime {
public:
    string name;
    int health;
    int damage;

    // default constructor
    baseSlime() {
        cout << "A new slime has been formed.\n";
        name = names[rand() % names.size()] + "Slime";
        health = 5;
        damage = 2;

    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
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
};


class bossSlime :  public baseSlime {
public:
    int damageMultiplier = 2;

    int healthMultiplier = names.size();

    int armorClass = 15;

    bossSlime() {
        // should inherit health
        // should inherit the cout statement
        name = "Slime God";
        damage = damage * damageMultiplier;
        health = health * healthMultiplier;
        }

    bool attack(baseSlime& opponent) {
        cout << "This is a boss attack!\n";
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

    

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    }

};

int main() {
    srand(time(0));
    cout << "---------------------------------------------\n";
    cout << "SLIME BATTLES!\n";\

    // create a vector of slimes
    // then pick to to fight
    // global variables

    // create a new vector of slime with a size of 6
    vector<baseSlime> sludge(6);

    if(true) {
        bossSlime superSlime;
        sludge.push_back(superSlime);
    }

    cout << "Here is out sludge of slimes:\n\n";
    for (auto& slime : sludge) {
        cout << slime.name << " .\n";

    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];
    auto& b = sludge[1];


    // create a slime
    baseSlime gerald;
    gerald.hello();
    gerald.name = "Gerald";

    bossSlime god;
    god.name = "Slime God";
    god.hello();
    god.taunt();

    cout << "Gerald is feeling cheeky...\n";
    gerald.attack(god);

    cout << "Slime God is ENRAGED!\n";
    if(god.attack(gerald)) {
        cout << "Gerald is no more. DED.\n";
    }

    cout << a.name << " is fighting " << b.name << "!!!\n";

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout << b.name << " has been defeated by " << a.name << ".\n";
        }
        else {
            if(b.attack(a)) {
                cout << a.name << " has been defeated by " << b.name << ".\n";
            }
        }
    }


    cout << "---------------------------------------------\n";
    return 0;
}