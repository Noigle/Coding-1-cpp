// Fav Games Assignment
// Create a .cpp program that will allow the user to
// add a game
// edit a game
// remove a game
// show all games (sorted)
// quit
// 
// use vectors and iterators and algorithms to do so
// use pseudocode to organize your thoughts.
// show the available commands to the user
//      at the top of each loop
// the games do not need to save between launches of the program
// the user should type the command they want to use as a word

// Matthew Knight Coding 1 Spring 2026


#include <iostream>
#include <string>     // for getline()
#include <vector>     // for vectors and iterators
#include <algorithm>  // for find(), sort(), random_shuffle()

using namespace std;

int main() {
    cout << "This is going to be a list of your favorite games.\n";


    string input;

    // create vector for favGames
    // get the user to input their favorite games
        cout << "What is one of your favorite games?\n";
        getline(cin, input);

            // add input to vector
        vector<string> favGames;
        favGames.push_back(input);

    do{
    cout << 
    getline(cin, input);

    // show current favGames
    // after input, provide options available to do
        // list will include 'quit', 'add more', 'remove', 'edit', 'remove all'
    // 'quit' will quit the program
    if(input == "quit") {
        cout << "You have some awesome games, bye bye now!\n";
        break;
    }
    else {
        cout << "Sorry, I don't understand that command.\n";
    }
    // 'add more' will allow user to add more games
    // 'remove' will remove one game
    // 'edit' will allow the user to change one of the games
    // 'remove all' "clear()" will remove all games from vector
        // make sure there is a "are you sure?" prompt





   } while(true);

}   // end of int main()
