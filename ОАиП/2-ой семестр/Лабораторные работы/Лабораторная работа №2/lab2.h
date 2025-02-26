#pragma once
#include <vector>

extern std::vector<int> array;
extern int mainMenu();
extern int inputInteger();
extern float inputDigit();
extern void inputArray();
extern void mergeSortWrapper(std::vector<int>& arr);
extern void shellSort(std::vector<int>& arr);
extern void quickSortWrapper(std::vector<int>& arr);
extern void insertionSort(std::vector<int>& arr);
extern void selectionSort(std::vector<int>& arr);
extern void bubbleSort(std::vector<int>& arr);