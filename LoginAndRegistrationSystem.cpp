#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register user
void registerUser() {
    string username, password;
    cout << "\n--- Register ---\n";
    cout << "Enter Username: ";
    cin >> username;

    // Check if username already exists
    ifstream checkFile("users.txt");
    string u, p;
    while (checkFile >> u >> p) {
        if (u == username) {
            cout << "Username already exists. Try another.\n";
            checkFile.close();
            return;
        }
    }
    checkFile.close();

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

// Function to login user
void loginUser() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool found = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "Login Successful! Welcome " << username << endl;
    else
        cout << "Invalid Username or Password.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Login System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
