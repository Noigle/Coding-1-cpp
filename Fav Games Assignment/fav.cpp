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
    cout << "Thats an interesting choice.\n";
    do{      // show current favGames
        cout << "Your current favorite games are:\n";
        for(int i = 0; i < favGames.size(); i++) {
            cout << favGames[i] << "\n";
        }


        // after input, provide options available to do
            // list will include 'quit', 'add more', 'remove', 'edit', 'remove all'
        
        cout << "What would you like to do next?\n";
        cout << "You can type 'quit', 'add more', 'remove', 'edit', 'remove all'.\n";
        getline(cin, input);
        // 'quit' will quit the program
        if(input == "quit") {
            if(favGames.empty()) {
                cout << "I hope you find some favorite games soon!\n";
                break;
            } else {
                    cout << "You have some awesome games, bye bye now!\n";
                    break;
                }
            
        }
            // 'add more' will allow user to add more games
        if(input == "add more"){
                cout << "What game would you like to add?\n";
                std::getline(cin, input);
                favGames.push_back(input);
        }
            // 'remove' will remove one game

        else if(input == "remove") {
            cout << "Your current favorite games are:\n";

            for(int i = 0; i < favGames.size(); i++) {
                cout << "     "  << favGames[i] << "\n";
            }

            cout << "What game would you like to remove from your favorites list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                favGames.erase(iter);
                cout << "That game has been removed from the list.\n";
            }
        }
            // 'edit' will allow the user to change one of the games
        else if(input == "edit") {
            vector<string>::iterator iter;

            cout << "Here is your current list of favorite games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << "     "  << favGames[i] << "\n";
            }

            iter = favGames.begin();
            iter += 1;

            cout << "What game would you like to edit?\n";
            getline(cin, input);

            iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "What would you like change this game to?\n";
                getline(cin, input);

                *iter = input;
                }
            cout << "Here is your current list of favorite games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << "     "  << favGames[i] << "\n";
            }
            }
            // 'remove all' "clear()" will remove all games from vector
                // make sure there is a "are you sure?" prompt
            else if(input == "remove all") {
                cout << "Are you sure you would like to remove all?\n";
                cout << "This will delete all the items in the list.\n";
                cout << "'yes' or 'no'?\n";
                getline(cin, input);
                if(input == "yes") {
                    favGames.clear();
                }
                else if(input == "no") {
                    cout << "NOT deleting items in list.\n";
                }
            }
            
            else {
                cout << "\tSorry, I don't understand that command.\n";
            }




    } while(true);

}   // end of int main()
