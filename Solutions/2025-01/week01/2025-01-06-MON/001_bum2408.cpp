#include <iostream>


class Box
{
public:
	Box() {}

	Box(int l, int b, int h)
		:length(l), breadth(b), height(h)
	{}

	Box(Box& other)
	{
		length = other.length;
		breadth = other.breadth;
		height = other.height;
	}

public:
	int GetLength()
	{
		return length;
	}
	int GetBreadth()
	{
		return breadth;
	}
	int GetHeight()
	{
		return height;
	}
	long long CalculateVolume()
	{
		return static_cast<long long>(length * breadth * height);
	}

public:
	bool operator<(const Box& other) const
	{
		if (length < other.length)
			return true;
		else if (breadth < other.breadth && length == other.length)
			return true;
		else if (height < other.height && breadth == other.breadth && length == other.length)
			return true;

		return false;
	}

	//스트림 연산자 오버로딩은 기억이 나질 않아 찾아보고 했습니다 ㅜ
	friend std::ostream& operator<<(std::ostream& out, const Box& a)
	{
		out << "Length: " << a.length << ", "
			<< "breath: " << a.breadth << ", "
			<< "height: " << a.height << "\n";
		return out;
	}

private:
	int length = 0;
	int breadth = 0;
	int height = 0;
};

int main()
{
	Box b1; // Should set b1.l = b1.b = b1.h = 0;
	Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
	std::cout << b2.GetLength();	// Should return 2
	std::cout << "\n";
	std::cout << b2.GetBreadth(); // Should return 3
	std::cout << "\n";
	std::cout << b2.GetHeight();	// Should return 4
	std::cout << "\n";
	std::cout << b2.CalculateVolume(); // Should return 24
	std::cout << "\n";
	bool x = (b1 < b2);
	std::cout << x;	// Should return true based on the conditions given
	std::cout << "\n";
	std::cout << b2; // Should print 2 3 4 in order.
}