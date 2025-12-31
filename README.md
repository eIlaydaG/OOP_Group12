# OOP_Group12
# OOP Group 12 – Pet Shelter Management System 

### Group Members:
- Fatih Kocaay  -21050111071
- Esra İlayda Günidi  -22050151037
- Arzu Bal  -230501506
- Rümeysa Ayhan  23050151015

### Instructor and TAs:
- Instructor: Dr. Abdullah Bülbül (`mabdullahbulbul`)
- TA 1: Nisa Nur Mercimek (`nisanurmercimek`)
- TA 2: Cagin Ozkaya (`caginozkaya`)

### Description:
This repository contains the OOP Group 12 project: “Pet Shelter Management System”.
The goal of the project is to develop an object-oriented system for managing animals, adopters, and shelter operations efficiently.

## My Contributions (Esra İlayda Günindi - 22050151037)

In this repository, I focused on developing the core backend logic and designing custom user interface components using C++ and Qt6.

### 1. Custom UI Components (`addpetdialog.cpp`)
Instead of relying solely on drag-and-drop tools, I implemented the **Add Pet Dialog** programmatically to achieve a specific design language:
* **Programmatic Layouts:** Constructed dynamic interfaces using `QVBoxLayout` and `QHBoxLayout` for responsive positioning.
* **Custom Styling:** Applied CSS-like stylesheets directly within the C++ code to create a modern look (custom fonts, borders, and colors for inputs and buttons).
* **Input Validation:** Integrated `QIntValidator` to ensure data integrity for numeric fields like age.

### 2. Core Logic (`ShelterLogic.h`)
* Designed the `ShelterLogic.h` header to structure the fundamental business logic and operations required for the shelter management system.

### 3. Resource Management (`resources.qrc`)
* Configured the Qt Resource System to bundle application assets (icons and background images) directly into the executable, ensuring portability and correct path management.
