/* Matthew Knight Coding 1 Spring 2026
    Personal Project

    Make a game where you select a game/ show from a list
      in the list shows the game/ show and top characters in it 
*/



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

/* Make a list of available games
allow user to select what game to look at
when user selects game, show the top 'x' favorite characters
allow user to create a game and add their favorite characters

*/
void showVec(vector<string>& GameShow) {
    for(int i = 0; i < GameShow.size(); i++) {
        cout << GameShow[i] << endl;
    }
}
void showVec(vector<string>& ATnames) {
    for(int i = 0; i < ATnames.size(); i++) {
        cout << ATnames[i] << endl;
    }
}
int main() {
     string input;

    vector<string> GameShow = {"Adventure Time", "Halo", "Nine Sols"};
    vector<string> ATnames = {"Finn", "Jake", "Marceline", "BM0", "Fire Princess"};

    cout << "What is one of your favorite games or shows?\n";
        getline(cin, input);

            // add input to vector
        
        GameShow.push_back(input);
        cout << "That's an interesting choice.\n";
    showVec(GameShow);


    return 0;
}