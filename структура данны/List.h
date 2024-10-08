#pragma once
#include <string>
#include <iostream>
#include "Data.h"


struct Node {

    Date Data;
    Node* next;
    Node* prev;
    Node();
    Node(Date _Data);

};


void addElemEnd(Node*& head);

void printList(Node* List);

void deleteFirst(Node*& List);

Node*& indexFind(Node* head, int ind);

void deleteElem(Node*& head, int elem);

void deleteElem(Node*& elem);

void addElemStart(Node*& head);

int countElem(Node* head);

bool isNull(Node* head);

void addElemAfter(Node*& head, int ind);

void deleteAllList(Node*& head);

void deleteLastElem(Node*& head);

void deleteAllIn(Node*& head, Date data);

void sortIlness(Node* head);

void mostIlness(Node* head);

void sortRestDays(Node* head);

void mostRestDays(Node* head);

bool isLater(Date data1, Date data2);

void sortDate(Node* head, int a);

void mostIlnessDate(Node* head);

void delAfterDate(Node*& head, Date data);

std::string IlnessPrint(int Ilness);

bool IsDataEq(Date data1, Date data2);
