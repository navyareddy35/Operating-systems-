#include <iostream>s
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    const char* filename = "message.txt";
    const char* message = "Hello from parent via file!";
    
    
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Failed to open file for writing.\n";
        return 1;
    }
    outfile << message;
    outfile.close();
    cout << "Parent (Sender) wrote message.\n";

    
    ifstream infile(filename);
    if (!infile) {
        cerr << "Failed to open file for reading.\n";
        return 1;
    }
    string received;
    getline(infile, received);
    infile.close();

    cout << "Child (Receiver) received message: " << received << endl;

    return 0;
}

