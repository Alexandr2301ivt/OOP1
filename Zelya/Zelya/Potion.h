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
    virtual void drink(bool full = true);
    virtual void pourOut(bool full = true);
    double getRemainingVolume() const { return remainingVolume; }
    bool isEmpty() const { return remainingVolume <= 0; }
};

class HealthPotion : public Potion {
public:
    HealthPotion(double vol, const string& material);
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void throwAtUndead();
    void resurrect();
};

class PoisonPotion : public Potion {
public:
    PoisonPotion(double vol, const string& material);
    void drink(bool full = true) override;
    void pourOut(bool full = true) override;
    void sendToItem();
    void weakenEffects();
};