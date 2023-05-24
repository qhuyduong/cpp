#include <exception>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Define the exception here */
class BadLengthException : public exception {
public:
    virtual const char* what() noexcept {
        num_char = new char[length + sizeof(char)];
        sprintf(num_char, "%d", length);
        return num_char;
    }
    BadLengthException(int n) : length{n} {
    }
    ~BadLengthException() {
        delete[] num_char;
    }

private:
    const int length;
    char* num_char;
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}