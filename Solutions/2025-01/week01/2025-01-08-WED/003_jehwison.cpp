#include <iostream>

int main() {
    int n;
    // �迭 ũ�� �Է�
    std::cin >> n;
    // ������ �迭 ����
    int* arr = new int[n];

    // �迭 ��� �Է�
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // �迭�� �������� ���
    for (int i = n - 1; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // �޸� ����
    delete[] arr;

    return 0;
}
