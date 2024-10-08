#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void UI(Node*& head) 
{
    int temp = 0;
    char continueOp = 'y';
    int op = 0;
    Date tempData{};
    Date tempo{};

    for (int i = 0; i < 30; ++i)
    {
        addElemStart(head);
    }

    while (continueOp == 'y' || continueOp == 'Y')
    {
        cout << "1 - ���������� � ������\n2 - ���������� � �����\n3 - ���������� ����� ������������� ��������\n4 - �������� ����� ������\n5 - �������� ������\n6 - �������� ����� ���������\n7 - �������� ���������� ��������\n8 - �������� ���� ���������\n9 - ����� �� �����\n10 - ������� �������, ������� ����������� ���� �����\n11 - ������� �����, ������� ������ ������ �����\n12 - ������� ��� ������ ������� ��������� ����\n13 - ������� ����, � ������� ���� ������� ������ ����� ����������\n";
        while (true) {
            cout << "������� ����� �������� : \n";
            cin >> op;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }

        switch (op)
        {
        case(1):
            addElemStart(head);
            break;
        case(2):
            addElemEnd(head);
            break;
        case(3):
            cout << "������� ����� �������, ����� �������� ������ ��������:\n";
            cin >> temp;
            addElemAfter(head, temp);
            break;
        case(4):
            deleteAllList(head);
            break;
        case(5):
            deleteFirst(head);
            break;
        case(6):
            cout << "������� ����� ��������, ������� ������ �������\n";
            cin >> temp;
            deleteElem(head, temp);
            break;
        case(7):
            deleteLastElem(head);
            break;
        case(8):
            cout << "������� ������ � ��������, ��� ��������� ������� � ������� �� ������ �������\n ����, �����, ���, ���, ������, ��� �������, ����������\n";
            cin >> tempData;
            tempData.PrintDate();

            deleteAllIn(head, tempData);
            break;
        case(9):
            printList(head);
            break;
        case(10):
            sortIlness(head);
            mostIlness(head);
            break;
        case(11):
            sortRestDays(head);
            mostRestDays(head);
            break;
        case(12):
            sortDate(head, 1);
            cout << "������� ����:\n";
            cin >> tempo.day >> tempo.month >> tempo.year;
            delAfterDate(head, tempo);
            break;
        case(13):
            sortDate(head, 2);
            mostIlnessDate(head);
            break;
        default:
            cout << "�������� ����\n";
            break;
        }

        cout << "\n����� ���������� ������� y/Y ,����� n/N\n";
        cin >> continueOp;
        system("cls");
    }

}