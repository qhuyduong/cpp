#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start_time;
    int duration;

    Workshop() {
    }
    Workshop(int start_time, int duration)
        : start_time{start_time}, duration{duration} {
    }

    friend bool operator<(const Workshop& a, const Workshop& b) {
        return a.start_time < b.start_time;
    }

    Workshop& operator=(const Workshop& other) {
        if (this != &other) { // Check for self-assignment
            start_time = other.start_time;
            duration = other.duration;
        }
        return *this;
    }
};

struct Available_Workshops {
    int n;
    Workshop* workshops;

    Available_Workshops(int n) : n{n} {
        workshops = new Workshop[n];
    }
    ~Available_Workshops() {
        delete[] workshops;
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops(n);

    for (int i = 0; i < n; i++) {
        Workshop w(start_time[i], duration[i]);
        aw->workshops[i] = w;
    }
    sort(aw->workshops, aw->workshops + n);

    return aw;
}

void swap(Workshop& a, Workshop& b) {
    Workshop tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    Workshop* workshops = ptr->workshops;
    int n = ptr->n;

    int count = 1;

    for (int i = 1; i < n; i++) {
        if (workshops[n - i].start_time >=
            workshops[n - i - 1].start_time + workshops[n - i - 1].duration) {
            count += 1;
        } else {
            swap(workshops[n - i], workshops[n - i - 1]);
        }
    }

    return count;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
