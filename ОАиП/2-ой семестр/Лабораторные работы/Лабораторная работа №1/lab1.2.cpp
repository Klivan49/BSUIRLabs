#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <chrono>
#include "lab1.h"
#include <functional>

struct Job 
{
    char name[30]; 
    float cost;      
    float revenue;   
    float profit;    
};

extern int inputInteger() {
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Пожалуйста, введите целое число: ";
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

void selectionSort(std::vector<Job>& arr, std::function<bool(const Job&, const Job&)> comp) {
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (comp(arr[j], arr[min_idx])) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки выбором:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " миллисекунд\n" << duration.count()
        << " секунд" << std::endl;
}

void insertionSort(std::vector<Job>& arr, std::function<bool(const Job&, const Job&)> comp) {
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Job key = arr[i];
        int j = i - 1;
        while (j >= 0 && comp(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки вставками:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " миллисекунд\n" << duration.count()
        << " секунд" << std::endl;
}

void shellSort(std::vector<Job>& arr, std::function<bool(const Job&, const Job&)> comp) {
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && comp(temp, arr[j - gap]); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки методом Шелла:\n" << duration.count() * 1000000
        << " наносекунд\n" << duration.count() * 1000
        << " миллисекунд\n" << duration.count()
        << " секунд" << std::endl;
}

extern int inputStruct() {
    int numberOfJobs = 0, newJobs = 0;
    std::ifstream inFile("numberOfJobs.txt");
    if (inFile) {
        inFile >> numberOfJobs;
        inFile.close();
    }
    std::cout << "Сколько новых работ вы хотите добавить? ";
    newJobs = inputInteger();
    if (newJobs < 0) {
        std::cerr << "Вы ввели что-то не то...\nPress any key to continue...\n";
        system("pause");
        return 0;
    }
    std::ofstream outFile("jobs.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи работ(\n";
        return 0;
    }
    Job job;
    for (int i = numberOfJobs; i < numberOfJobs + newJobs; ++i) {
        std::cout << "Введите название работы №" << (i + 1) << ": ";
        std::cin.getline(job.name, 30);
        std::cout << "Введите стоимость работы: ";
        job.cost = inputDigit();
        std::cout << "Введите доход от работы: ";
        job.revenue = inputDigit();
        job.profit = job.revenue - job.cost;
        if (job.cost < 0 || job.revenue < 0) {
            std::cerr << "Вы ввели что-то не то...\nPress any key to continue...\n";
            outFile.close();
            system("pause");
            return 1;
        }
        outFile << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFile.close();
    numberOfJobs += newJobs;
    std::ofstream updateCount("numberOfJobs.txt");
    if (!updateCount) {
        std::cerr << "Ошибка обновления числа работ(\n";
        return 0;
    }
    updateCount << numberOfJobs;
    updateCount.close();
    std::cout << "Список работ успешно обновлен! Теперь у вас " << numberOfJobs << " работ.\n";
    return 1;
}

extern int outputStruct(int n, int num) {
    int numberOfJobs = 0;
    std::ifstream readJobCount("numberOfJobs.txt");
    if (readJobCount) {
        readJobCount >> numberOfJobs;
        readJobCount.close();
    }
    else {
        std::cerr << "Ошибка открытия файла numberOfJobs.txt для чтения\n";
        return 0;
    }
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "Ошибка открытия файла jobs.txt для чтения\n";
        return 0;
    }
    if (n == 0) {
        text();
        Job job;
        std::string line;
        for (int i = 0; i < numberOfJobs; i++) {
            if (!std::getline(inFileJob, line)) {
                std::cerr << "Ошибка чтения работы " << i << " из файла\n";
                break;
            }

            std::istringstream iss(line);
            if (!(iss.getline(job.name, 30, ' ') >> job.cost >> job.revenue >> job.profit)) {
                std::cerr << "Ошибка разбора данных работы " << i << " из файла\n";
                break;
            }
            std::cout << std::left << std::setw(20) << job.name
                << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
        }
    }
    else if (n == 1) {
        Job job;
        std::string line;
        for (int i = 0; i < num; ++i) {
            if (!std::getline(inFileJob, line)) {
                std::cerr << "Ошибка при поиске фильма по индексу\n";
                inFileJob.close();
                return 0;
            }
        }
        if (!inFileJob.getline(job.name, 30, ' ') ||
            !(inFileJob >> job.cost) ||
            !(inFileJob >> job.revenue) ||
            !(inFileJob >> job.profit)) {
            std::cerr << "Ошибка чтения фильма по индексу " << num << " из файла\n";
            inFileJob.close();
            return 0;
        }
        std::cout << std::left << std::setw(20) << job.name
            << std::setw(15) << job.cost
            << std::setw(20) << std::fixed << std::setprecision(2) << job.revenue
            << std::setw(20) << job.profit << std::endl;
    }

    inFileJob.close();
    return 1;
}

extern int sorting() {
    std::cout << "Как именно вы хотите отсортировать работы?\n"
        << "1 -- В алфавитном порядке по названию\n"
        << "2 -- По стоимости\n"
        << "3 -- По доходу\n"
        << "4 -- По прибыли\n"
        << "5 -- Выход\n";

    int n = inputInteger();
    if (n < 1 || n > 5) {
        std::cout << "Вы ввели что-то не то...\n";
        return 0;
    }
    if (n == 5) return 0;

    std::cout << "Выберите тип сортировки:\n"
        << "1 -- Сортировка выбором\n"
        << "2 -- Сортировка вставками\n"
        << "3 -- Сортировка Шелла\n"
        << "4 -- Выход\n";

    int sortType = inputInteger();
    if (sortType < 1 || sortType > 4) {
        std::cout << "Вы ввели что-то не то...\n";
        return 0;
    }
    if (sortType == 4) return 0;

    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "Ошибка открытия файла numberOfJobs.txt\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "Ошибка открытия файла jobs.txt\n";
        return 0;
    }
    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    // Определение компаратора на основе критерия
    std::function<bool(const Job&, const Job&)> comp;
    switch (n) {
    case 1: 
        comp = [](const Job& a, const Job& b) { return strcmp(a.name, b.name) < 0; };
        break;
    case 2:
        comp = [](const Job& a, const Job& b) { return a.cost < b.cost; };
        break;
    case 3:
        comp = [](const Job& a, const Job& b) { return a.revenue < b.revenue; };
        break;
    case 4:
        comp = [](const Job& a, const Job& b) { return a.profit < b.profit; };
        break;
    }

    switch (sortType) {
    case 1:
        selectionSort(arrOfJobs, comp);
        break;
    case 2:
        insertionSort(arrOfJobs, comp);
        break;
    case 3:
        shellSort(arrOfJobs, comp);
        break;
    }

    std::ofstream outFileJob("jobs.txt");
    if (!outFileJob) {
        std::cerr << "Ошибка открытия файла jobs.txt для записи\n";
        return 0;
    }
    for (const auto& job : arrOfJobs) {
        outFileJob << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFileJob.close();

    std::cout << "Работы успешно отсортированы!\n";
    return 1;
}

extern void text()
{
    std::cout << std::left << std::setw(20) << "Название работы"
        << std::setw(15) << "Стоимость"
        << std::setw(15) << "Доход"
        << std::setw(15) << "Прибыль" << std::endl;
    std::cout << std::string(65, '=') << std::endl;
}

extern int finder() {
    std::cout << "По какому параметру вы будете проводить поиск?\n"
        << "1 -- По названию работы\n"
        << "2 -- По стоимости работы\n"
        << "3 -- По доходу от работы\n"
        << "4 -- По прибыли\n"
        << "5 -- Выход\n";
    int n = inputInteger();
    if (n < 1 || n > 5) {
        std::cout << "Вы ввели что-то не то...";
        return 0;
    }
    if (n == 5) return 0;
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();
    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 100, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();
    bool found = false;
    switch (n) {
    case 1: {
        char input[30];
        std::cout << "Введите название работы: ";
        std::cin.getline(input, 30);
        text();
        for (int i = 0; i < arrOfJobs.size(); ++i) {
            if (strcmp(arrOfJobs[i].name, input) == 0) {
                std::cout << std::left << std::setw(20) << arrOfJobs[i].name
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].profit << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Нет работ с таким названием(\n";
        break;
    }
    case 2: {
        float cost = inputDigit();
        text();
        for (int i = 0; i < arrOfJobs.size(); ++i) {
            if (arrOfJobs[i].cost <= cost) {
                std::cout << std::left << std::setw(20) << arrOfJobs[i].name
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].profit << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Нет работ с такой или меньшей стоимостью(\n";
        break;
    }
    case 3: {
        float revenue = inputDigit();
        text();
        for (int i = 0; i < arrOfJobs.size(); ++i) {
            if (arrOfJobs[i].revenue >= revenue) {
                std::cout << std::left << std::setw(20) << arrOfJobs[i].name
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].profit << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Нет работ с таким или большим доходом(\n";
        break;
    }
    case 4: {
        float profit = inputDigit();
        text();
        for (int i = 0; i < arrOfJobs.size(); ++i) {
            if (arrOfJobs[i].profit >= profit) {
                std::cout << std::left << std::setw(20) << arrOfJobs[i].name
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << arrOfJobs[i].profit << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "Нет работ с такой или большей прибылью(\n";
        break;
    }
    }
    return 1;
}

extern int remaking() {
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }

    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    std::cout << "Информацию о какой работе вы хотите изменить?\n";
    for (int i = 0; i < arrOfJobs.size(); ++i) {
        std::cout << i + 1 << " -- " << arrOfJobs[i].name << '\n';
    }
    int num = inputInteger();
    if (num < 1 || num > numberOfJobs) {
        std::cerr << "Такой работы нет\n";
        return 0;
    }
    num--;

    std::cout << "Что именно вы хотите изменить?\n"
        << "1 -- Название\n"
        << "2 -- Стоимость\n"
        << "3 -- Доход\n"
        << "4 -- Выход\n";
    int n = inputInteger();
    if (n < 1 || n > 3) {
        std::cout << "Вы ввели что-то не то...";
        return 0;
    }

    switch (n) {
    case 1:
        std::cout << "Старое значение: " << arrOfJobs[num].name << '\n';
        std::cout << "Введите новое значение: ";
        std::cin >> arrOfJobs[num].name;
        break;
    case 2:
        std::cout << "Старое значение: " << arrOfJobs[num].cost << '\n';
        std::cout << "Введите новое значение: ";
        arrOfJobs[num].cost = inputInteger();
        if (arrOfJobs[num].cost < 0) {
            std::cout << "Некорректное значение";
            return 0;
        }
        break;
    case 3:
        std::cout << "Старое значение: " << arrOfJobs[num].revenue << '\n';
        std::cout << "Введите новое значение: ";
        arrOfJobs[num].revenue = inputDigit();
        if (arrOfJobs[num].revenue < 0) {
            std::cout << "Некорректное значение";
            return 0;
        }
        break;
    case 4:
        return 1;
    }

    std::ofstream outFileJob("jobs.txt");
    if (!outFileJob) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    for (const auto& job : arrOfJobs) {
        outFileJob << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFileJob.close();

    return 1;
}

extern int deleting() {
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }

    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    std::cout << "Информацию о какой работе вы хотите удалить?\n";
    for (int i = 0; i < arrOfJobs.size(); ++i) {
        std::cout << i + 1 << " -- " << arrOfJobs[i].name << '\n';
    }
    int num = inputInteger();
    if (num < 1 || num > numberOfJobs) {
        std::cerr << "Такой работы нет\n";
        return 1;
    }
    num--;

    arrOfJobs.erase(arrOfJobs.begin() + num);
    numberOfJobs--;

    std::ofstream outFile("numberOfJobs.txt");
    if (!outFile) {
        std::cerr << "Ошибка обновления числа работ(\n";
        return 0;
    }
    outFile << numberOfJobs;
    outFile.close();

    std::ofstream outFileKino("jobs.txt");
    if (!outFileKino) {
        std::cerr << "Ошибка открытия файла(\n";
        return 0;
    }
    for (const auto& job : arrOfJobs) {
        outFileKino << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFileKino.close();

    return 1;
}

extern void deleteFile() {
    if (remove("numberOfJobs.txt")) std::cerr << "Ошибка удаления numberOfJobs.txt\n";
    if (remove("jobs.txt")) std::cerr << "Ошибка удаления jobs.txt\n";
}
