#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    short digit,fg,bg,bright;
    srand(time(NULL));
    while(true) {
        bright = rand() % 2;
        digit = rand() % 10;
        fg=rand() % 8 + 30;
        bg=rand() % 8 + 40;
        cout << "\033[" << bright << ";" << fg << ";" << bg << "m" << digit << "\033[0m";
    }
    return 0;
}

