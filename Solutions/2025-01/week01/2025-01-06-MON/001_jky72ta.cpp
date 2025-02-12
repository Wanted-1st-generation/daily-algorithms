#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <sstream>

class Box
{
    public :
        Box()
            : _l(0), _b(0), _h(0)
        {
        }
        Box(int l, int b, int h)
            : _l(l), _b(b), _h(h)
        {
        }
        Box(const Box& other)
        {
            this->_l = other._l;
            this->_b = other._b;
            this->_h = other._h;
        }
        ~Box() {}
        int getLength() const { return (this->_l); }
        int getBreadth() const { return (this->_b); }
        int getHeight() const { return (this->_h); }
        long long CalculateVolume()
        {
            return (static_cast<long long>(this->_l) * \
                    static_cast<long long>(this->_b) * \
                    static_cast<long long>(this->_h));
        }
        bool operator<(const Box &other) const
        {
            if (this->_l == other._l)
            {
                if (this->_b == other._b)
                {
                    return (this->_h < other._h);
                }
                return (this->_b < other._b);
            }
            return (this->_l < other._l);
        }
        friend std::ostream& operator<<(std::ostream& os, Box& B)
        {
            os << B._l << " " << B._b << " " << B._h;
        }
    private :
        int _l;
        int _b;
        int _h;
};

#endif

using namespace std;

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout << temp << endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout << temp << endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

void check1(char *str)
{
    FILE* rFile = fopen(str, "r");
    stringstream ss;
    if (rFile == nullptr)
	{
		cout << "no read " << feof(rFile) << endl;
		return ;
	}
	Box temp;
    while (!feof(rFile))
    {
        int n;
        fscanf(rFile, "%d", &n);
        for(int i=0;i<n;i++)
	    {
		    int type;
		    fscanf(rFile, "%d", &type);
		    if(type ==1)
		    {
		    	ss << temp << endl;
		    }
		    if(type == 2)
		    {
		    	int l,b,h;
				fscanf(rFile, " %d%d%d" ,&l, &b, &h);
		    	Box NewBox(l,b,h);
		    	temp=NewBox;
		    	ss << temp << endl;
		    }
		    if(type==3)
		    {
		    	int l,b,h;
				fscanf(rFile, "%d%d%d" ,&l, &b, &h);
		    	Box NewBox(l,b,h);
		    	if(NewBox<temp)
		    	{
		    		ss << "Lesser" << endl;
		    	}
		    	else
		    	{
		    		ss << "Greater" << endl;
		    	}
		    }
		    if(type==4)
		    {
		    	ss << temp.CalculateVolume() << endl;
		    }
		    if(type==5)
		    {
		    	Box NewBox(temp);
		    	ss << NewBox << endl;
		    }

	    }
		ss << endl;
    }

    cout << ss.str() << endl;
}

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        check2();
    }
	check1(argv[1]);
}