#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    virtual void getdata() {};
    virtual void putdata() {};

protected:
    std::string name = "";
    int age = 0;
};

class Professor : public Person
{
public:
    virtual void getdata() override
    {
        cin >> name >> age >> publication;
    }
    virtual void putdata() override
    {
        cur_id++;
        cout << name << " " << age << " " << publication << " " << cur_id << "\n";
    }

private:
    static int cur_id;
    int publication = 0;
};

int Professor::cur_id = 0;

class Student : public Person
{
public:
    virtual void getdata() override
    {
        cin >> name >> age;
        for (int i = 0; i < 6; ++i)
        {
            cin >> marks[i];
            sum += marks[i];
        }
    }
    virtual void putdata() override
    {
        cur_id++;
        cout << name << " " << age << " " << sum << " " << cur_id << "\n";
    }

private:
    static int cur_id;
    int marks[6] = {};
    int sum = 0;
};

int Student::cur_id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    // Person* per[n];
    vector<Person*> per(n);

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}