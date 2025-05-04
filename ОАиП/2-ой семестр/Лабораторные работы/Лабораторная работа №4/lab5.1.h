#pragma once

// Структура для работы
struct Job {
    char name[30];
    float cost;
    float revenue;
    float profit;
};

// Узел стека
struct Node {
    Job job;
    Node* next;
};

// Реализация стека на базе связного списка
struct Stack {
    Node* top;
};

// Функции для работы со стеком
void initStack(Stack& s);
void push(Stack& s, const Job& job);
bool pop(Stack& s, Job& job);
void freeStack(Stack& s);
bool isEmptyStack(const Stack& s);
int stackSize(const Stack& s);

// Прототипы остальных функций (не меняются)
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
