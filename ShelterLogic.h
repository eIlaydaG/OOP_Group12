#ifndef SHELTERLOGIC_H
#define SHELTERLOGIC_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <QString>

// --- PET CLASS ---
class Pet {
public:
    int id;
    std::string name, species, health, status;
    int age;

    Pet(int i, std::string n, std::string s, int a, std::string h)
        : id(i), name(n), species(s), age(a), health(h), status("Available") {}
};

// --- DATABASE CONNECTION ---
class DatabaseConnector {
public:
    static void saveAll(const std::vector<Pet>& pets) {
        std::ofstream f("shelter_db.txt", std::ios::trunc);
        for (const auto& p : pets) {
            f << "PET," << p.id << "," << p.name << "," << p.species << ","
              << p.age << "," << p.health << "," << p.status << "\n";
        }
        f.close();
    }
};

// --- SERVICE CLASS ---
class PetService {
private:
    std::vector<Pet> pets;

public:
    PetService() { load(); }

    void load() {
        pets.clear();
        std::ifstream f("shelter_db.txt");
        if (!f.is_open()) return;

        std::string line;
        while (std::getline(f, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string tag, idS, n, s, aS, h, st;

            std::getline(ss, tag, ',');   std::getline(ss, idS, ',');
            std::getline(ss, n, ',');     std::getline(ss, s, ',');
            std::getline(ss, aS, ',');    std::getline(ss, h, ',');
            std::getline(ss, st, ',');

            if (tag == "PET") {
                try {
                    Pet p(std::stoi(idS), n, s, std::stoi(aS), h);
                    p.status = st;
                    pets.push_back(p);
                } catch (...) { continue; }
            }
        }
        f.close();
    }

    bool addPet(int id, std::string n, std::string s, int a, std::string h) {
        load();
        for (auto& p : pets) if (p.id == id) return false;

        pets.push_back(Pet(id, n, s, a, h));
        DatabaseConnector::saveAll(pets);
        return true;
    }

    std::vector<Pet> getAllPets() {
        load();
        return pets;
    }
};

#endif // SHELTERLOGIC_H
