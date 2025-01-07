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
    string name;
    int age;
};

class Professor : public Person
{
public:
    Professor()
        : publications(0)
    {
        ++cur_id;
        id = cur_id;
    }

    virtual void getdata() override
    {
        cin >> name >> age >> publications;
    }

    virtual void putdata() override
    {
        cout << name << " " << age << " " << publications << " " << id << "\n";
    }

private:
    int publications;
    static int cur_id;
    int id;
};

int Professor::cur_id = 0;

class Student : public Person
{
public:
    Student()
        : sum(0)
    {
        ++cur_id;
        id = cur_id;
    }

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
        cout << name << " " << age << " " << sum << " " << id << "\n";
    }

private:
    int marks[6] = { };
    int sum;
    static int cur_id;
    int id;
};

int Student::cur_id = 0;

// �׽�Ʈ��
int main()
{
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

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