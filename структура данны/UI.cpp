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
        cout << "1 - Добавление в начало\n2 - Добавление в конец\n3 - Добавление после определенного элемента\n4 - Удаление всего списка\n5 - удаление головы\n6 - Удаление после заданного\n7 - Удаление последнего элемента\n8 - удаление всех вхождений\n9 - Вывод на экран\n10 - Вывести диагноз, который встречается чаще всего\n11 - Вывести людей, которые болели дольше всего\n12 - Удалить все записи позднее указанной даты\n13 - Вывести дату, в которую было открыто больше всего больничных\n";
        while (true) {
            cout << "Введите номер операции : \n";
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
            cout << "Введите номер элемент, после которого хотите добавить:\n";
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
            cout << "Введите номер элемента, который хотите удалить\n";
            cin >> temp;
            deleteElem(head, temp);
            break;
        case(7):
            deleteLastElem(head);
            break;
        case(8):
            cout << "Введите данные о человеке, все вхождения записей о котором вы хотите удалить\n День, месяц, год, ФИО, Работа, Код болезни, Больничный\n";
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
            cout << "Введите дату:\n";
            cin >> tempo.day >> tempo.month >> tempo.year;
            delAfterDate(head, tempo);
            break;
        case(13):
            sortDate(head, 2);
            mostIlnessDate(head);
            break;
        default:
            cout << "Неверный ввод\n";
            break;
        }

        cout << "\nЧтобы продолжить введите y/Y ,иначе n/N\n";
        cin >> continueOp;
        system("cls");
    }

}