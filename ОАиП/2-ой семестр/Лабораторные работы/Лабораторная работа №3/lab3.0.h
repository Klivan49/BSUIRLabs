#pragma once

struct List {           // ������
    int number;         // �������� ��������
    List* next;         // ��������� �� ��������� ����
};

typedef List* ListPtr;

// ��������� �������
int inputInteger();                               //����/�������� �����
int mainMenu();                                   // ������� ����
void insert(ListPtr* s, int value);               // ������� ��������
void deleteAllOccurrences(ListPtr* s, int value); // �������� ���� ���������
void deleteDuplicates(ListPtr* s);                // �������� ����������
int countList(ListPtr s);                         // ������� ���������
int findMin(ListPtr s);                           // ����� ������������ ��������
int findMax(ListPtr s);                           // ����� ������������� ��������
void printList(ListPtr current);                  // ������ ������
bool isEmpty(ListPtr s);                          // �������� �� �������
void instructions();                              // ����� �������