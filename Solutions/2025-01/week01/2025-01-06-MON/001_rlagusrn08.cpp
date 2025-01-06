#include<iostream>

using namespace std;

typedef long long ll;

class Box
{
public:
	Box() : l(0), b(0), h(0)
	{

	}

	Box(int length, int breadth, int height)
	{
		l = length;
		b = breadth;
		h = height;
	}
	Box(const Box& rhs)
	{
		l = rhs.l;
		b = rhs.b;
		h = rhs.h;
	}

	bool operator < (const Box& other)
	{
		if (l < other.l)
		{
			return true;
		}
		else if (b < other.b && l == other.l)
		{
			return true;
		}
		else if (h < other.h && b == other.b && l == other.l)
		{
			return true;
		}

		return false;
	}
	friend ostream& operator<<(ostream& os, const Box& pos);

public:
	int getLegth() { return l; }
	int getBreadth() { return b; }
	int getHeight() { return h; }
	ll CalculateVolume() { return (ll)l * (ll)b * (ll)h; } // 범위 때문에 하나라도 형변환 하고 연산해야 함.
private:
	int l;
	int b;
	int h;
};

ostream& operator << (ostream& os, const Box& box)
{
	os << box.l << " " << box.b << " " << box.h;
	return os;
}

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