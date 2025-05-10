#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    while (true) {
        cout << "rudra-shell> ";
        getline(cin, input);

        if (input == "exit") break;

        system(input.c_str());  // Execute command in cmd
    }

    return 0;
}
