#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Spell {
private:
    string scrollName;

public:
    Spell() : scrollName("") {
    }
    Spell(string name) : scrollName(name) {
    }
    virtual ~Spell() {
    }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private:
    int power;

public:
    Fireball(int power) : power(power) {
    }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private:
    int power;

public:
    Frostbite(int power) : power(power) {
    }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private:
    int power;

public:
    Thunderstorm(int power) : power(power) {
    }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private:
    int power;

public:
    Waterbolt(int power) : power(power) {
    }
    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) {
    if (Fireball* s = dynamic_cast<Fireball*>(spell); s != nullptr)
        s->revealFirepower();
    else if (Frostbite* s = dynamic_cast<Frostbite*>(spell); s != nullptr)
        s->revealFrostpower();
    else if (Waterbolt* s = dynamic_cast<Waterbolt*>(spell); s != nullptr)
        s->revealWaterpower();
    else if (Thunderstorm* s = dynamic_cast<Thunderstorm*>(spell); s != nullptr)
        s->revealThunderpower();
    else {
        string scroll = spell->revealScrollName();
        string journal = SpellJournal::journal;
        int m = scroll.length();
        int n = journal.length();

        int L[m + 1][n + 1];

        // Following steps build L[m+1][n+1] in bottom up
        // fashion. Note that L[i][j] contains length of LCS of
        // X[0..i-1] and Y[0..j-1]
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (scroll[i - 1] == journal[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        cout << L[m][n] << endl;
    }
}

class Wizard {
public:
    Spell* cast() {
        Spell* spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        } else if (s == "frost") {
            spell = new Frostbite(power);
        } else if (s == "water") {
            spell = new Waterbolt(power);
        } else if (s == "thunder") {
            spell = new Thunderstorm(power);
        } else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}