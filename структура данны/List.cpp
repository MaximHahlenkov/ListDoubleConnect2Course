#include "List.h"
#include <iostream>
using namespace std;

std::string IlnessPrint(int Ilness)
{
    std::string arr[10]{ "Гайморит","Гастрит","Геморрой","Гепатит С","Герпес","Апноэ","Боль в спине" ,"Гингивит","Головная боль","Запор" };
    return arr[Ilness - 1];
}

int countElem(Node* head) 
{
    int temp = 0;
    if (head) 
    {
        Node* tempo = head;
        while (tempo != nullptr) 
        {
            temp++;
            tempo = tempo->next;
        }
    }
    return temp;
}

void printList(Node* head) {
    if (!head)
    {
        cout << "Cписок пуст\n";
        return;
    }
    Node* temp = head;
    int it = 1;
    cout << "\nCписок:\n";
    while (temp != nullptr) {
        cout << it << ": " << ' ';
        temp->Data.PrintDate();
        it++;
        cout << "\n";
        temp = temp->next;
    }
}

void addElemEnd(Node*& head) {
    Node* temp = head;
    Node* prev = head;
    Date data{};
    if (head)
    {
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        temp->next = new Node{ data };
        temp->next->prev = prev;
    }
    else
        head = new Node{ data };
}

Node*& indexFind(Node* head, int ind) 
{

    Node* temp = head;
    if (head) 
    {
        int  indx = 1; 
        while (temp != nullptr) 
        {
            if (ind == indx)
                return temp;
            temp = temp->next;
            indx++;
 
        }
    }
    return head;
}

void deleteFirst(Node*& head) {
    if (head) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }
    else
        cout << "Список пуст\n";
}

void deleteElem(Node*& head, int ind)
{
    Node* del = indexFind(head, ind);
    if (ind < 1 || ind > countElem(head))
    {
        cout << "Нет такого элемента\n";
        return;
    }
    if (!isNull(del))
    {
        if (del == head) 
        {
            deleteFirst(head);
        }
        else 
        {
            Node* temp = del;
            if(del->next)
            {
                del->prev->next = del->next;
                del->next->prev = del->prev;
            }
            else 
            {
                del->prev->next = nullptr;
            }
            delete temp;
            temp = nullptr;
        }
    }
    else
        cout << "Список пуст\n";
}

    void addElemStart(Node*& head)
{
    Date data = Date();
    Node* first = new Node{ data };
    if (!head)
    {
        head = first;
    }
    else
    {
        first->next = head;
        head->prev = first;
        head = first;
    }
}

bool isNull(Node* head) { return head == nullptr; }

void addElemAfter(Node*& head, int ind)
{
    Node* add = indexFind(head, ind);
    if (ind < 1 || ind > countElem(head))
    {
        cout << "Нет такого элемента\n";
        return;
    }
    if (!isNull(add))
    {
        Date data{};
        Node* temp = new Node{ data };
        
        if(add->next){
            temp->next = add->next;
            temp->prev = add;

            add->next->prev = temp;
            add->next = temp;
        }
        else 
        {
            add->next = temp;
            temp->prev = add;
        }

    }
    else
        cout << "Список пуст\n";
}

void deleteAllList(Node*& head)
{

    if (!isNull(head))
    {
        while (!isNull(head))
        {
            deleteFirst(head);
        }
        cout << "Cписок удален\n";
    }
    else
        cout << "Список пуст\n";
}

void deleteLastElem(Node*& head)
{
    if (!isNull(head))
    {
        Node* temp = head;
        if (temp->next == nullptr) 
        {
            deleteFirst(head);
            return;
        }
        while (temp != nullptr)
        {
            if (temp->next == nullptr) 
            {
                Node* del = temp;
                temp->prev->next = nullptr;
                delete del;
                del = nullptr;
                return;
            }
            temp = temp->next;
        }

    }
    else
        cout << "Cписок пуст\n";
}

