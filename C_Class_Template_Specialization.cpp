#include <iostream>
#include <string>
using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

#define stringify(name) #name

template <typename T>
struct Traits;

// Define specializations for the Traits class template here.
template <>
struct Traits<Fruit> {
    static string name(int index) {
        string result;

        switch (index) {
            case static_cast<int>(Fruit::apple):
                result = "apple";
                break;
            case static_cast<int>(Fruit::orange):
                result = "orange";
                break;
            case static_cast<int>(Fruit::pear):
                result = "pear";
                break;
            default:
                result = "unknown";
                break;
        }

        return result;
    }
};

template <>
struct Traits<Color> {
    static string name(int index) {
        string result;

        switch (index) {
            case static_cast<int>(Color::red):
                result = "red";
                break;
            case static_cast<int>(Color::green):
                result = "green";
                break;
            case static_cast<int>(Color::orange):
                result = "orange";
                break;
            default:
                result = "unknown";
                break;
        }

        return result;
    }
};

int main() {
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
