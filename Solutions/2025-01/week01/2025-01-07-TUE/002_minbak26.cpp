
#include <iostream>
#include <string>
using namespace std;

class Person {
//순수 가상함수
public:
    virtual void getdata() = 0; 
    virtual void putdata() = 0; 
    virtual ~Person() {}       

protected:
    string name;
    int age;
};

class Professor : public Person {
public:
//생성자 호출시 아이디 증가
    Professor() {
        ++cur_id;
    }

    void getdata() override {
        cin >> name >> age >> publication;
    }

    void putdata() override {
        cout << name << " " << age << " " << publication << " " << cur_id << "\n";
    }

private:
    int publication;
    static int cur_id; 
};

//맴버초기화로 인한 초기화 (이부분 알아보고 있는데 피드백 바랍니다)
//클래스안에서 초기화 하면 오류
int Professor::cur_id = 0;

class Student : public Person {
public:
    Student() : sum_mark(0) {} 

    void getdata() override {
        cin >> name >> age;
        sum_mark = 0;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
            sum_mark += marks[i];
        }
        ++cur_id;
    }

    void putdata() override {
        cout << name << " " << age << " " << sum_mark << " " << cur_id << "\n";
    }

private:
    int marks[6];
    int sum_mark;
    static int cur_id; 
};
//맴버초기화로 인한 초기화 (이부분 알아보고 있는데 피드백 바랍니다)
//클래스안에서 초기화 하면 오류
int Student::cur_id = 0;

int main() {
    int n, val;
    cin >> n; 
    Person** per = new Person * [n]; 

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            per[i] = new Professor; 
        }
        else {
            per[i] = new Student;   
        per[i]->getdata(); 
    }

    for (int i = 0; i < n; i++) {
        per[i]->putdata(); 
        delete per[i];     
    }

    delete[] per; 

    return 0;
}
