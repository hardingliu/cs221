#include <iostream>

using namespace std;

int global_array[10];

void fill_array(int f_v, int increment)
{
    int acc = f_v;
    for (int i = 1; i <= 10; i++)
    {
        global_array[i] = acc;
        acc += increment;
    }
}

int main(void)
{
    fill_array(4, 2);
    for (int i = 1; i <= 10; i++)
    {
        cout << global_array[i] << endl;
    }
}
