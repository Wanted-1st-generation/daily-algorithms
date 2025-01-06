#include<iostream>

class Box
{
public:
	Box()
		:i(0), b(0), h(0)
	{

	}
	Box(int l, int b, int h) : i(l), b(b), h(h) {}

	Box(const Box& other) //복사생성자
	{
		i = other.i;
		b = other.b;
		h = other.h;
	}

	~Box()
	{
	}

	int getLength()
	{
		return i;
	}
	int getBreadth()
	{
		return b;
	}
	int getHight()
	{
		return h;
	}
	long long CalculateVolume()
	{
		return i * b * h;
	}

	//연산자 < 오버로딩
	bool operator<(const Box& box)
	{
		if (i < box.i) return true;
		else if (b < box.b && i == box.i) return true;
		else if (h < box.h && b == box.b && i == box.i) return true;
		else return false;

	}
	//연산자 << 오버로딩
	friend std::ostream& operator << (std::ostream& out, const Box& box)
	{
		out << box.i << " " << box.b << " " << box.h;
		return out;

	}

private:
	int i;
	int b;
	int h;

};


//사이트 테스트 코드
void check2()
{
	int n;
	std::cin >> n;
	Box temp;
	for (int i = 0;i < n;i++)
	{
		int type;
		std::cin >> type;
		if (type == 1)
		{
			std::cout << temp << std::endl;
		}
		if (type == 2)
		{
			int I, b, h;
			std::cin >> I >> b >> h;
			Box NewBox(I, b, h);
			temp = NewBox;
			std::cout << temp << std::endl;
		}
		if (type == 3)
		{
			int I, b, h;
			std::cin >> I >> b >> h;
			Box NewBox(I, b, h);
			if (NewBox < temp)
			{
				std::cout << "Lesser\n";
			}
			else
			{
				std::cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			std::cout << temp.CalculateVolume() << std::endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			std::cout << NewBox << std::endl;
		}

	}
}

int main()
{
	check2();
}
