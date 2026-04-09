// Matthew Knight Coding 1 Spring 2026
//  Vectors, Iterators, and Algorithms

#include <iostream>
#include <string>     // for getline()
#include <vector>     // for vectors and iterators
#include <algorithm>  // for find(), sort(), random_shuffle()

using namespace std;

int main() {
    cout << "Let's Learn about vectors!\n";

    string input;
    // int to numberInput = stoi(input);
    do{
        cout << "What would you like to do?\n";
        cout << "You can type 'quit', 'find', 'push'.\n";

        getline(cin, input);        // get input from player
    
        if(input == "push"){
            cout << "\nLet's make our first vector of strings.\n";

            vector<string> names;

            // add some names with names. push_back()
            names.push_back("Finn");
            names.push_back("Lady Rainicorn");
            names.push_back("Jake");
            names.push_back("The Lich");
            names.push_back("Lemongrab");
            
            cout << "Here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << names[i] << "\n";
            }

            cout << "There are " << names.size() << " names.\n\n";

            cout << *(names.end() -1) << " is sour. Let's get rid of him.\n";
            names.pop_back();   // pop_back() removes the last element from the vector     
           
            cout << "Here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << names[i] << "\n";
            } 

            cout << "There are " << names.size() << " names.\n\n";


        } // end of 'push'
        else if(input == "find") {
            cout << "Let's try to use the find algorithm.\n";

           
            vector<string> favs = {"Star Wars", "Kill Bill", "Ponyo"};
            // build an iterator. it point to a 'spot' in a vector
            vector<string>::iterator iter;

            cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "     "  << favs[i] << "\n";
            }


            //make iter point at the first element in the vector
            iter = favs.begin();

            // the asterisk is a "dereference operator"... so that we can get
                // the value the iter is pointing at.
            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "Now iter is pointing at " << *iter << ".\n";

            cout << "What name would you like to select?\n";
            getline(cin, input);
            //use the find algorithm
            iter = find(favs.begin(), favs.end(), input);

            if(iter != favs.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);
                if(input == "yes") {
                    cout << "What would you like to change this fav to?\n";
                    getline(cin, input);

                    *iter = input;      // change the fav
                }

                cout << "here are your updated favs!\n";
                for(int i = 0; i < favs.size(); i++) {
                    cout << "     "  << favs[i] << "\n";
                }
               

            
        }
        else {
            cout << "We couldn't find that name.\n";
        }




        }
        else if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }
        else {
            cout << "I didn't recognise that command.\n";
        }
    
    } while(true);

    // create a new vector of strings


return 0;

}



