#pragma once
#include <stdlib.h>

struct stack;                           // Stack structrue.
typedef struct stack* PtrToStack;       // A pointer to the stack (used as the head of the stack).
typedef struct stack stackElement;      // An element of a stack.

struct stack
{
    void* data;                         // Pointer to the data of current element.
    size_t dataSize;                    // Size of the memory chunk data pointer refers to.
    PtrToStack prev;                    // Pointer to the previous stack element.
};


/*
 * Creates new default stack head element.
 *
 * @return              Returns a pointer to the new stack head.
 * @return              May return NULL if fails.
 */
PtrToStack           stackInstantinate(void);


/*
 * Creates a pointer to the new stack element.
 *
 * @param data          Pointer to the data buffer, that stack element will contain.
 * @param dataSize      Size of the data buffer.
 * @return              Returns pointer to the new stack element. May return NULL if fails.
 */
stackElement* stackNewElement(void* data,
    size_t dataSize);

/*
 * Dealocates the memory of a given stack.
 *
 * @param toDelete      Pointer to the stack struct you want to delete.
 */
void            stackDelete(PtrToStack toDelete);


/*
 * Pushes the new element to the stack.
 *
 * @param toPushTo      Pointer to the head pointer of the stack.
 * @param newElement    New element that will be pushed to the stack.
 */
void            stackPush(PtrToStack* toPushTo,
    stackElement* newElement);

/*
 * Pops the last element from the stack.
 *
 * @param toPopFrom     Pointer to the head pointer of the stack.
 * @return              Returns the last element pushed into the stack
 */
stackElement    stackPop(PtrToStack* toPopFrom);


/*
 * Puts elements from the line into the stacks accordind to the task.
 *
 * @param stack1     Pointer to pointer to the 1st stack.
 * @param stack2     Pointer to pointer to the 2nd stack.
 * @param arr        Pointer to the array.
 * @param length     Length of the array.
 */
void enterStacks(PtrToStack* stack, char* arr, int length);

/*
 * Prints elements from the both stacks.
 *
 * @param stack1     Pointer to the 1st stack.
 * @param stack2     Pointer to the 2nd stack.
 */
void printStacks(PtrToStack stack);