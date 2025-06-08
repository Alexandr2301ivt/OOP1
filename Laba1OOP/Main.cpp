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
        cout << "Выберите зелье:\n"
            << "0 - Выход\n"
            << "1 - Зелье здоровья\n"
            << "2 - Зелье яда\n"
            << "Ваш выбор: ";
        while (!(cin >> choice) || !isValidInput(choice, 0, 2)) {
            cout << "Ошибка! Введите число от 0 до 2: ";
            clearInput();
        }

        if (choice == 0) {
            cout << "Завершение программы...\n";
            delete potion;
            break;
        }

        if (potion == nullptr || potion->isEmpty()) {
            if (potion != nullptr) {
                delete potion;
                potion = nullptr;
            }

            int volumeChoice;
            cout << "Выберите объем зелья:\n1 - 100 мл\n2 - 50 мл\nВаш выбор: ";
            while (!(cin >> volumeChoice) || !isValidInput(volumeChoice, 1, 2)) {
                cout << "Ошибка! Введите 1 или 2: ";
                clearInput();
            }

            double volume = (volumeChoice == 1) ? 100 : 50;

            int materialChoice;
            string material;
            cout << "Выберите материал сосуда:\n1 - Стекло\n2 - Керамика\nВаш выбор: ";
            while (!(cin >> materialChoice) || !isValidInput(materialChoice, 1, 2)) {
                cout << "Ошибка! Введите 1 или 2: ";
                clearInput();
            }

            material = (materialChoice == 1) ? "стекло" : "керамика";

            if (choice == 1)
                potion = new HealthPotion(volume, material);
            else
                potion = new PoisonPotion(volume, material);
        }

        int action;
        while (true) {
            cout << "\nТекущий объём зелья: " << potion->getRemainingVolume() << " мл\n";
            cout << "Выберите действие:\n"
                << "1 - Выпить зелье\n"
                << "2 - Вылить зелье\n"
                << "3 - Специальное действие\n"
                << "0 - Вернуться к выбору зелья\n"
                << "Ваш выбор: ";
            while (!(cin >> action) || !isValidInput(action, 0, 3)) {
                cout << "Ошибка! Введите число от 0 до 3: ";
                clearInput();
            }

            if (action == 0) break;

            if (action == 1 || action == 2) {
                int amountChoice;
                cout << "1 - Полностью\n2 - Наполовину\nВаш выбор: ";
                while (!(cin >> amountChoice) || !isValidInput(amountChoice, 1, 2)) {
                    cout << "Ошибка! Введите 1 или 2: ";
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
                    cout << "Зелье полностью использовано. Выберите новое зелье.\n";
                    break;
                }
            }
            else if (action == 3) {
                int specialAction;
                if (auto* hp = dynamic_cast<HealthPotion*>(potion)) {
                    cout << "1 - Воскресить персонажа\n2 - Бросок в нежить\nВаш выбор: ";
                    while (!(cin >> specialAction) || !isValidInput(specialAction, 1, 2)) {
                        cout << "Ошибка! Введите 1 или 2: ";
                        clearInput();
                    }
                    (specialAction == 1) ? hp->resurrect() : hp->throwAtUndead();
                }
                else if (auto* pp = dynamic_cast<PoisonPotion*>(potion)) {
                    cout << "1 - Отравить предмет\n2 - Ослабить эффекты\nВаш выбор: ";
                    while (!(cin >> specialAction) || !isValidInput(specialAction, 1, 2)) {
                        cout << "Ошибка! Введите 1 или 2: ";
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