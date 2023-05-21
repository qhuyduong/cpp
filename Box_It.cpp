#include <bits/stdc++.h>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

// Overload operator < as specified
// bool operator<(Box& b)

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)
class Box
{
public:
    Box() : length{0}, breadth{0}, height{} {}
    Box(int l, int b, int h) : length{l}, breadth{b}, height{h} {}
    Box(Box &B)
    {
        length = B.length;
        height = B.height;
        breadth = B.breadth;
    }

    int getLength() { return length; }
    int getHeight() { return height; }
    int getBreadth() { return breadth; }
    long long CalculateVolume() { return (long long) length * height * breadth; }

    friend ostream &operator<<(ostream &o, const Box &B)
    {
        o << B.length << " " << B.breadth << " " << B.height;

        return o;
    }

    friend bool operator<(const Box &A, const Box &B)
    {
        if (A.length < B.length)
            return true;

        if (A.breadth < B.breadth && A.length == B.length)
            return true;

        if (A.height < B.height && A.breadth == B.breadth && A.length == B.length)
            return true;

        return false;
    }

private:
    int length;
    int height;
    int breadth;
};

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}