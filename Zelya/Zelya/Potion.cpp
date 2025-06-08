#include "Potion.h"
#include <iostream>

using namespace std;

// Potion
Potion::Potion(double vol, const string& material) : volume(vol), remainingVolume(vol), flaskMaterial(material) {}
Potion::~Potion() {}

void Potion::drink(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "�� ������ " << amount << " �� ����� �� " << flaskMaterial << ". ��������: " << remainingVolume << " ��.\n";
}

void Potion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "�� ������ " << amount << " �� ����� �� " << flaskMaterial << ". ��������: " << remainingVolume << " ��.\n";
}

// HealthPotion
HealthPotion::HealthPotion(double vol, const string& material) : Potion(vol, material) {}

void HealthPotion::drink(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    double hpRestored = amount; // 1 �� = 1 ��
    cout << "�� ������ " << amount << " �� ����� ��������. ������������� " << hpRestored << " ��. ��������: " << remainingVolume << " ��.\n";
}

void HealthPotion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "�� ������ " << amount << " �� ����� ��������. ��������: " << remainingVolume << " ��.\n";
}

void HealthPotion::throwAtUndead() {
    cout << "������ � ������: ������� ����.\n";
}

void HealthPotion::resurrect() {
    cout << "�� ���������� ���������.\n";
}

// PoisonPotion
PoisonPotion::PoisonPotion(double vol, const string& material) : Potion(vol, material) {}

void PoisonPotion::drink(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    double damage = amount; // 1 �� = 1 �� �����
    cout << "�� ������ " << amount << " �� ����� ���. ������� ���� � ������� " << damage << " ��. ��������: " << remainingVolume << " ��.\n";
}

void PoisonPotion::pourOut(bool full) {
    if (isEmpty()) {
        cout << "����� ��� ���������!\n";
        return;
    }
    double amount = full ? remainingVolume : remainingVolume / 2;
    remainingVolume -= amount;
    if (remainingVolume < 0) remainingVolume = 0;
    cout << "�� ������ " << amount << " �� ����� ���. ��������: " << remainingVolume << " ��.\n";
}

void PoisonPotion::sendToItem() {
    cout << "������� ��������.\n";
}

void PoisonPotion::weakenEffects() {
    cout << "���������� ���� ��������.\n";
}