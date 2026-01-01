#ifndef SERVICES_H
#define SERVICES_H

#include "Entities.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <algorithm> // required for deletions

// ---  VALIDATOR CLASS ---
class Validator {
public:
    static bool isNotEmpty(QString text) {
        return !text.trimmed().isEmpty();
    }
    static bool isNumeric(QString text) {
        bool ok;
        text.toInt(&ok);
        return ok;
    }
};

// DATABASE ASSISTANT
class DatabaseConnector {
public:
    static void savePets(const std::vector<Pet>& pets) {
        QFile file("pets_db.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (const auto& p : pets) {
                out << p.id << "," << p.name << "," << p.species << ","
                    << p.age << "," << p.health << "," << p.status << "\n";
            }
            file.close();
        }
    }

    static void saveAdopters(const std::vector<Adopter>& adopters) {
        QFile file("adopters_db.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (const auto& a : adopters) {
                out << a.id << "," << a.fullName << "," << a.phone << "," << a.address << "\n";
            }
            file.close();
        }
    }
};

// ---  PET SERVICE ---
class PetService {
private:
    std::vector<Pet> pets;
public:
    PetService() { load(); }

    int generateId() {
        if (pets.empty()) return 1; // Hiç kayıt yoksa 1'den başla

        int maxId = 0;
        for (const auto& p : pets) {
            if (p.id > maxId) maxId = p.id;
        }
        return maxId + 1;
    }

    void load() {
        pets.clear();
        QFile file("pets_db.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 6) {
                pets.push_back(Pet(parts[0].toInt(), parts[1], parts[2], parts[3].toInt(), parts[4], parts[5]));
            }
        }
        file.close();
    }

    bool addPet(int id, QString name, QString species, int age, QString health) {
        for(const auto& p : pets) {
            if(p.id == id) return false;
        }

        pets.push_back(Pet(id, name, species, age, health));
        DatabaseConnector::savePets(pets);
        return true;
    }

    // DELETE
    bool deletePet(int id) {
        auto it = std::remove_if(pets.begin(), pets.end(), [id](const Pet& p){ return p.id == id; });
        if (it != pets.end()) {
            pets.erase(it, pets.end());
            DatabaseConnector::savePets(pets);
            return true;
        }
        return false;
    }

    // UPDATE
    bool updatePet(int id, QString name, QString species, int age, QString health) {
        for(auto& p : pets) {
            if(p.id == id) {
                p.name = name; p.species = species; p.age = age; p.health = health;
                DatabaseConnector::savePets(pets);
                return true;
            }
        }
        return false;
    }

    //STATUS UPDATE (For Adoption)
    void updatePetStatus(int petId, QString newStatus) {
        for(auto& p : pets) {
            if(p.id == petId) {
                p.status = newStatus;
                break;
            }
        }
        DatabaseConnector::savePets(pets);
    }

    std::vector<Pet> getAllPets() { return pets; }
};

// ---  ADOPTER SERVICE ---
class AdopterService {
private:
    std::vector<Adopter> adopters;
public:
    AdopterService() { load(); }

    void load() {
        adopters.clear();
        QFile file("adopters_db.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 4) {
                adopters.push_back(Adopter(parts[0].toInt(), parts[1], parts[2], parts[3]));
            }
        }
        file.close();
    }

    bool addAdopter(int id, QString fullName, QString phone, QString address) {
        for(const auto& a : adopters) if(a.id == id) return false;
        adopters.push_back(Adopter(id, fullName, phone, address));
        DatabaseConnector::saveAdopters(adopters);
        return true;
    }

    // DELETE
    bool deleteAdopter(int id) {
        auto it = std::remove_if(adopters.begin(), adopters.end(), [id](const Adopter& a){ return a.id == id; });
        if (it != adopters.end()) {
            adopters.erase(it, adopters.end());
            DatabaseConnector::saveAdopters(adopters);
            return true;
        }
        return false;
    }

    // UPDATE
    bool updateAdopter(int id, QString name, QString phone, QString address) {
        for(auto& a : adopters) {
            if(a.id == id) {
                a.fullName = name; a.phone = phone; a.address = address;
                DatabaseConnector::saveAdopters(adopters);
                return true;
            }
        }
        return false;
    }

    std::vector<Adopter> getAllAdopters() { return adopters; }
};

// ---  ADOPTION SERVICE ---
class AdoptionService {
public:
    bool performAdoption(int petId, int adopterId, PetService& petService) {
        petService.updatePetStatus(petId, "Adopted");
        return true;
    }
};

#endif // SERVICES_H
