#pragma once
#ifndef LIST_H
#define LIST_H

struct ListNode {
    int number;         // �������� ���� (����� �����)
    ListNode* next;     // ��������� �� ��������� ����
};

typedef ListNode* ListNodePtr;

// ��������� �������
int mainMenu();                                     // ������� ����
void insert(ListNodePtr* s, int value);             // ������� ��������
void deleteAllOccurrences(ListNodePtr* s, int value); // �������� ���� ���������
void deleteDuplicates(ListNodePtr* s);              // �������� ����������
int countList(ListNodePtr s);                       // ������� ���������
int findMin(ListNodePtr s);                         // ����� ������������ ��������
int findMax(ListNodePtr s);                         // ����� ������������� ��������
void printList(ListNodePtr current);                // ������ ������
bool isEmpty(ListNodePtr s);                        // �������� �� �������
void instructions();                                // ����� �������
#endif