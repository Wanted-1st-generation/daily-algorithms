#include <iostream>
#include <vector>

class Matrix {
public:
    // 행렬을 초기화하는 생성자
    Matrix(int n, int m) : rows(n), cols(m) {
        // n x m 크기의 행렬 생성
        a.resize(n, std::vector<int>(m)); 
    }

    // 행렬 데이터를 입력받는 함수
    void inputMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 행렬 요소 입력
                std::cin >> a[i][j]; 
            }
        }
    }

    // '+' 연산자 오버로딩
    Matrix operator+(const Matrix& other) {
        // 결과 행렬 생성
        Matrix result(rows, cols); 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 행렬 요소 더하기
                result.a[i][j] = this->a[i][j] + other.a[i][j];
            }
        }
        return result;
    }

    // 행렬을 출력하는 함수
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 각 요소 출력
                std::cout << a[i][j] << " ";
            }
            // 개행
            std::cout << std::endl; 
        }
    }

private:
    // 행렬 데이터를 저장할 벡터
    std::vector<std::vector<int>> a; 
    // 행의 수
    int rows;
    // 열의 수
    int cols;
};

int main() {
    int T;
    // 테스트 케이스 개수 입력
    std::cin >> T;
    while (T--) {
        int N, M;
        // 행렬의 행과 열 입력
        std::cin >> N >> M;
        // 행렬 생성
        Matrix matrix1(N, M);
        Matrix matrix2(N, M);

        // 행렬 입력
        matrix1.inputMatrix(); 
        matrix2.inputMatrix(); 

        // 행렬 덧셈 수행
        Matrix result = matrix1 + matrix2;
        // 결과 행렬 출력
        result.printMatrix();
    }
    return 0;
}
