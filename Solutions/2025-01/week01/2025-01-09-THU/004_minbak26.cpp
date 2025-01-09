#include <iostream>
#include <vector>

class Matrix {
public:
    // 2차원 배열 동적 할당
    Matrix(int row, int column)
        : row(row), column(column) {
        array = new int* [row];
        for (int i = 0; i < row; ++i) {
            array[i] = new int[column];
            std::fill_n(array[i], column, 0);
        }
    }

    // 소멸자로 동적 메모리 해제
    ~Matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    // 행렬 입력
    void input() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                std::cin >> array[i][j];
            }
        }
    }

    // 행렬 출력
    void print() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                std::cout << array[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // + 연산자 오버로딩: 두 행렬의 합 계산
    Matrix operator+(const Matrix& other) const {
        Matrix result(row, column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                result.array[i][j] = array[i][j] + other.array[i][j];
            }
        }
        return result;
    }

private:
    int row;
    int column;
    int** array; 
};

int main() {
    int testCase = 0;
    int row = 0, column = 0;

    // 테스트 케이스 수 입력 
    std::cout << "테스트 횟수 입력\n";
    std::cin >> testCase;

    // 행과 열 크기 입력
    std::cout << "행과 열을 입력하시오\n";
    std::cin >> row >> column;

    // 두 행렬 생성
    Matrix ma1(row, column);
    Matrix ma2(row, column);
    
    for(int i=0; i<testCase; i++)
    {
        // 행렬 입력
         std::cout << "첫번째 행렬:\n";
        ma1.input();

        std::cout << "두번째 행렬:\n";
        ma2.input();

        // 두 행렬의 합 계산 및 출력
        try {
            Matrix result = ma1 + ma2;
            std::cout << "행렬 합:\n";
            result.print();
        }
        catch (const std::exception& e)
            {
            std::cerr << "Error: " << e.what() << std::endl;
            }
    }
    return 0;
}
