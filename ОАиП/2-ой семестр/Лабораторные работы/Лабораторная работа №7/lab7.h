#pragma once
#include <vector>

struct Product 
{
    std::string name;
    float price;
    int release_day;
};

int searchKey(const std::vector<int>& table, int key);

void insertKey(std::vector<int>& table, int key);

int hashFunc(int key, int M);

float inputDigit();

int inputInteger();

void printHashTable(std::vector<int> table, int M);

void printArrayBase(std::vector<int> arr);

std::vector<int> tableInstantinate(int M, std::vector<int> arr);

void inputStructs(int n, int M, std::vector<Product>& products, std::vector<Product*>& hashTable);

void printBaseStruct(const std::vector<Product>& products);

void printHashStruct(int M, const std::vector<Product*>& hashTable);