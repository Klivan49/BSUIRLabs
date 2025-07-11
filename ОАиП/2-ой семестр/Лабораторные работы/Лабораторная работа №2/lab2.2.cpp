#include "lab2.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <cstring>
#include <stdexcept>
#include <chrono>
#include <conio.h>

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
            std::cout << "\n�������� ����. ����������, ������� ����� �����: ";
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
            std::cout << "�������� ����. ����������, ������� �����: ";
        }
    }
}

std::vector<int> linearSearch(const std::vector<int>& arr, int target) {
    std::vector<int> positions;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            positions.push_back(i);
        }
    }
    return positions; // ���� ������ ����, ������� �� ������
}

int binarySearch(const std::vector<int>& arr, int target, int left, int right) 
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            // ����� �������, ���������, ������ �� ��� �������
            while (mid > 0 && arr[mid - 1] == target) {
                mid--;
            }
            return mid;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1; // ������� �� ������
}

void finder(const std::vector<int>& arr, const std::vector<int>& sorted) {
    if (arr.empty()) {
        std::cout << "������ ����. ����������, ������� ������ �������." << std::endl;
        return;
    }
    std::cout << "������� �������� ��������, ������� �������� ������ ����� � �������: ";
    int target = inputInteger();

    // �������� �����
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> linearPositions = linearSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    if (!linearPositions.empty()) {
        std::cout << "�������� �����: ������� ������ �� ��������: ";
        for (int pos : linearPositions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "�������� �����: ������� �� ������" << std::endl;
    }
    std::cout << "����� ��������� ������:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������\n" << std::endl;

    // �������� �����
    start = std::chrono::high_resolution_clock::now();
    int binaryPosition = binarySearch(sorted, target, 0, sorted.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    if (binaryPosition != -1) {
        std::cout << "�������� �����: ������� ������ �� ������� " << binaryPosition
            << " � ��������������� �������" << std::endl;
    }
    else {
        std::cout << "�������� �����: ������� �� ������ � ��������������� �������" << std::endl;
    }
    std::cout << "����� ��������� ������:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
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
    char n;
    std::cout << "�� ������ ���� ������ ������ ��� ����� ������?(1/2)\n3 -- �������� �����(a):\n";
    n = _getch();
    switch(n)
    {
    case '1':
    {
        std::string input;
        std::cout << "������� �������� ������� ����� ������ (Enter -- ����� �������)" << std::endl;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        int value;

        while (iss >> value) {
            array.push_back(value);
        }

        if (iss.fail() && !iss.eof()) {
            std::cerr << "������ �����: ������������ �������� � �������" << std::endl;
        }
        std::cout << "������ ������� ������?(y/n)" << std::endl;
        char ch = _getch();
        if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        {
            std::cout << "������������ ������:\n";
            printArray(array);
        }
        else if (ch == 'n' || ch == 'N' || ch == '�' || ch == '�')
        {
        }
        else std::cout << "�� ����� ���-�� �� �� :3";
        break;
    }
    case '2':
    {
        std::cout << "������� ���������� ��������� �������: ";
        int n = inputInteger();
        if (n > 100000)
        {
            std::cout << "������� ����� ���������";
            return;
        }
        std::cout << "������� ����� ������� ���������� �����: ";
        int start = inputInteger();
        std::cout << "������� ������� ������� ���������� �����: ";
        int end = inputInteger();
        for (int i = 0; i < n; i++)
        {
            int value = rand() % (end - start + 1) + start;
            array.push_back(value);
        }
        std::cout << "������ ������� ������?(y/n)" << std::endl;
        char ch = _getch();
        if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        {
            std::cout << "������������ ������:\n";
            printArray(array);
        }
        else if (ch == 'n' || ch == 'N')
        {
        }
        else std::cout << "�� ����� ���-�� �� �� :3";
        break;
    }
    case '3':
    {
        break;
    }
    default:
    {
        std::cout << "�� ����� ���-�� �� ��...";
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
    std::cout << "����� ����������� ����������:\n" << duration.count() * 1000000 
        << " ����������\n" << duration.count() * 1000 
        << " ����������\n" << duration.count() 
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N' || ch == '�' || ch == '�')
    {
        std::cout << "�� ����� ���-�� �� �� :3";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        finder(arr, sorted);
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
    std::cout << "����� ���������� �������:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
    }
    else if (ch == 'n' || ch == 'N' || ch == '�' || ch == '�')
    {
        std::cout << "�� ����� ���-�� �� �� :3";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        finder(arr, sorted);
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
    std::cout << "����� ���������� ��������:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (ch == 'n' || ch == 'N' || ch == '�' || ch == '�')
    {
        std::cout << "�� ����� ���-�� �� �� :3";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        finder(arr, sorted);
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
    std::cout << "����� ���������� ������� �����:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
    }
    else if (ch != 'n' && ch != 'N')
    {
        std::cout << "����";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        finder(arr, sorted);
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
    std::cout << "����� ���������� ������� �����:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
    }
    else if (ch != 'n' && ch != 'N')
    {
        std::cout << "�� ����� ���-�� �� �� :3";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y' || ch == '�' || ch == '�')
        finder(arr, sorted);
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
    std::cout << "����� ���������� ������� �������:\n" << duration.count() * 1000000
        << " ����������\n" << duration.count() * 1000
        << " ����������\n" << duration.count()
        << " ������" << std::endl;
    std::cout << "������ ������� �������?(y/n)" << std::endl;
    char ch = _getch();
    if (ch == 'y' || ch == 'Y')
    {
        std::cout << "\n�������� ������: ";
        printArray(array);
        std::cout << "\n\n\n\n��������������� ������: ";
        printArray(sorted);
    }
    else if (ch != 'n' && ch != 'N')
    {
        std::cout << "�� ����� ���-�� �� �� :3";
    }
    std::cout << "������ �������� �����?(y/n)" << std::endl;
    ch = _getch();
    if (ch == 'y' || ch == 'Y')
        finder(arr, sorted);
}
