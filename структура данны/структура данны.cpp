#include <iostream>
#include <ctime>
#include "List.h"
#include "UI.h"
#include <windows.h>
using namespace std;



int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    
    Node* head = nullptr;

    UI(head);
}

