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

    stackElement ret = **toPopFrom;
    PtrToStack toFree = *toPopFrom;
    *toPopFrom = (*toPopFrom)->prev;

    // Копируем данные перед освобождением
    void* dataCopy = malloc(ret.dataSize);
    memcpy(dataCopy, ret.data, ret.dataSize);
    ret.data = dataCopy;

    free(toFree->data); // Освобождаем данные элемента
    free(toFree);       // Освобождаем сам элемент

    return ret;
}


//Pushes elements into the stack according to the task
void
enterStacks(PtrToStack* stack, char* arr, int length)
{
    if (length == 0) return;

  /*  // Первый символ в первый стек
    char firstChar = arr[0];
    stackElement* elem = stackNewElement(&firstChar, sizeof(char));
    stackPush(stack1, elem); */

    for (int i = 0; i < length; i++) {
        char current = arr[i];
        if (current == '\0') break;
        stackElement* newElem = stackNewElement(&current, sizeof(char));
        stackPush(stack, newElem);
    }
}

void
polishResult(PtrToStack stack)
{
    printf("\nПервый стек: ");
    PtrToStack current = stack;
    // Пропускаем головной элемент (prev == NULL)
    while (current->prev != NULL) {
        printf("%c <- ", *(char*)current->data); // Приводим к char*
        current = current->prev;
    }
    printf("Base\n");
}

void
printStacks(PtrToStack stack)
{
    printf("\nПервый стек: ");
    PtrToStack current = stack;
    // Пропускаем головной элемент (prev == NULL)
    while (current->prev != NULL) {
        printf("%c <- ", *(char*)current->data); // Приводим к char*
        current = current->prev;
    }
    printf("Base\n");
}
