#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include "lab1.3.h"

struct Job 
{
    char name[30]; 
    float cost;      
    float revenue;   
    float profit;    
};

int inputInteger() {
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�������� ����. ����������, ������� ����� �����: ";
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
            std::cout << "�������� ����. ����������, ������� �����: ";
        }
    }
}

void getStringInput(char* buffer, int bufferSize) {
    std::cin.get();
    std::cin.getline(buffer, bufferSize);
}

int inputStruct() {
    int numberOfJobs = 0, newJobs = 0;
    std::ifstream inFile("numberOfJobs.txt");
    if (inFile) {
        inFile >> numberOfJobs;
        inFile.close();
    }
    std::cout << "������� ����� ����� �� ������ ��������? ";
    newJobs = inputInteger();
    if (newJobs < 0) {
        std::cerr << "�� ����� ���-�� �� ��...\nPress any key to continue...\n";
        system("pause");
        return 0;
    }
    std::ofstream outFile("jobs.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "������ �������� ����� ��� ������ �����(\n";
        return 0;
    }
    Job job;
    for (int i = numberOfJobs; i < numberOfJobs + newJobs; ++i) {
        std::cout << "������� �������� ������ �" << (i + 1) << ": ";
        std::cin.getline(job.name, 30);
        std::cout << "������� ��������� ������: ";
        job.cost = inputDigit();
        std::cout << "������� ����� �� ������: ";
        job.revenue = inputDigit();
        job.profit = job.revenue - job.cost;
        if (job.cost < 0 || job.revenue < 0) {
            std::cerr << "�� ����� ���-�� �� ��...\nPress any key to continue...\n";
            outFile.close();
            deleteFile();
            system("pause");
            return 0;
        }
        outFile << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFile.close();
    numberOfJobs += newJobs;
    std::ofstream updateCount("numberOfJobs.txt");
    if (!updateCount) {
        std::cerr << "������ ���������� ����� �����(\n";
        return 0;
    }
    updateCount << numberOfJobs;
    updateCount.close();
    std::cout << "������ ����� ������� ��������! ������ � ��� " << numberOfJobs << " �����.\n";
    return 1;
}

int outputStruct(int n, int num) {
    int numberOfJobs = 0;
    std::ifstream readJobCount("numberOfJobs.txt");
    if (readJobCount) {
        readJobCount >> numberOfJobs;
        readJobCount.close();
    }
    else {
        std::cerr << "������ �������� ����� numberOfJobs.txt ��� ������\n";
        return 0;
    }
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "������ �������� ����� jobs.txt ��� ������\n";
        return 0;
    }
    if (n == 0) {
        text();
        Job job;
        std::string line;
        for (int i = 0; i < numberOfJobs; i++) {
            if (!std::getline(inFileJob, line)) {
                std::cerr << "������ ������ ������ " << i << " �� �����\n";
                break;
            }

            std::istringstream iss(line);
            if (!(iss.getline(job.name, 30, ' ') >> job.cost >> job.revenue >> job.profit)) {
                std::cerr << "������ ������� ������ ������ " << i << " �� �����\n";
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
                std::cerr << "������ ��� ������ ������ �� �������\n";
                inFileJob.close();
                return 0;
            }
        }
        if (!inFileJob.getline(job.name, 30, ' ') ||
            !(inFileJob >> job.cost) ||
            !(inFileJob >> job.revenue) ||
            !(inFileJob >> job.profit)) {
            std::cerr << "������ ������ ������ �� ������� " << num << " �� �����\n";
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

int sorting() {
    std::cout << "��� ������ �� ������ ������������� ������?\n"
        << "1 -- � ���������� ������� �� ��������\n"
        << "2 -- �� ���������\n"
        << "3 -- �� ������\n"
        << "4 -- �� �������\n"
        << "5 -- �����\n";

    int n = inputInteger();
    if (n < 1 || n > 5) {
        std::cout << "�� ����� ���-�� �� ��...";
        return 0;
    }
    if (n == 5) return 0;

    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }

    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    for (int i = 0; i < numberOfJobs - 1; ++i) {
        for (int j = i + 1; j < numberOfJobs; ++j) {
            bool shouldSwap = false;
            switch (n) {
            case 1: shouldSwap = strcmp(arrOfJobs[i].name, arrOfJobs[j].name) > 0; break;
            case 2: shouldSwap = arrOfJobs[i].cost > arrOfJobs[j].cost; break;
            case 3: shouldSwap = arrOfJobs[i].revenue > arrOfJobs[j].revenue; break;
            case 4: shouldSwap = arrOfJobs[i].profit > arrOfJobs[j].profit; break;
            }
            if (shouldSwap) {
                Job temp = arrOfJobs[i];
                arrOfJobs[i] = arrOfJobs[j];
                arrOfJobs[j] = temp;
            }
        }
    }

    std::ofstream outFileJob("jobs.txt");
    if (!outFileJob) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    for (const auto& Job : arrOfJobs) {
        outFileJob << Job.name << " " << Job.cost << " " << Job.revenue << " " << Job.profit << std::endl;
    }
    outFileJob.close();

    return 1;
}

void text()
{
    std::cout << std::left << std::setw(20) << "�������� ������"
        << std::setw(15) << "���������"
        << std::setw(15) << "�����"
        << std::setw(15) << "�������" << std::endl;
    std::cout << std::string(65, '=') << std::endl;
}

int finder() {
    std::cout << "�� ������ ��������� �� ������ ��������� �����?\n"
        << "1 -- �� �������� ������\n"
        << "2 -- �� ��������� ������\n"
        << "3 -- �� ������ �� ������\n"
        << "4 -- �� �������\n"
        << "5 -- �����\n";
    int n = inputInteger();
    if (n < 1 || n > 5) {
        std::cout << "�� ����� ���-�� �� ��...";
        return 0;
    }
    if (n == 5) return 0;
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();
    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "������ �������� �����(\n";
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
        std::cout << "������� �������� ������: ";
        getStringInput(input, 30);
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
        if (!found) std::cout << "��� ����� � ����� ���������(\n";
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
        if (!found) std::cout << "��� ����� � ����� ��� ������� ����������(\n";
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
        if (!found) std::cout << "��� ����� � ����� ��� ������� �������(\n";
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
        if (!found) std::cout << "��� ����� � ����� ��� ������� ��������(\n";
        break;
    }
    }
    return 1;
}

int remaking() {
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }

    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    std::cout << "���������� � ����� ������ �� ������ ��������?\n";
    for (int i = 0; i < arrOfJobs.size(); ++i) {
        std::cout << i + 1 << " -- " << arrOfJobs[i].name << '\n';
    }
    int num = inputInteger();
    if (num < 1 || num > numberOfJobs) {
        std::cerr << "������ ������ ���\n";
        return 0;
    }
    num--;

    std::cout << "��� ������ �� ������ ��������?\n"
        << "1 -- ��������\n"
        << "2 -- ���������\n"
        << "3 -- �����\n"
        << "4 -- �����\n";
    int n = inputInteger();
    if (n < 1 || n > 3) {
        std::cout << "�� ����� ���-�� �� ��...";
        return 0;
    }

    switch (n) {
    case 1:
        std::cout << "������ ��������: " << arrOfJobs[num].name << '\n';
        std::cout << "������� ����� ��������: ";
        getStringInput(arrOfJobs[num].name, 30);
        break;
    case 2:
        std::cout << "������ ��������: " << arrOfJobs[num].cost << '\n';
        std::cout << "������� ����� ��������: ";
        arrOfJobs[num].cost = inputInteger();
        if (arrOfJobs[num].cost < 0) {
            std::cout << "������������ ��������";
            return 0;
        }
        break;
    case 3:
        std::cout << "������ ��������: " << arrOfJobs[num].revenue << '\n';
        std::cout << "������� ����� ��������: ";
        arrOfJobs[num].revenue = inputDigit();
        if (arrOfJobs[num].revenue < 0) {
            std::cout << "������������ ��������";
            return 0;
        }
        break;
    case 4:
        return 1;
    }

    std::ofstream outFileJob("jobs.txt");
    if (!outFileJob) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    for (const auto& job : arrOfJobs) {
        outFileJob << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFileJob.close();

    return 1;
}

int deleting() {
    int numberOfJobs;
    std::ifstream inFile("numberOfJobs.txt");
    if (!inFile) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    inFile >> numberOfJobs;
    inFile.close();

    std::vector<Job> arrOfJobs(numberOfJobs);
    std::ifstream inFileJob("jobs.txt");
    if (!inFileJob) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }

    for (int i = 0; i < numberOfJobs; ++i) {
        inFileJob.getline(arrOfJobs[i].name, 30, ' ');
        inFileJob >> arrOfJobs[i].cost >> arrOfJobs[i].revenue >> arrOfJobs[i].profit;
        inFileJob.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inFileJob.close();

    std::cout << "���������� � ����� ������ �� ������ �������?\n";
    for (int i = 0; i < arrOfJobs.size(); ++i) {
        std::cout << i + 1 << " -- " << arrOfJobs[i].name << '\n';
    }
    int num = inputInteger();
    if (num < 1 || num > numberOfJobs) {
        std::cerr << "����� ������ ���\n";
        return 1;
    }
    num--;

    arrOfJobs.erase(arrOfJobs.begin() + num);
    numberOfJobs--;

    std::ofstream outFile("numberOfJobs.txt");
    if (!outFile) {
        std::cerr << "������ ���������� ����� �����(\n";
        return 0;
    }
    outFile << numberOfJobs;
    outFile.close();

    std::ofstream outFileKino("jobs.txt");
    if (!outFileKino) {
        std::cerr << "������ �������� �����(\n";
        return 0;
    }
    for (const auto& job : arrOfJobs) {
        outFileKino << job.name << " " << job.cost << " " << job.revenue << " " << job.profit << std::endl;
    }
    outFileKino.close();

    return 1;
}

extern void deleteFile() {
    if (remove("numberOfJobs.txt")) std::cerr << "������ �������� numberOfJobs.txt\n";
    if (remove("jobs.txt")) std::cerr << "������ �������� jobs.txt\n";
}
