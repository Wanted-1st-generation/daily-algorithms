#include <iostream>
#include <vector>

class Matrix {
public:
    // ����� �ʱ�ȭ�ϴ� ������
    Matrix(int n, int m) : rows(n), cols(m) {
        // n x m ũ���� ��� ����
        a.resize(n, std::vector<int>(m)); 
    }

    // ��� �����͸� �Է¹޴� �Լ�
    void inputMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // ��� ��� �Է�
                std::cin >> a[i][j]; 
            }
        }
    }

    // '+' ������ �����ε�
    Matrix operator+(const Matrix& other) {
        // ��� ��� ����
        Matrix result(rows, cols); 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // ��� ��� ���ϱ�
                result.a[i][j] = this->a[i][j] + other.a[i][j];
            }
        }
        return result;
    }

    // ����� ����ϴ� �Լ�
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // �� ��� ���
                std::cout << a[i][j] << " ";
            }
            // ����
            std::cout << std::endl; 
        }
    }

private:
    // ��� �����͸� ������ ����
    std::vector<std::vector<int>> a; 
    // ���� ��
    int rows;
    // ���� ��
    int cols;
};

int main() {
    int T;
    // �׽�Ʈ ���̽� ���� �Է�
    std::cin >> T;
    while (T--) {
        int N, M;
        // ����� ��� �� �Է�
        std::cin >> N >> M;
        // ��� ����
        Matrix matrix1(N, M);
        Matrix matrix2(N, M);

        // ��� �Է�
        matrix1.inputMatrix(); 
        matrix2.inputMatrix(); 

        // ��� ���� ����
        Matrix result = matrix1 + matrix2;
        // ��� ��� ���
        result.printMatrix();
    }
    return 0;
}
