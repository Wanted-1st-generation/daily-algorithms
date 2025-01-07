#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    virtual ~Person() {}
public:
    virtual void getdata()
    {

    }
    virtual void putdata()
    {

    }
protected:
    string name;
    int age = 0;
};


class Student : public Person
{
public:
    Student()
    {
        cur_id++;
        thisid = cur_id;
    }
public:
    virtual void getdata() override
    {
        std::cin >> name >> age;
        for (int i = 0; i < 6; i++)
        {
            std::cin >> arr[i];
            sum += arr[i];
        }

    }
    virtual void putdata() override
    {
        cout << name << " " << age << " " << sum << " " << thisid << endl;
    }

private:
    static int cur_id;
    int thisid = 0;
    int arr[6] = { 0 };
    int sum = 0;
};
int Student::cur_id = 0;

class Professor : public Person
{
public:
    Professor()
    {
        cur_id++;
        thisid = cur_id;
    }
public:
    virtual void getdata() override
    {
        std::cin >> name >> age >> publications;

    }
    virtual void putdata() override
    {
        std::cout << name << " " << age << " " << publications << " " << thisid << "\n";
    }

private:
    int publications = 0;
    int thisid = 0;
    static int cur_id;


};
int Professor::cur_id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0;i < n;i++) {

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

    return 0;

}
