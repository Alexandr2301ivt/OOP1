#include "Potion.h"
#include <iostream>

using namespace std;

// Potion
Potion::Potion(double vol, const string& material) : volume(vol), remainingVolume(vol), flaskMaterial(material) {}
Potion::~Potion() {}

void Potion::getDataCreated() {
    cout << "Зелье создано с объёмом " << volume << " мл и материалом " << flaskMaterial << "\n";
}

void Potion::updateInfo() {
    cout << "Обновлена информация: осталось " << remainingVolume << " мл\n";
}

void Potion::drink(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "Вы выпили " << amount << " мл зелья из " << flaskMaterial << ". Осталось: " << remainingVolume << " мл.\n";
}

void Potion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "Вы вылили " << amount << " мл зелья из " << flaskMaterial << ". Осталось: " << remainingVolume << " мл.\n";
}

// HealthPotion
HealthPotion::HealthPotion(double vol, const string& material) : Potion(vol, material) {}

void HealthPotion::getDataCreated() {
    Potion::getDataCreated();
    cout << "Тип: Зелье здоровья\n";
}

void HealthPotion::drink(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    double hpRestored = amount;
    cout << "Вы выпили " << amount << " мл зелья здоровья. Восстановлено " << hpRestored << " ХП. Осталось: " << remainingVolume << " мл.\n";
}

void HealthPotion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "Вы вылили " << amount << " мл зелья здоровья. Осталось: " << remainingVolume << " мл.\n";
}

void HealthPotion::throwAtUndead() {
    cout << "Бросок в нежить: нанесен урон.\n";
}

void HealthPotion::resurrect() {
    cout << "Вы воскресили персонажа.\n";
}

// PoisonPotion
PoisonPotion::PoisonPotion(double vol, const string& material) : Potion(vol, material) {}

void PoisonPotion::getDataCreated() {
    Potion::getDataCreated();
    cout << "Тип: Зелье яда\n";
}

void PoisonPotion::drink(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    double damage = amount;
    cout << "Вы выпили " << amount << " мл зелья яда. Получен урон в размере " << damage << " ХП. Осталось: " << remainingVolume << " мл.\n";
}

void PoisonPotion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "Зелье уже кончилось!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "Вы вылили " << amount << " мл зелья яда. Осталось: " << remainingVolume << " мл.\n";
}

void PoisonPotion::sendToItem() {
    cout << "Предмет отравлен.\n";
}

void PoisonPotion::weakenEffects() {
    cout << "Ослабление всех эффектов.\n";
}