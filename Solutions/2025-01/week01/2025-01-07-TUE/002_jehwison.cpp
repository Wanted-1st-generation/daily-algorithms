#include <iostream>
#include <string>

class Person {
public:
    // 순수 가상 함수
    virtual void getdata() = 0;
    virtual void putdata() = 0;

protected:
    std::string name;
    int age = 0;
};

class Professor : public Person {
private:
    // 발표 수
    int publications = 0;
    // 현재 아이디
    int cur_id;
    // 아이디 카운터: static 변수로 선언
    static int id_counter;

public:
    Professor() {
        // 고유 아이디 할당
        cur_id = ++id_counter;
    }

    void getdata() {
        // 데이터 입력
        std::cin >> name >> age >> publications;
    }

    void putdata() {
        // 교수 정보 출력
        std::cout << name << " " << age << " " << publications << " " << cur_id << std::endl;
    }
};

class Student : public Person {
public:
    Student() {
        // 고유 아이디 할당
        cur_id = ++id_counter;
    }

    void getdata() {
        // 이름, 나이 입력
        std::cin >> name >> age;
        // 과목 점수 입력
        for (int i = 0; i < 6; i++) {
            std::cin >> marks[i];
        }
    }

    void putdata() {
        int sum = 0;
        // 점수 합 계산
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        // 학생 정보 출력
        std::cout << name << " " << age << " " << sum << " " << cur_id << std::endl;
    }

private:
    int marks[6] = { 0, };
    // 현재 아이디
    int cur_id;
    // 아이디 카운터: static 변수로 선언
    static int id_counter;
};

// static 변수 초기화
int Professor::id_counter = 0;
int Student::id_counter = 0;

int main() {
    // 생성할 객체 수
    int n;
    std::cin >> n;

    // 동적 배열 할당
    Person** per = new Person * [n];

    for (int i = 0; i < n; i++) {
        int menu;
        std::cin >> menu;
        // 입력 가능한 메뉴: 1, 2
        if (menu == 1) {
            per[i] = new Professor();
        }
        else {
            per[i] = new Student();
        }
        // 데이터 입력
        per[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        // 데이터 출력
        per[i]->putdata();
        // 동적 메모리 해제
        delete per[i];
    }
    // 동적 배열 해제
    delete[] per;

    return 0;
}
