#pragma once
#include <string>

using namespace std;

class Potion {
protected:
    double volume;           // Изначальный объём зелья
    double remainingVolume;  // Оставшийся объём
    string flaskMaterial;

public:
    Potion(double vol, const string& material);
    virtual ~Potion();
    virtual void getDataCreated(); // Абстрактный метод для инициализации
    double getRemainingVolume() const { return remainingVolume; }
    string getFlaskMaterial() const { return flaskMaterial; }
    void setVolume(double vol) { volume = vol; remainingVolume = vol; }
    void setFlaskMaterial(const string& material) { flaskMaterial = material; }
    void updateInfo(); // Метод для обновления информации
    virtual void drink(bool full = true);
    virtual void pourOut(bool full = true);
    bool isEmpty() const { return remainingVolume <= 0; }
};

class HealthPotion : public Potion {
public:
    HealthPotion(double vol, const string& material);
    void getDataCreated() override; // Переопределяем для специфической инициализации
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void throwAtUndead();
    void resurrect();
    void getType() { cout << "Health Potion\n"; } // Добавляем для соответствия
    void printInfo() { cout << "Health Potion: " << remainingVolume << " мл, материал: " << flaskMaterial << "\n"; }
};

class PoisonPotion : public Potion {
public:
    PoisonPotion(double vol, const string& material);
    void getDataCreated() override; // Переопределяем для специфической инициализации
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void sendToItem();
    void weakenEffects();
    void getType() { cout << "Poison Potion\n"; } // Добавляем для соответствия
    void printInfo() { cout << "Poison Potion: " << remainingVolume << " мл, материал: " << flaskMaterial << "\n"; }
};