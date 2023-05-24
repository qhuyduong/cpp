#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    virtual void getdata() {
    }

    virtual void putdata() {
    }

protected:
    string name;
    int age;
};

class Professor : public Person {
public:
    Professor() : cur_id(inc()) {
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }

    int inc() {
        return ++total_id;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id
             << endl;
    }

private:
    int publications;
    int cur_id;
    static int total_id;
};
int Professor::total_id = 0;

class Student : public Person {
public:
    Student() : cur_id(++total_id) {
    }

    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            int tmp;
            cin >> tmp;
            marks_sum += tmp;
        }
    }

    void putdata() override {
        cout << name << " " << age << " " << marks_sum << " " << cur_id << endl;
    }

private:
    int marks_sum = 0;
    int cur_id;
    static int total_id;
};
int Student::total_id = 0;

int main() {

    int n, val;
    cin >> n; // The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        } else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata();        // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
