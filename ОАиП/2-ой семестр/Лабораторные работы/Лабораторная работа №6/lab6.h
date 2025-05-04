#pragma once
#include <string>

struct tree {
	int data;
	struct tree* left;
	struct tree* right;
};

int inputInteger();

float inputDigit();

tree* treeInstantinate(int data);

tree* treeNewElement(tree* root, int data);

tree* findMin(struct tree* root);

void printTree(tree* root, int level);

tree* balanceTree(tree* root);

int findMaxSumPath(tree* root);

void inOrderTraversal(struct tree* root);

tree* deleteElement(struct tree* root, int data);
