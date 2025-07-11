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


int countNodes(tree* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void storeInorder(tree* root, int* arr, int& idx) {
    if (!root) return;
    storeInorder(root->left, arr, idx);
    arr[idx++] = root->data;
    storeInorder(root->right, arr, idx);
}

tree* buildBalancedTree(int* arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    tree* root = (tree*)malloc(sizeof(tree));
    new (&root->data) int(arr[mid]);
    root->left = root->right = nullptr;
    // Рекурсия
    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, end);
    return root;
}

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




void printTree(const tree* root, const std::string& prefix, bool isLeft, bool isRoot)
{
    if (!root) return;

    std::string rightPrefix = prefix + (isRoot ? "" : (isLeft ? "│   " : "    "));
    printTree(root->right, rightPrefix, false, false);

    if (isRoot) {
        std::cout << root->data << "\n";
    }
    else {
        std::cout << prefix << (isLeft ? "└── " : "┌── ") << root->data << "\n";
    }

    std::string leftPrefix = prefix + (isRoot ? "" : (isLeft ? "    " : "│   "));
    printTree(root->left, leftPrefix, true, false);
}





tree* findMin(struct tree* root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL) {
        return root;
    }

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

void inOrderTraversal(tree* root) {
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


int findSecondMinimum(tree* root) {
    if (!root) return -1;

    int n = countNodes(root);
    if (n < 2) return -1;


    int* arr = (int*)malloc(n * sizeof(int));
    int idx = 0;
    storeInorder(root, arr, idx);

    int first = arr[0];


    int second = -1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > first) {
            second = arr[i];
            break;
        }

    }

    free(arr);
    return second;
}

void extraLeaves(tree* root)
{
    if (!root) return;              

    if (root->left == nullptr && root->right == nullptr) 
    {
        root->data += 1; 
    }
    else {
        root->data -= 1; 
        extraLeaves(root->left);
        extraLeaves(root->right);
    }
}
