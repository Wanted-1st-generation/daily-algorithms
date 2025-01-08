#include <iostream>
#include <conio.h>

const char *OVER_VALUE = "over value"; 
const char *WRONG_INPUT = "worng input";
const char *SCARCE = "Item is scarce";

struct MyArray
{
    public:
        MyArray(int size)
            : size(size)
        {
        }

        int& operator[](int idx)
        {
            return (array[idx]);
        }
        int *begin()
        {
            return (this->array);
        }
        int *end()
        {
            return (&this->array[(size)]);
        }
        int getSize()
        {
            return (size);
        }
    private:
        int size;
        int array[1000];
};

void ConsoleBackSpace();

bool ErrorMessage(const wchar_t *errorMessage);

bool InputArraySize(int &size);

bool InputArrayItem(MyArray &arr);

int strlen(MyArray arr);

void sort(int *a, int *b, bool (*compare)(int a, int b));

void reverse(int *a, int *b);

void printArray(int *a, int size);

int main()
{
    
    int size = 0;
    if (InputArraySize(size) == false)
        return (0);
    MyArray arr(size);
    if (InputArrayItem(arr) == false)
        return (0);
    reverse(arr.begin(), arr.end());
    printArray(arr.begin(), size);

    return (0);
}

void ConsoleBackSpace()
{
    std::cout << (char)8;
    std::cout << ' ';
    std::cout << (char)8;
}

bool ErrorMessage(const char *errorMessage)
{
    system("cls");
    std::cout << errorMessage << std::endl;
    return (false);
}

bool InputArraySize(int &size)
{
    std::cout << "you try input array distance(only number), and input anter" << std::endl;
    int a = 0;
    int count = 0;
    char str[5] = {};
    do{
        a = getch();
        if (isdigit(a) == false && a != 13 && a != 8)
        {
            ErrorMessage(WRONG_INPUT);
            return (false);
        }
        if (a == 8 && count > 0)
        {
            ConsoleBackSpace();
            count = count - 1;
            str[count] = 0;
        }
        else if (isdigit(a) == true)
        {
            str[count] = (char)a;
            std::cout << (char)a;
            if (count >= 3)
            {
                int ans = atoi(str);
                if (ans > 1000)
                    return (ErrorMessage(OVER_VALUE));
            }
            count = count + 1;
        }
    } while (a != 13);
    if (str[0] == 0)
        return (ErrorMessage(WRONG_INPUT));
    size = atoi(str);
    return (true);
}

int strlen(MyArray arr)
{
    return (arr.getSize());
}

bool InputArrayItem(MyArray &arr)
{
    system("cls");
    std::cout << "you try input array item(only number),Please separate it by space and type enter at the end " << std::endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
        int count = 0;
        int a = 0;
        char str[6] = {};
        do{
            a = getch();
            if (isdigit(a) == false && a != 13 && a != 8 && a != 32)
                return (ErrorMessage(WRONG_INPUT));
            if (a == 8 && count > 0)
            {
                ConsoleBackSpace();
                count = count - 1;
                str[count] = 0;
            }
            else if (a == 13)
            {
                if (i == arr.getSize() - 1 && count != 0)
                    break ;
                return (ErrorMessage(SCARCE));
            }
            else if (a == 32)
            {
                if (count == 0)
                    return (ErrorMessage(WRONG_INPUT));
                std::cout << (char)a;
            }
            else if (isdigit(a))
            {
                str[count] = (char)a;
                std::cout << (char)a;
                if (count >= 4)
                {
                    int ans = atoi(str);
                    if (ans > 10000)
                        return (ErrorMessage(OVER_VALUE));
                }
                count = count + 1;
            }
        } while (a != 32);
        arr[i] = atoi(str);
    }
    return (true);
}

void reverse(int *a, int *b)
{

    int addr_dis = reinterpret_cast<char *>(b) - reinterpret_cast<char *>(a);
    for (int start = 0, count = ((addr_dis / sizeof(int)) - 1); start < count; start++, count--)
    {
        int temp = *(a + start);
        *(a + start) = *(a + count);
        *(a + count) = temp;
    }
}

void printArray(int *a, int size)
{
    system("cls");
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << a[size - 1];
}


void sort(int *a, int *b, bool (*compare)(int a, int b))
{
    int *start = a;
    for (; start != b; start++)
    {
        for (int *memo = start + 1; memo != b; memo++)
        {
            if (compare(*start, *memo))
            {
                int temp = *start;
                *start = *memo;
                *memo = temp;
            }
        }
       
    }
}

bool upp(int a, int b)
{
    return (a > b);
}

bool downn(int a, int b)
{
    return (a < b);
}