#include <iostream>
#include <cstdlib> 

int main()
{
    int n = 0;
    std::cin >> n;

    int* arr = (int*)std::malloc(sizeof(int) * n);  
    int* arr2 = (int*)std::malloc(sizeof(int) * n); 

    // 메모리 할당 실패 처리
    if (arr == nullptr || arr2 == nullptr) { 
        std::cerr << "메모리 할당 실패" << std::endl;
        return;
    }

    //arr에 입력받기
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];  
    }
    //arr2
    for (int i = 0; i < n; i++) {
        arr2[n - i - 1] = arr[i];  
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // 메모리 해제
    std::free(arr);
    std::free(arr2);

    return 0;
}
