#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{

    int generatedN;
    char guessN[100];

    srand(time(NULL));

    generatedN = rand() % 100 + 1;

    int i = atoi(guessN);

    do
    {
        cout << "Guess the number(if you want to quit, please input anything other than an integer from 1 to 100): ";
        cin >> i;
        if ((i < 1) || (i > 100))
        {
            cout << "Try next time, bye!" << endl;
            return 0;
        }
        if (generatedN != i)
        {
            cout << "Try again!" << endl;
        }
    } while (generatedN != i);

    cout << "Correct!" << endl;

    return 0;
}
