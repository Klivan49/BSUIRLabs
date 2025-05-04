#include "lab5.h"
#include <stdlib.h>

// Creates a pointer to the beginning of a new stack
// 
PtrToStack 
stackInstantinate()
{
    PtrToStack newBase = malloc(sizeof(struct stack));
    if (newBase == NULL)
        return NULL;

    newBase->data = NULL;
    newBase->dataSize = 0;
    newBase->prev = NULL;

    return newBase;
}

// Creates a pointer to the new stack element
//
stackElement* 
stackNewElement(void* data, size_t dataSize) 
{
    stackElement* newElem = malloc(sizeof(stackElement));
    if (!newElem) return NULL;

    newElem->data = malloc(dataSize); // Выделяем память под данные
    if (!newElem->data) {
        free(newElem);
        return NULL;
    }

    memcpy(newElem->data, data, dataSize); // Копируем данные
    newElem->dataSize = dataSize;
    newElem->prev = NULL;

    return newElem;
}


// Dealocates the memory of a given stack
//
void 
stackDelete(PtrToStack toDelete) 
{
    while (toDelete != NULL) 
    {
        PtrToStack prev = toDelete->prev;
        free(toDelete->data); // Освобождаем данные
        free(toDelete);       // Освобождаем элемент
        toDelete = prev;
    }
}

// Pushes the new element to the stack
//
void
stackPush(PtrToStack* toPushTo, stackElement* newElement)
{
    newElement->prev = *toPushTo;
    *toPushTo = newElement;
}


// Pops the last element from the stack
//
stackElement 
stackPop(PtrToStack* toPopFrom) 
{
    if ((*toPopFrom)->prev == NULL) 
    {
        stackElement empty = { NULL, 0, NULL };
        return empty;
    }

    stackElement toReturn = **toPopFrom;
    PtrToStack toFree = *toPopFrom;
    *toPopFrom = (*toPopFrom)->prev;

    // Копируем данные перед освобождением
    void* dataCopy = malloc(toReturn.dataSize);
    memcpy(dataCopy, toReturn.data, toReturn.dataSize);
    toReturn.data = dataCopy;

    free(toFree->data); // Освобождаем данные элемента
    free(toFree);       // Освобождаем сам элемент

    return toReturn;
}


//Pushes elements into the stack according to the task
void
enterStacks(PtrToStack* stack1, PtrToStack* stack2, char* arr, int length) 
{
    if (length == 0) return;

    // Первый символ в первый стек
    char firstChar = arr[0];
    stackElement* elem = stackNewElement(&firstChar, sizeof(firstChar));
    stackPush(stack1, elem);

    for (int i = 1; i < length; i++) {
        char current = arr[i];
        if (current == '\0') break;

        // Проверяем верхушку stack1 (если он не пуст)
        if ((*stack1)->prev != NULL) {
            char topChar = *(char*)((*stack1)->data);
            if (topChar == current) {
                stackElement* newElem = stackNewElement(&current, sizeof(current));
                stackPush(stack2, newElem);
                continue;
            }
            // Если не совпадает или stack1 пуст
            stackElement* newElem = stackNewElement(&current, sizeof(char));
            stackPush(stack1, newElem);
        }
        
    }
}

void 
printStacks(PtrToStack stack1, PtrToStack stack2) 
{
    printf("\nПервый стек: ");
    PtrToStack current = stack1;
    // Пропускаем головной элемент (prev == NULL)
    while (current->prev != NULL) {
        printf("%c <- ", *(char*)current->data); // Приводим к char*
        current = current->prev;
    }
    printf("Base");

    printf("\nВторой стек: ");
    current = stack2;
    while (current->prev != NULL) {
        printf("%c <- ", *(char*)current->data);
        current = current->prev;
    }
    printf("Base");
    printf("\n");
    system("pause");
}
