#ifndef ENTITIES_H
#define ENTITIES_H

#include <QString>

// --- PET ENTITY ---
class Pet {
public:
    int id;
    QString name;
    QString species;
    int age;
    QString health;
    QString status; // "Available" veya "Adopted"

    Pet(int i, QString n, QString s, int a, QString h, QString st = "Available")
        : id(i), name(n), species(s), age(a), health(h), status(st) {}
};

// ---  ADOPTER ENTITY ---
class Adopter {
public:
    int id;
    QString fullName;
    QString phone;
    QString address;

    Adopter(int i, QString fn, QString ph, QString addr)
        : id(i), fullName(fn), phone(ph), address(addr) {}
};

// ---  STAFF ENTITY (NEW) ---
class Staff {
public:
    QString username;
    QString password;

    Staff(QString u, QString p) : username(u), password(p) {}
};

#endif // ENTITIES_H
