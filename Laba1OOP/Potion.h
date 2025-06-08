#pragma once
#include <string>

using namespace std;

class Potion {
protected:
    double volume;           // ����������� ����� �����
    double remainingVolume;  // ���������� �����
    string flaskMaterial;

public:
    Potion(double vol, const string& material);
    virtual ~Potion();
    virtual void getDataCreated(); // ����������� ����� ��� �������������
    double getRemainingVolume() const { return remainingVolume; }
    string getFlaskMaterial() const { return flaskMaterial; }
    void setVolume(double vol) { volume = vol; remainingVolume = vol; }
    void setFlaskMaterial(const string& material) { flaskMaterial = material; }
    void updateInfo(); // ����� ��� ���������� ����������
    virtual void drink(bool full = true);
    virtual void pourOut(bool full = true);
    bool isEmpty() const { return remainingVolume <= 0; }
};

class HealthPotion : public Potion {
public:
    HealthPotion(double vol, const string& material);
    void getDataCreated() override; // �������������� ��� ������������� �������������
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void throwAtUndead();
    void resurrect();
    void getType() { cout << "Health Potion\n"; } // ��������� ��� ������������
    void printInfo() { cout << "Health Potion: " << remainingVolume << " ��, ��������: " << flaskMaterial << "\n"; }
};

class PoisonPotion : public Potion {
public:
    PoisonPotion(double vol, const string& material);
    void getDataCreated() override; // �������������� ��� ������������� �������������
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void sendToItem();
    void weakenEffects();
    void getType() { cout << "Poison Potion\n"; } // ��������� ��� ������������
    void printInfo() { cout << "Poison Potion: " << remainingVolume << " ��, ��������: " << flaskMaterial << "\n"; }
};