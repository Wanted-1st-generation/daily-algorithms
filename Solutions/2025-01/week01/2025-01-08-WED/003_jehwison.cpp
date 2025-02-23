#include <iostream>

int main() {
    int n;
    // 배열 크기 입력
    std::cin >> n;
    // 정수형 배열 생성
    int* arr = new int[n];

    // 배열 요소 입력
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // 배열을 역순으로 출력
    for (int i = n - 1; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 메모리 해제
    delete[] arr;

    return 0;
}
