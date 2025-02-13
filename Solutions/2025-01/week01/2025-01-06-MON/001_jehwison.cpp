#include<iostream>

using namespace std;

class Box {
public:
    // 생성자
    Box() : l(0), b(0), h(0) {}
    Box(int l, int b, int h) : l(l), b(b), h(h) {}
    Box(const Box& box) : l(box.l), b(box.b), h(box.h) {}

    // 박스 길이 반환 함수
    int getLength() const { return l; }
    // 박스 너비 반환 함수
	int getBreadth() const { return b; }
    // 박스 높이 반환 함수
	int getHeight() const { return h; }

    // 박스 부피 계산 함수
    long long CalculateVolume() const {
        return static_cast<long long>(l) * b * h;
    }

    // 비교 연산자(<) 오버로딩
    bool operator<(const Box& box) const {
		// 현재 박스의 길이가 비교 대상 박스의 길이보다 짧으면 true 반환
        if (l < box.l) return true;
		// 길이가 같은 경우, 현재 박스의 너비가 비교 대상 박스의 너비보다 작으면 true 반환
        if (l == box.l && b < box.b) return true;
		// 길이와 너비가 같은 경우, 현재 박스의 높이가 비교 대상 박스의 높이보다 낮으면 true 반환
        if (l == box.l && b == box.b && h < box.h) return true;
		// 위 조건문에 해당하지 않는 경우 false 반환
        return false;
    }

    // 박스의 길이, 너비, 높이를 출력하기 위한 << 연산자 오버로딩
    friend ostream& operator<<(ostream& out, const Box& box) {
        out << box.l << " " << box.b << " " << box.h;
        return out;
    }

private:
	// 멤버 변수(박스의 길이, 너비, 높이)
    int l, b, h;
};

// 명령 처리 함수
void processBoxCommands() {
    // 처리할 명령의 개수
	int numberOfOrders;
	// 명령 개수 입력	
    cin >> numberOfOrders;

	// 기본 생성자를 통해 박스 생성
    Box currentBox;

    // 명령 처리 로직
    for (int i = 0; i < numberOfOrders; i++) {
		// 명령 타입
        int commandType;
		// 처리할 명령의 타입 입력
        cin >> commandType;

        switch (commandType) {
            case 1: {
                // 명령 1: 현재 박스의 길이, 너비, 높이 출력
                cout << currentBox << endl;
                break;
            }
            case 2: {
                // 명령 2: 새로운 박스의 정보를 입력받아 현재 박스를 수정 후 출력
                int l, b, h;
                cin >> l >> b >> h;
				// 새로운 박스 객체 생성
                Box newBox(l, b, h);
				// 현재 박스를 새 박스로 업데이트
                currentBox = newBox;
				// 업데이트된 박스의 길이, 너비, 높이 출력
                cout << currentBox << endl;
                break;
            }
            case 3: {
                // 명령 3: 새로운 박스를 입력받아 현재 박스와 비교
                int l, b, h;
                cin >> l >> b >> h;
                Box newBox(l, b, h);
                if (newBox < currentBox) {
					// 입력된 박스가 더 작은 경우
                    cout << "New box is smaller than current box\n";
                } else {
					// 입력된 박스가 더 큰 경우
                    cout << "New box is bigger than current box\n";
                }
                break;
            }
            case 4: {
                // 명령 4: 현재 박스의 부피 계산 및 출력
                cout << currentBox.CalculateVolume() << endl;
                break;
            }
            case 5: {
                // 명령 5: 현재 박스를 복사하여 출력
                Box newBox(currentBox);
                cout << newBox << endl;
                break;
            }
            default:
				// 잘못된 입력 시
                cout << "Invalid command\n";
				i--;
				break;
        }
    }
}

// 메인 함수
int main() {
    processBoxCommands();  // 명령 처리 함수 호출
    return 0;
}
