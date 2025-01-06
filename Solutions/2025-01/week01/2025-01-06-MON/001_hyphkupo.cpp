#include <iostream>
using namespace std;

class Box
{
public:
	Box()
		: l(0), b(0), h(0)
	{
	}

	Box(int l, int b, int h)
		: l(l), b(b), h(h)
	{
	}

	Box(const Box& other)
		: l(other.l), b(other.b), h(other.h)
	{
	}

	int getLength()
	{
		return l;
	}

	int getBreadth()
	{
		return b;
	}

	int getHeight()
	{
		return h;
	}

	long long CalculateVolume()
	{
		return l * b * h;
	}

	bool operator<(const Box& other)
	{
		if (l < other.l)
		{
			return true;
		}

		else if (l == other.l && b < other.b)
		{
			return true;
		}

		else if (b == other.b && l == other.l && h < other.h)
		{
			return true;
		}

		return false;
	}

	friend ostream& operator<<(ostream& os, const Box& other)
	{
		os << other.l << " " << other.b << " " << other.h;
		return os;
	}

private:
	int l;		// length
	int b;		// breadth
	int h;		// height
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}