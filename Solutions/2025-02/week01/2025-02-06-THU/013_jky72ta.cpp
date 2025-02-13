#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") { }
    Spell(string name) : scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power) : power(power) { }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power) : power(power) { }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power) : power(power) { }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power) : power(power) { }
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
    void MyFun(Spell * spell);
    MyFun(spell);

}

#include <cstring>

void MyFun(Spell* spell)
{
    if (Fireball* obj = dynamic_cast<Fireball*>(spell)) {
        obj->revealFirepower();
    }
    else if (Frostbite* obj = dynamic_cast<Frostbite*>(spell)) {
        obj->revealFrostpower();
    }
    else if (Thunderstorm* obj = dynamic_cast<Thunderstorm*>(spell)) {
        obj->revealThunderpower();
    }
    else if (Waterbolt* obj = dynamic_cast<Waterbolt*>(spell)) {
        obj->revealWaterpower();
    }
    else {
        const string& s1 = SpellJournal::read();
        const string& s2 = spell->revealScrollName();
        int max_s1 = s1.size();
        int max_s2 = s2.size();
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= max_s1; ++i)
        {
            for (int j = 1; j <= max_s2; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[max_s1][max_s2] << endl;
    }
}

class Wizard {
public:
    Spell* cast() {
        Spell* spell;
        string s; cin >> s;
        int power; cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        }
        else if (s == "frost") {
            spell = new Frostbite(power);
        }
        else if (s == "water") {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
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