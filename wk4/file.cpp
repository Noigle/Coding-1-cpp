/*  Matthew Knight Coding 1 Spring 2026
    writing to and reading from files.

*/
#include <string>
#include <iostream>
#include <vector>
#include <fstream>  // file stream

using namespace std;

void read(string path = "save.txt") {
    /*"I was crazy once
they put me in a room
a rubber room
a rubber room with rats
rats make me crazy"*/ // save.txt text in case is deleted
     string Line;
    ifstream readFile(path);  
    if(readFile.is_open()){
        cout << "The file is open.\n";
        while(getline(readFile, Line)) {
            cout << Line << endl;
        }
    }
    else {
        cout << "Couldn't read that file.\n";
    }

    // after we are done reading the file, close it!!
    readFile.close();
}

void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);
    if(readFile.is_open()){
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);    // add each line to the vector.
        }
    }
    else {
        cout << "Couldn't read that file.\n";
    }

    // after we are done reading the file, close it!!
    readFile.close();
}

void write(vector<string>& vec, string path = "save.txt") {
    ofstream writeFile(path);

    if(writeFile.is_open()) {
        // cout << "the write file is open\n";
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
    else {
        // cout << "Couldn't open new writeFile.\n";
    }
    writeFile.close();

}

int main() {
    cout << "Let's write to a file!\n";
    vector <string> favs;
    string input = "asdf";


    string path = "save.txt";

    cout << "What file would you like to open?\ntype 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;   // this let's us open different files
    }



    read(path);
    read(favs, path);

    cout << "What text would you like to add?\n";
    cout << "Enter an empty line to stop\n";

    // create a file to write to, open it  

    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "") {
            break;
        }

        // send to file
        favs.push_back(input);
    }

    // now call the write function and sent it our favs vector
    write(favs);

    return 0;
}