void deleteAllIn(Node*& head, Date data)
{
    if(!isNull(head)){
        Node* temp = head;

        while (temp != nullptr)
        {
            if (temp->Data == data)
            {
                Node* del = temp;       
                if (temp->prev)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }

                if (temp->next)
                    temp->next->prev = temp->prev;
                
                temp = temp->next;

                delete del;
                del = nullptr;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    else 
        cout << "Cписок пуст\n";
}


Node::Node()
{
    Data = Date();
    next = nullptr;
    prev = nullptr;
}

Node::Node(Date _Data)
{
    Data = _Data;
    next = nullptr;
    prev = nullptr;
}

void sortIlness(Node* head)
{
    if (head)
    {
        bool swp;
        Node* temp = head;
        Node* last = nullptr;
        do
        {
            swp = false;
            temp = head;
            while (temp->next != last)
            {
                if (temp->Data.Ilness > temp->next->Data.Ilness)
                {
                    swap(temp->Data, temp->next->Data);
                    swp = true;
                }
                temp = temp->next;
            }
            last = temp;
        } while (swp);
    }
    else
        cout << "Список пуст!\n";
}

void mostIlness(Node* head)
{
    if (!head)
    {
        cout << "Список пуст!\n";
        return;
    }

    Node* temp = head;
    int most_common = temp->Data.Ilness; 
    int max_count = 1; 
    int current_count = 1; 

    while (temp->next != nullptr)
    {
        if (temp->Data.Ilness == temp->next->Data.Ilness)
        {
            current_count++;
        }
        else
        {
            if (current_count > max_count)
            {
                max_count = current_count;
                most_common = temp->Data.Ilness; 
            }
            current_count = 1; 
        }
        temp = temp->next;
    }

    
    if (current_count > max_count)
    {
        max_count = current_count;
        most_common = temp->Data.Ilness; 
    }

    cout << "Диагноз, который встречался чаще всего: " << IlnessPrint( most_common ) << ". Он встречался: " << max_count;
    max_count < 5 ? cout << " раза" : cout << " раз" << endl;
}

void sortRestDays(Node* head)
{
    if (head)
    {
        bool swp;
        Node* temp = head;
        Node* last = nullptr;
        do
        {
            swp = false;
            temp = head;
            while (temp->next != last)
            {
                if (temp->Data.Rest_days < temp->next->Data.Rest_days)
                {
                    swap(temp->Data, temp->next->Data);
                    swp = true;
                }
                temp = temp->next;
            }
            last = temp;
        } while (swp);
    }
    else
        cout << "Список пуст!\n";
}

void mostRestDays(Node* head) 
{
    if (!head)
    {
        cout << "Список пуст!\n";
        return;
    }

    Node* temp = head;
    cout << "Профессии: \n";
    while (temp) 
    {
        if (temp->Data.Rest_days == head->Data.Rest_days)
            cout << temp->Data.Work << " : " << temp->Data.FIO <<"\n";
        temp = temp->next;
    }
    
}

bool isLater(Date date1, Date date2) 
{
    if (date1.year > date2.year) return true;
    if (date1.year < date2.year) return false;

    if (date1.month > date2.month) return true;
    if (date1.month < date2.month) return false;

    if (date1.day > date2.day) return true;
    return false;

}

void sortDate(Node* head, int a) 
{
    if (head)
    {
        bool swp;
        Node* temp = head;
        Node* last = nullptr;
        do
        {
            swp = false;
            temp = head;
            while (temp->next != last)
            {
                if(a == 1)
                {
                    if (!isLater(temp->Data, temp->next->Data))
                    {
                        swap(temp->Data, temp->next->Data);
                        swp = true;
                    }
                }
                else
                {
                    if (isLater(temp->Data, temp->next->Data))
                    {
                        swap(temp->Data, temp->next->Data);
                        swp = true;
                    }
                }
                temp = temp->next;
            }
            last = temp;
        } while (swp);
    }
    else
        cout << "Список пуст!\n";
}

void deleteElem(Node*& elem)
{
    if (elem == nullptr) {
        std::cout << "Список пуст или элемент не существует\n";
        return;
    }

    if (elem->prev == nullptr) {
        deleteFirst(elem);  
    }
    else {
        Node* temp = elem;
        if (elem->next) {
            elem->prev->next = elem->next;  
            elem->next->prev = elem->prev;  
        }
        else {
            elem->prev->next = nullptr;  
        }
        delete temp;
        elem = nullptr;  
    }
}



void delAfterDate(Node*& head, Date data)
{
    if (!isNull(head))
    {
        if(!isLater(head->Data, data))
        {
            cout << "Все больничные открыты раньше\n";
        }
        else
        {
            while (head != nullptr && isLater(head->Data, data))
            {
                deleteFirst(head);
            }
        }
    }
    else
        cout << "Список пуст!\n";
}

bool IsDataEq(Date data1, Date data2) 
{
    if (data1.day != data2.day)
        return false;
    if (data1.month != data2.month)
        return false;
    if (data1.year != data2.year)
        return false;
    return true;
}

void mostIlnessDate(Node* head) 
{
    if (!isNull(head))
    {
        Node* temp = head;
        Date data = head->Data;
        
        int max = 1;
        int cur = 1;

        while (temp->next != nullptr) 
        {
            if (IsDataEq(temp->Data, temp->next->Data)) 
            {
                cur++;
            }
            else 
            {
                if (cur >= max)
                {
                    max = cur;
                    cur = 1;
                    data = temp->next->Data;
                }
                else 
                {
                    cur = 1;
                }
            }
            temp = temp->next;
        }
        cout << "Дата, в которую было открыто наибольшее кол-во больничных: " << data.day << '.' << data.month << '.' << data.year << " ,кол-во больничных: " << max << "\n";
        
    }
    else
        cout << "Список пуст!\n";
}