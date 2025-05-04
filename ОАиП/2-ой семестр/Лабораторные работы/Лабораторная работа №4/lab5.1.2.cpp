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
#include "lab5.1.h"
#include <functional>

// ******************* Реализация стека *******************

void initStack(Stack& s) {
    s.top = nullptr;
}

void push(Stack& s, const Job& job) {
    Node* newNode = new Node;
    newNode->job = job;
    newNode->next = s.top;
    s.top = newNode;
}

bool pop(Stack& s, Job& job) {
    if (s.top == nullptr)
        return false;
    Node* temp = s.top;
    job = temp->job;
    s.top = s.top->next;
    delete temp;
    return true;
}

void freeStack(Stack& s) {
    while (s.top != nullptr) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

bool isEmptyStack(const Stack& s) {
    return (s.top == nullptr);
}

int stackSize(const Stack& s) {
    int count = 0;
    Node* temp = s.top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ******************* Вспомогательные функции для работы с файлами *******************

Stack loadStackFromFile() {
    Stack s;
    initStack(s);

    std::ifstream inFile("jobs.txt");
    std::ifstream countFile("numberOfJobs.txt");
    if (!countFile) {
        std::cerr << "Ошибка открытия файла numberOfJobs.txt\n";
        return s;
    }
    int numberOfJobs;
    countFile >> numberOfJobs;
    countFile.close();

    for (int i = 0; i < numberOfJobs; i++) {
        Job job;
        std::string nameLine;
        if (!std::getline(inFile, nameLine)) break;
        strcpy_s(job.name, sizeof(job.name), nameLine.c_str());

        std::string numbersLine;
        if (!std::getline(inFile, numbersLine)) break;
        std::istringstream iss(numbersLine);
        if (!(iss >> job.cost >> job.revenue >> job.profit)) break;

        push(s, job);
    }
    inFile.close();
    return s;
}

bool writeStackToFile(Stack& s) {
    int size = stackSize(s);
    std::ofstream outCount("numberOfJobs.txt");
    if (!outCount) return false;
    outCount << size;
    outCount.close();

    std::ofstream outFile("jobs.txt");
    if (!outFile) return false;
    Node* temp = s.top;
    while (temp != nullptr) {
        outFile << temp->job.name << std::endl;
        outFile << temp->job.cost << " "
            << temp->job.revenue << " "
            << temp->job.profit << std::endl;
        temp = temp->next;
    }
    outFile.close();
    return true;
}

// -------------------- Остальные функции --------------------

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

extern int inputStruct() {
    Stack s = loadStackFromFile();
    int currentCount = stackSize(s);
    std::cout << "Сколько новых работ вы хотите добавить? ";
    int newJobs = inputInteger();
    if (newJobs < 0) { freeStack(s); return 0; }
    int added = 0;
    for (int i = 0; i < newJobs; ++i) {
        Job job;
        std::cout << "Введите название работы №" << (currentCount + added + 1) << ": ";
        std::cin.getline(job.name, 30);
        if (job.name[0] == '\0') continue;
        std::cout << "Введите стоимость работы: "; job.cost = inputInteger();
        std::cout << "Введите доход от работы: "; job.revenue = inputInteger();
        job.profit = job.revenue - job.cost;
        push(s, job);
        added++;
    }

    int updated = currentCount + added;
    std::ofstream upd("numberOfJobs.txt");
    upd << updated;
    upd.close();
    writeStackToFile(s);
    freeStack(s);
    return 1;
}


extern int outputStruct(int mode, int index) {
    Stack s = loadStackFromFile();
    if (isEmptyStack(s)) {
        std::cerr << "Файл пуст или нет работ.\n";
        return 0;
    }
    if (mode == 0) {
        text();
        Node* temp = s.top;
        while (temp != nullptr) {
            Job job = temp->job;
            std::cout << std::left << std::setw(25) << job.name
                << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
            temp = temp->next;
        }
    }
    else if (mode == 1) {
        int pos = 0;
        bool found = false;
        Node* temp = s.top;
        while (temp != nullptr) {
            if (pos == index) {
                Job job = temp->job;
                std::cout << std::left << std::setw(20) << job.name
                    << std::setw(15) << job.cost
                    << std::setw(20) << std::fixed << std::setprecision(2) << job.revenue
                    << std::setw(20) << job.profit << std::endl;
                found = true;
                break;
            }
            pos++;
            temp = temp->next;
        }
        if (!found) {
            std::cerr << "Работа с заданным индексом не найдена\n";
        }
    }
    freeStack(s);
    return 1;
}



extern int sorting() {
    std::cout << "Как именно вы хотите отсортировать работы?\n"
        << "1 -- По названию\n"
        << "2 -- По стоимости\n"
        << "3 -- По доходу\n"
        << "4 -- По прибыли\n"
        << "5 -- Выход\n";
    int criterion = inputInteger();
    if (criterion < 1 || criterion > 5) {
        std::cout << "Неверный ввод\n";
        return 0;
    }
    if (criterion == 5) return 0;

    std::cout << "Выберите тип сортировки:\n"
        << "1 -- Сортировка выбором\n"
        << "2 -- Сортировка вставками\n"
        << "3 -- Сортировка Шелла\n"
        << "4 -- Выход\n";
    int sortType = inputInteger();
    if (sortType < 1 || sortType > 4) {
        std::cout << "Неверный ввод\n";
        return 0;
    }
    if (sortType == 4) return 0;

    // Загружаем данные в очередь, затем копируем в вектор для сортировки
    Stack s = loadStackFromFile();
    int n = stackSize(s);
    if (n == 0) {
        std::cerr << "Нет работ для сортировки\n";
        return 0;
    }
    std::vector<Job> arr;
    arr.reserve(n);
    Node* temp = s.top;
    while (temp != nullptr) {
        arr.push_back(temp->job);
        temp = temp->next;
    }
    freeStack(s);

    // Определяем компаратор
    std::function<bool(const Job&, const Job&)> comp;
    switch (criterion) {
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

    auto start = std::chrono::high_resolution_clock::now();
    if (sortType == 1) {
        // Сортировка выбором
        for (size_t i = 0; i < arr.size() - 1; i++) {
            size_t min_idx = i;
            for (size_t j = i + 1; j < arr.size(); j++) {
                if (comp(arr[j], arr[min_idx]))
                    min_idx = j;
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }
    else if (sortType == 2) {
        // Сортировка вставками
        for (int i = 1; i < arr.size(); i++) {
            Job key = arr[i];
            int j = i - 1;
            while (j >= 0 && comp(key, arr[j])) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    else if (sortType == 3) {
        // Сортировка Шелла
        for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arr.size(); i++) {
                Job tempJob = arr[i];
                int j;
                for (j = i; j >= (int)gap && comp(tempJob, arr[j - gap]); j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = tempJob;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время сортировки:\n"
        << duration.count() * 1000000 << " наносекунд, "
        << duration.count() * 1000 << " миллисекунд, "
        << duration.count() << " секунд." << std::endl;

    // Пересобираем очередь по отсортированным данным и сохраняем
    initStack(s);
    for (auto& j : arr) {
        push(s, j);
    }
    if (!writeStackToFile(s)) {
        std::cerr << "Ошибка записи в файл после сортировки\n";
        freeStack(s);
        return 0;
    }
    std::cout << "Работы успешно отсортированы!\n";
    freeStack(s);
    return 1;
}

extern int finder() {
    std::cout << "По какому параметру искать работу?\n"
        << "1 -- По названию\n"
        << "2 -- По стоимости\n"
        << "3 -- По доходу\n"
        << "4 -- По прибыли\n"
        << "5 -- Выход\n";
    int criterion = inputInteger();
    if (criterion < 1 || criterion > 5) {
        std::cout << "Неверный ввод\n";
        return 0;
    }
    if (criterion == 5)
        return 0;
    Stack s = loadStackFromFile();
    if (isEmptyStack(s)) {
        std::cerr << "Нет работ для поиска\n";
        return 0;
    }
    bool found = false;
    
    if (criterion == 1) {
        char searchName[30];
        std::cout << "Введите название работы: ";
        std::cin.getline(searchName, 30);
        text();
        Node* temp = s.top;
        while (temp != nullptr) {
            if (strcmp(temp->job.name, searchName) == 0) {
                Job job = temp->job;
                std::cout << std::left << std::setw(25) << job.name
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            std::cout << "Нет работы с таким названием\n";
    }
    else if (criterion == 2) {
        std::cout << "Введите стоимость для поиска: ";
        float cost = inputDigit();
        Node* temp = s.top;
        while (temp != nullptr) {
            if (temp->job.cost <= cost) {
                Job job = temp->job;
                std::cout << std::left << std::setw(25) << job.name
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            std::cout << "Нет работы с такой или меньшей стоимостью\n";
    }
    else if (criterion == 3) {
        std::cout << "Введите доход для поиска: ";
        float revenue = inputDigit();
        Node* temp = s.top;
        while (temp != nullptr) {
            if (temp->job.revenue >= revenue) {
                Job job = temp->job;
                std::cout << std::left << std::setw(25) << job.name
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            std::cout << "Нет работы с таким или большим доходом\n";
    }
    else if (criterion == 4) {
        std::cout << "Введите прибыль для поиска: ";
        float profit = inputDigit();
        Node* temp = s.top;
        while (temp != nullptr) {
            if (temp->job.profit >= profit) {
                Job job = temp->job;
                std::cout << std::left << std::setw(25) << job.name
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.cost
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.revenue
                    << std::setw(15) << std::fixed << std::setprecision(2) << job.profit << std::endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            std::cout << "Нет работы с такой или большей прибылью\n";
    }
    freeStack(s);
    return 1;
}

extern int remaking() {
    Stack s = loadStackFromFile();
    int size = stackSize(s);
    if (size == 0) {
        std::cerr << "Нет работ для редактирования\n";
        return 0;
    }
    std::cout << "Информация о текущих работах:\n";
    int idx = 1;
    Node* temp = s.top;
    while (temp != nullptr) {
        std::cout << idx << " -- " << temp->job.name << "\n";
        idx++;
        temp = temp->next;
    }
    std::cout << "Введите номер работы для редактирования: ";
    int pos = inputInteger();
    if (pos < 1 || pos > size) {
        std::cerr << "Такой работы нет\n";
        freeStack(s);
        return 0;
    }
    temp = s.top;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    std::cout << "Что вы хотите изменить?\n"
        << "1 -- Название\n"
        << "2 -- Стоимость\n"
        << "3 -- Доход\n"
        << "4 -- Выход\n";
    int option = inputInteger();
    switch (option) {
    case 1:
        std::cout << "Старое значение: " << temp->job.name << "\n";
        std::cout << "Введите новое название: ";
        std::cin.getline(temp->job.name, 30);
        break;
    case 2:
        std::cout << "Старое значение стоимости: " << temp->job.cost << "\n";
        std::cout << "Введите новую стоимость: ";
        temp->job.cost = inputDigit();
        if (temp->job.cost < 0) {
            std::cout << "Некорректное значение.\n";
            freeStack(s);
            return 0;
        }
        break;
    case 3:
        std::cout << "Старое значение дохода: " << temp->job.revenue << "\n";
        std::cout << "Введите новый доход: ";
        temp->job.revenue = inputDigit();
        if (temp->job.revenue < 0) {
            std::cout << "Некорректное значение.\n";
            freeStack(s);
            return 0;
        }
        break;
    case 4:
        freeStack(s);
        return 1;
    default:
        std::cout << "Неверный выбор.\n";
        freeStack(s);
        return 0;
    }
    // Пересчитываем прибыль
    temp->job.profit = temp->job.revenue - temp->job.cost;
    if (!writeStackToFile(s)) {
        std::cerr << "Ошибка записи в файл после редактирования\n";
        freeStack(s);
        return 0;
    }
    freeStack(s);
    return 1;
}

extern int deleting() {
    Stack s = loadStackFromFile();
    int size = stackSize(s);
    if (size == 0) {
        std::cerr << "Нет работ для удаления\n";
        return 0;
    }
    std::cout << "Выберите работу для удаления:\n";
    int idx = 1;
    Node* temp = s.top;
    while (temp != nullptr) {
        std::cout << idx << " -- " << temp->job.name << "\n";
        idx++;
        temp = temp->next;
    }
    std::cout << "Введите номер работы для удаления: ";
    int pos = inputInteger();
    if (pos < 1 || pos > size) {
        std::cerr << "Такой работы нет\n";
        freeStack(s);
        return 0;
    }
    // Удаляем узел в указанной позиции
    if (pos == 1) {
        Node* toDelete = s.top;
        s.top = s.top->next;
        if (s.top == nullptr)
            s.top = nullptr;
        delete toDelete;
    }
    else {
        Node* prev = s.top;
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == s.top)
            s.top = prev;
        delete toDelete;
    }
    if (!writeStackToFile(s)) {
        std::cerr << "Ошибка записи в файл после удаления\n";
        freeStack(s);
        return 0;
    }
    freeStack(s);
    return 1;
}

extern void deleteFile() {
    if (remove("numberOfJobs.txt"))
        std::cerr << "Ошибка удаления numberOfJobs.txt\n";
    if (remove("jobs.txt"))
        std::cerr << "Ошибка удаления jobs.txt\n";
}

// ******************* Функция для отображения заголовка таблицы *******************

extern void text() {
    std::cout << std::left << std::setw(25) << "Название работы"
        << std::setw(15) << "Стоимость"
        << std::setw(15) << "Доход"
        << std::setw(15) << "Прибыль" << std::endl;
    std::cout << std::string(62, '=') << std::endl;
}
