#pragma once

struct List {           // ������
    int number;         // �������� ��������
    List* next;         // ��������� �� ��������� ����
};


// ��������� �������
int inputInteger();                               //����/�������� �����
int mainMenu();                                   // ������� ����
void insert(List** start, int value);               // ������� ��������
void deleteAllOccurrences(List** start, int value); // �������� ���� ���������
void deleteDuplicates(List** start);                // �������� ����������
int countList(List* s);                         // ������� ���������
int findMin(List* s);                           // ����� ������������ ��������
int findMax(List* s);                           // ����� ������������� ��������
void printList(List* current);                  // ������ ������
bool isEmpty(List* s);                          // �������� �� �������
void instructions();                              // ����� �������