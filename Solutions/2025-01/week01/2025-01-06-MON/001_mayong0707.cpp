#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box
{
public:
	Box()
		: length(0), breadth(0), height(0)
	{

	}
	Box(int length, int breadth, int height)
		: length(length), breadth(breadth), height(height)
	{

	}
	const int getLength()
	{
		return length;
	}
	const int getBreadth()
	{
		return breadth;
	}
	const int getHeight()
	{
		return height;
	}
	const ll CalculateVolume()
	{
		return length * breadth * height;
	}

	// Operator Overloading
	bool operator<(Box& other)
	{
		if (this->length == other.length)
		{
			if (this->breadth == other.breadth)
			{
				return this->length < other.length;
			}
			return this->breadth < other.breadth;
		}
		return this->length < other.length;
	}

	friend ostream& operator<<(ostream& os, Box& right)
	{
		os << right.length << " " << right.breadth << " " << right.height;
		return os;
	}

private:
	int length;
	int breadth;
	int height;

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