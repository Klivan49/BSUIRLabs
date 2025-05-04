#pragma once

// ��������� ��� ������
struct Job {
    char name[30];
    float cost;
    float revenue;
    float profit;
};

// ���� �����
struct Node {
    Job job;
    Node* next;
};

// ���������� ����� �� ���� �������� ������
struct Stack {
    Node* top;
};

// ������� ��� ������ �� ������
void initStack(Stack& s);
void push(Stack& s, const Job& job);
bool pop(Stack& s, Job& job);
void freeStack(Stack& s);
bool isEmptyStack(const Stack& s);
int stackSize(const Stack& s);

// ��������� ��������� ������� (�� ��������)
extern void text();
extern int inputStruct();
extern int sorting();
extern int finder();
extern int remaking();
extern int deleting();
extern int outputStruct(int mode, int num);
extern void deleteFile();
extern int mainMenu();
extern int inputInteger();
extern int qSize();
