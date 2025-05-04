#define _CRT_SECURE_NO_WARNINGS
#include "lab6.h"
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>

int inputInteger()
{
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nНеверный ввод. Пожалуйста, введите целое число: ";
        }
    }
}

float inputDigit() {
    float value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Пожалуйста, введите число: ";
        }
    }
}

tree* treeInstantinate(int data)
{
    tree* newTree = (tree*)malloc(sizeof(tree));
    newTree->data = data; //Значение value передается в поле data нового 
    //узла
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;

}


tree* treeNewElement(struct tree* root, int data) {
    if (root == NULL)
    { //если дерево пустое, создаем новый узел и делаем его корнем дерева
        return treeInstantinate(data);
    }
    else
    { //рекурсивно вставляем новый узел в левое или правое поддерево
        if (data <= root->data)
        {//вставляем в левое поддерево, если значение меньше или равно 
              //текущему узлу
            root->left = treeNewElement(root->left, data);
        }
        else
        { //вставляем в правое поддерево, если значение больше текущего узла
            root->right = treeNewElement(root->right, data);
        }
        return root;
    }
}


// 1. Подсчёт числа узлов в дереве
int countNodes(tree* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 2. Сбор значений через in-order обход в массив
void storeInorder(tree* root, int* arr, int& idx) {
    if (!root) return;
    storeInorder(root->left, arr, idx);
    arr[idx++] = root->data;
    storeInorder(root->right, arr, idx);
}

// 3. Построение сбалансированного BST из отсортированного массива
tree* buildBalancedTree(int* arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    tree* root = (tree*)malloc(sizeof(tree));
    // Инициализируем вручную, так как конструкция через malloc не вызывает конструктор
    new (&root->data) int(arr[mid]);
    root->left = root->right = nullptr;
    // Рекурсия
    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, end);
    return root;
}

// 4. Функция балансировки дерева (без STL)
tree* balanceTree(tree* root) {
    if (!root) return nullptr;
    int n = countNodes(root);
    int* arr = (int*)malloc(n * sizeof(int));
    int idx = 0;
    storeInorder(root, arr, idx);
    tree* balanced = buildBalancedTree(arr, 0, n - 1);
    free(arr);
    return balanced;
}





void printTree(tree* root, int level) {
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) 
        std::cout << "\t";
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}


tree* findMin(struct tree* root) {
    if (root == NULL) {
        //если дерево пустое, возвращаем NULL
        return NULL;
    }

    if (root->left == NULL) {
        //если левое поддерево пустое, текущий узел является минимальным
        return root;
    }

    //рекурсивно ищем минимальный элемент в левом поддереве
    return findMin(root->left);
}

tree* deleteElement(struct tree* root, int data) 
{
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteElement(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteElement(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct tree* minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = deleteElement(root->right, minRight->data);
        }
    }
    return root;
}

void inOrderTraversal(struct tree* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int findMaxSumPath(tree* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = findMaxSumPath(root->left);

    int rightSum = findMaxSumPath(root->right);

    return root->data + (leftSum > rightSum ? leftSum : rightSum);
}

