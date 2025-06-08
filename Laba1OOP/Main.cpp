#include <iostream>
#include <string>
#define NOMINMAX
#include <Windows.h>
#include <limits>
#include <locale.h>
#include "Potion.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidInput(int choice, int min, int max) {
    return choice >= min && choice <= max;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Potion* potion = nullptr;

    while (true) {
        int choice;
        cout << "�������� �����:\n"
            << "0 - �����\n"
            << "1 - ����� ��������\n"
            << "2 - ����� ���\n"
            << "��� �����: ";
        while (!(cin >> choice) || !isValidInput(choice, 0, 2)) {
            cout << "������! ������� ����� �� 0 �� 2: ";
            clearInput();
        }

        if (choice == 0) {
            cout << "���������� ���������...\n";
            delete potion;
            break;
        }

        if (potion == nullptr || potion->isEmpty()) {
            if (potion != nullptr) {
                delete potion;
                potion = nullptr;
            }

            int volumeChoice;
            cout << "�������� ����� �����:\n1 - 100 ��\n2 - 50 ��\n��� �����: ";
            while (!(cin >> volumeChoice) || !isValidInput(volumeChoice, 1, 2)) {
                cout << "������! ������� 1 ��� 2: ";
                clearInput();
            }

            double volume = (volumeChoice == 1) ? 100 : 50;

            int materialChoice;
            string material;
            cout << "�������� �������� ������:\n1 - ������\n2 - ��������\n��� �����: ";
            while (!(cin >> materialChoice) || !isValidInput(materialChoice, 1, 2)) {
                cout << "������! ������� 1 ��� 2: ";
                clearInput();
            }

            material = (materialChoice == 1) ? "������" : "��������";

            if (choice == 1)
                potion = new HealthPotion(volume, material);
            else
                potion = new PoisonPotion(volume, material);
        }

        int action;
        while (true) {
            cout << "\n������� ����� �����: " << potion->getRemainingVolume() << " ��\n";
            cout << "�������� ��������:\n"
                << "1 - ������ �����\n"
                << "2 - ������ �����\n"
                << "3 - ����������� ��������\n"
                << "0 - ��������� � ������ �����\n"
                << "��� �����: ";
            while (!(cin >> action) || !isValidInput(action, 0, 3)) {
                cout << "������! ������� ����� �� 0 �� 3: ";
                clearInput();
            }

            if (action == 0) break;

            if (action == 1 || action == 2) {
                int amountChoice;
                cout << "1 - ���������\n2 - ����������\n��� �����: ";
                while (!(cin >> amountChoice) || !isValidInput(amountChoice, 1, 2)) {
                    cout << "������! ������� 1 ��� 2: ";
                    clearInput();
                }
                bool full = (amountChoice == 1);

                if (action == 1) {
                    potion->drink(full);
                }
                else {
                    potion->pourOut(full);
                }
                if (potion->isEmpty()) {
                    cout << "����� ��������� ������������. �������� ����� �����.\n";
                    break;
                }
            }
            else if (action == 3) {
                int specialAction;
                if (auto* hp = dynamic_cast<HealthPotion*>(potion)) {
                    cout << "1 - ���������� ���������\n2 - ������ � ������\n��� �����: ";
                    while (!(cin >> specialAction) || !isValidInput(specialAction, 1, 2)) {
                        cout << "������! ������� 1 ��� 2: ";
                        clearInput();
                    }
                    (specialAction == 1) ? hp->resurrect() : hp->throwAtUndead();
                }
                else if (auto* pp = dynamic_cast<PoisonPotion*>(potion)) {
                    cout << "1 - �������� �������\n2 - �������� �������\n��� �����: ";
                    while (!(cin >> specialAction) || !isValidInput(specialAction, 1, 2)) {
                        cout << "������! ������� 1 ��� 2: ";
                        clearInput();
                    }
                    (specialAction == 1) ? pp->sendToItem() : pp->weakenEffects();
                }
                break;
            }
        }
    }

    return 0;
}