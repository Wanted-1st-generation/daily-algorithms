#include <iostream>
#include <string>

class Person {
public:
    // ���� ���� �Լ�
    virtual void getdata() = 0;
    virtual void putdata() = 0;

protected:
    std::string name;
    int age = 0;
};

class Professor : public Person {
private:
    // ��ǥ ��
    int publications = 0;
    // ���� ���̵�
    int cur_id;
    // ���̵� ī����: static ������ ����
    static int id_counter;

public:
    Professor() {
        // ���� ���̵� �Ҵ�
        cur_id = ++id_counter;
    }

    void getdata() {
        // ������ �Է�
        std::cin >> name >> age >> publications;
    }

    void putdata() {
        // ���� ���� ���
        std::cout << name << " " << age << " " << publications << " " << cur_id << std::endl;
    }
};

class Student : public Person {
public:
    Student() {
        // ���� ���̵� �Ҵ�
        cur_id = ++id_counter;
    }

    void getdata() {
        // �̸�, ���� �Է�
        std::cin >> name >> age;
        // ���� ���� �Է�
        for (int i = 0; i < 6; i++) {
            std::cin >> marks[i];
        }
    }

    void putdata() {
        int sum = 0;
        // ���� �� ���
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        // �л� ���� ���
        std::cout << name << " " << age << " " << sum << " " << cur_id << std::endl;
    }

private:
    int marks[6] = { 0, };
    // ���� ���̵�
    int cur_id;
    // ���̵� ī����: static ������ ����
    static int id_counter;
};

// static ���� �ʱ�ȭ
int Professor::id_counter = 0;
int Student::id_counter = 0;

int main() {
    // ������ ��ü ��
    int n;
    std::cin >> n;

    // ���� �迭 �Ҵ�
    Person** per = new Person * [n];

    for (int i = 0; i < n; i++) {
        int menu;
        std::cin >> menu;
        // �Է� ������ �޴�: 1, 2
        if (menu == 1) {
            per[i] = new Professor();
        }
        else {
            per[i] = new Student();
        }
        // ������ �Է�
        per[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        // ������ ���
        per[i]->putdata();
        // ���� �޸� ����
        delete per[i];
    }
    // ���� �迭 ����
    delete[] per;

    return 0;
}
