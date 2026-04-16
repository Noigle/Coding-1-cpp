// Matthew Knight Coding Spring 2026
// Functions!!!!!!!!!!!


/*BLOCK COMMENT*/

/*
    Functions
        return type, name, (input parameters) { code }
    Sending and recieving variable to and from a function.
    Passing by value
    Passing by reference
*/



#include<iostream>
#include<string>
#include<cstdlib>       // for rand() and srand()
#include<ctime>         // for time()
#include<vector>

using namespace std;


// declaring and defining a new function
// the return type is void, which means it returns NOTHING
// the name of the function is "sayHello"
// the input parameters go in the parenthesis... this function doesn't have any.
// then the code goes between {curly braces}!
void sayHello() {
    cout << "Hello!\n";
} 

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";

}

// dont forget to include <cstdlib> and <ctime>
int dieRoll(int sides = 6) {
    return rand() % sides + 1;
}

// create a function
// return type is bool
// name is askYesNo
// no input parameters (for now)

bool askYesNo(string question = "Do you want to Keep playing?") {
    while(true){
        cout << question << " ('yes'/'no')\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
            return true;
        }
        else if(input == "no"){
            return false;
        }
        else {
            cout << "I did not understand. Please type 'yes or 'no'.\n";
        }
    }
}

// variable scope
// global variables
// passing by reference
// include vector

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// create a refernce with and ampersand ('&') next to the variable type.
//  int& number; or string& name;

// references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

   //  showVec(vec);
}

int main() {
    srand(time(0));
    vector<string> names = {"Finn", "Jake", "Marceline", "BM0", "Princess Bubblegum"};

    showVec(names);

    addStringToVec(names);

    showVec(names);

    cout << "Finally, functions!\n";

    sayHello();

    doAddition(123, 321);

    cout << "let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(222));

    showVec(names);

    // call the askYesNo() Function, and it will return true or false.
    if(askYesNo()) {
        cout << "Let's start the next level!\n";
    }
    else {
        cout << "Thanks for Playing!\n";
    }
    if(askYesNo("Do you like watermelons?")) {
        cout << "I like them too!\n";
    }
    else {
        cout << "You're wrong, unless its the mushy melon, then I'd agree with you.\n";
    }


    return 0;
}