
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Person
{
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
protected:
    char name[101];
    int age;
    int id = 0;
};

class Professor : public Person
{
public:
    virtual void getdata()
    {
        cin >> name >> age >> publications;
        id = ++cur_id;
    };
    virtual void putdata()
    {
        cout << name << " " << age << " " << publications
            << " " << id << '\n';
    };

private:
    int publications = 0;
    static int cur_id;
};


class Student : public Person
{
public:
    virtual void getdata()
    {
        cin >> name >> age;
        for (int i = 0; i < 6;i++)
        {
            cin >> score[i];
        }
        id = ++cur_id;
    };
    virtual void putdata()
    {
        int sum = 0;
        for (int i = 0; i < 6;i++)
        {
            sum += score[i];
        }
        cout << name << " " << age << " " << sum << " " << id
            << '\n';
    };

private:
    int score[6] = { 0, };
    static int cur_id;
};

int Professor::cur_id = 0;
int Student::cur_id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person** per = new Person * [n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0;i < n;i++)
        per[i]->putdata(); // Print the required output for each object.

    delete[] per;
    return 0;

}
