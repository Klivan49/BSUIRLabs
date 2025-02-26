#include "lab2.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <cstring>
#include <stdexcept>
#include <chrono>

std::vector<int> array;

extern int inputInteger() 
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

extern float inputDigit() {
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

void printArray(const std::vector<int>& arr) 
{
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

extern void inputArray()
{
    int n;
    std::cout << "Вы хотите сами задать массив или через рандом?(1/2)\n3 -- случайно нажал(a):\n";
    n = inputInteger();
    switch(n)
    {
    case 1:
    {
        std::string input;
        std::cout << "Введите элементы массива через пробел (Enter -- конец массива)" << std::endl;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        int value;

        while (iss >> value) {
            array.push_back(value);
        }

        if (iss.fail() && !iss.eof()) {
            std::cerr << "Ошибка ввода: некорректное значение в массиве" << std::endl;
        }
        std::cout << "Хотите вывести массив?(y/n)" << std::endl;
        char ch = getchar();
        if (ch == 'y' || ch == 'Y')
        {
            std::cout << "Получившийся массив:\n";
            printArray(array);
        }
        else if (ch == 'n' || ch == 'N')
        {
        }
        else std::cout << "Вы ввели что-то не то :3";
        break;
    }
    case 2:
    {
        std::cout << "Введите количество элементов массива: ";
        int n = inputInteger();
        std::cout << "Введите нижню границу случайного числа: ";
        int start = inputInteger();
        std::cout << "Введите верхнюю границу случайного числа: ";
        int end = inputInteger();
        for (int i = 0; i < n; i++)
        {
            int value = rand() % (end - start + 1) + start;
            array.push_back(value);
        }
        std::cout << "Хотите вывести массив?(y/n)" << std::endl;
        char ch = getchar();
        if (ch == 'y' || ch == 'Y')
        {
            std::cout << "Получившийся массив:\n";
            printArray(array);
        }
        else if (ch == 'n' || ch == 'N')
        {
        }
        else std::cout << "Вы ввели что-то не то :3";
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
        std::cout << "Вы ввели что-то не то...";
        break;
    }
    }
}

extern void bubbleSort(std::vector<int>& arr) 
{
    std::vector<int> sorted = arr;
    auto start = std::chrono::high_resolution_clock::now();
    int n = sorted.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                std::swap(sorted[j], sorted[j + 1]);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время пузырьковой сортировки:\n" << duration.count() * 1000000 
        << " наносекунд\n" << duration.count() * 1000 
        << " милисекунд\n" << duration.count() 
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}

extern void selectionSort(std::vector<int>& arr) 
{
    std::vector<int> sorted = arr;
    auto start = std::chrono::high_resolution_clock::now();
    int n = sorted.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (sorted[j] < sorted[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(sorted[i], sorted[min_idx]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки выборки:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " милисекунд\n" << duration.count()
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}

extern void insertionSort(std::vector<int>& arr) 
{
    std::vector<int> sorted = arr;
    auto start = std::chrono::high_resolution_clock::now();
    int n = sorted.size();
    for (int i = 1; i < n; i++) {
        int key = sorted[i];
        int j = i - 1;
        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки вставкой:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " милисекунд\n" << duration.count()
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}

extern void shellSort(std::vector<int>& arr) 
{
    std::vector<int> sorted = arr;
    auto start = std::chrono::high_resolution_clock::now();
    int n = sorted.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = sorted[i];
            int j;
            for (j = i; j >= gap && sorted[j - gap] > temp; j -= gap) {
                sorted[j] = sorted[j - gap];
            }
            sorted[j] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки методом Шелла:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " милисекунд\n" << duration.count()
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

extern void quickSortWrapper(std::vector<int>& arr) {
    std::vector<int> sorted = arr;
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(sorted, 0, sorted.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки методом Хоора:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " милисекунд\n" << duration.count()
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) 
{
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

extern void mergeSortWrapper(std::vector<int>& arr) 
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted = arr;
    mergeSort(sorted, 0, sorted.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки методом слияния:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " милисекунд\n" << duration.count()
        << " секунд" << std::endl;
    std::cout << "Хотите вывести массивы?(y/n)" << std::endl;
    char ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\nИсходный массив: ";
        printArray(array);
        std::cout << "\n\n\n\nОтсортированный массив: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N')
    {
    }
    else std::cout << "Вы ввели что-то не то :3";
}
