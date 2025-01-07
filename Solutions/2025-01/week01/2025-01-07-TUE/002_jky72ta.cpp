#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person 
{
    public:
        virtual void getdata()
        {
            cin >> this->name >> this->age;
        };
        virtual void putdata() const
        {
            cout << this->name << " " << this->age << " ";
        };
    private:
        std::string name;
        int age;
};

class Professor : public Person 
{
    public:
        static int id;
        Professor()
        {
            this->cur_id = Professor::id;
            Professor::id = Professor::id + 1;
        }
        virtual void getdata() override
        {
            Person::getdata();
            cin >> this->publications;
        }
        virtual void putdata() const override
        {
            Person::putdata();
            cout << this->publications << " " << this->cur_id << endl;
        }
    private:
        int publications;
        int cur_id;
};

int Professor::id = 1;

class Student : public Person
{
    public:
        Student()
        {
            this->cur_id = Student::id;
            Student::id = Student::id + 1;
        }
        static int id;
        virtual void getdata() override
        {
            Person::getdata();
            for (int i = 0; i < 6; i++)
            {
                cin >> this->marks[i];
            }
        }
        virtual void putdata() const override
        {
            Person::putdata();
            int totalCount = 0;
            for (int i = 0; i < 6; i++)
            {
                totalCount = totalCount + this->marks[i];
            }
            cout << totalCount << " " << this->cur_id << endl;
        }
    private:
        int marks[6];
        int cur_id;
};

int Student::id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[100];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}