// Matthew Knight Coding 1 Spring 2026
// Our first C++ program

// to compile, open 'Developer Command Prompt for VS 2022'
// navigate to this folder with 'cd' for 'change directory'
// use the command 'cl /EHsc filename.cpp' (in this case, its 'main.cpp')
// and then type 'filename' to run the .exe (in this case, its 'main')


#include <iostream>     // in out stream, for sending text to the console.
#include <string>        // for player name

using namespace std;    // so we dont have to type"std: :" all the time.

//here is where we start the program
int main() {
    // variables declared at the top is best practice.
    string playerName;       // variables use camelCase

    // ask the player for their name
    cout << "what is your name, player? ";

    // assign whatever the player types as the value of playerName
    cin >> playerName;

    //greet player by name
    cout << "Hello " << playerName << "." << endl;

    // user Control+slash to comment out lines.
    // cout << "Hello World!" << endl;    // cout = console out, endl = end line

return 0;                // end the program

}