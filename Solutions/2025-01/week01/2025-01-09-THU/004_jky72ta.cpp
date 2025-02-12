#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Matrix
{
    public:
        Matrix(int y, int x)
        {
            for (int i = 0; i < y; i++)
            {
                vector<int> v(y, 0);
                a.push_back(v);
            }
            
        }
        vector<vector<int>> getData() const
        {
            return (a);
        }
        
        void setData(string str)
        {
            int num;
            stringstream ss(str);
            for (int j = 0; j < this->a.size(); j++)
            {
                for (int x = 0; x < this->a[0].size(); x++)
                {
                    ss >> num;
                    (this->a)[j][x] = num;
                }
            }
        }

        vector<vector<int>> &getRealData()
        {
            return (a);
        }

        Matrix operator+(Matrix& other)
        {
            // vector<vector<int>> &other_v = other.getData();
            // int newMatrix_y = max(this->a.size(), other_v.size());
            // int newMatrix_x = max(this->a[0].size(), other_v[0].size());
            // Matrix newMatrix(newMatrix_y, newMatrix_x);
            Matrix newMatrix(this->a.size(), this->a[0].size());
            vector<vector<int>>& new_a = newMatrix.getRealData();
            vector<vector<int>>& other_a = other.getRealData();
            for (int j = 0; j < this->a.size(); j++)
            {
                for (int x = 0; x < this->a[0].size(); x++)
                {
                    new_a[j][x] = this->a[j][x] + other_a[j][x];
                }
            }
            return (newMatrix);
        }

        friend ostream &operator<<(ostream &os, Matrix &m)
        {
            vector<vector<int>>& v = m.getRealData();
            for (int j = 0; j < v.size(); j++)
            {
                for (int x = 0; x < v[0].size(); x++)
                {
                    os << v[j][x] << " ";
                }
            }
            os << char(8);
        }
        
    private:
        vector<vector<int>> a = {};
};


int main()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int round;
    ss >> round;
    for (int i = 0; i < round; i++)
    {
        str = "";
        getline(cin, str);
        ss.clear();
        ss.str(str);
        int y;
        int x;
        ss >> y;
        ss >> x;
        Matrix m(y, x);
        Matrix n(y, x);
        str = "";
        getline(cin, str);
        m.setData(str);
        str = "";
        getline(cin, str);
        n.setData(str);
        Matrix newM = m + n;
        cout << newM << endl;
    }
    return (0);
}

