# OOP_Group12
# Pet Shelter Management System 

## Group Members:
- Fatih Kocaay  -21050111071
- Esra İlayda Günidi  -22050151037
- Arzu Bal  -23050151006
- Rümeysa Ayhan  23050151015

## Instructor and TAs:
- Instructor: Dr. Abdullah Bülbül (`mabdullahbulbul`)
- TA 1: Nisa Nur Mercimek (`nisanurmercimek`)
- TA 2: Cagin Ozkaya (`caginozkaya`)

## Description:
This repository contains the OOP Group 12 project: “Pet Shelter Management System”.
The goal of the project is to develop an object-oriented system for managing animals, adopters, and shelter operations efficiently.

## Project Structure

The project follows a modular design, separating data entities, business logic, and the user interface.

```text
PetShelterApp/
├── CMakeLists.txt              # Project build configuration
├── main.cpp                    # Application entry point
├── resources.qrc               # Resource file (Icons & Images)
│
├── src/                        # SOURCE CODE
│   │
│   ├── models/                 # Data Entities
│   │   └── Entities.h          # Data class definitions
│   │       ├── class Pet       # Pet attributes (ID, Name, Species, Age, Health)
│   │       ├── class Adopter   # Adopter details
│   │       └── class Staff     # Staff authentication details
│   │
│   ├── logic/                  # Business Logic & Services
│   │   ├── Services.h          # Main Service Manager
│   │   │   ├── class PetService        # Manages pet inventory (CRUD operations)
│   │   │   ├── class AdopterService    # Manages adopter records
│   │   │   ├── class AdoptionService   # Handles the adoption process logic
│   │   │   ├── class DatabaseConnector # File I/O operations (TXT database)
│   │   │   └── class Validator         # Input validation helpers
│   │   │
│   │   └── ShelterLogic.h      # Alternative Logic Layer
│   │
│   └── views/                  # User Interface (GUI)
│       ├── MainWindow          # Main Application Dashboard
│       │   ├── mainwindow.ui   # UI Design file (XML)
│       │   ├── mainwindow.h    # Main Window class header
│       │   └── mainwindow.cpp  # Main Window logic & signal-slots
│       │
│       └── Dialogs             # Pop-up Windows
│           ├── addpetdialog.h  # Add Pet Dialog header
│           └── addpetdialog.cpp# Add Pet Dialog logic
│
└── assets/                     # EXTERNAL ASSETS
    ├── images/                 # Visual Assets
    │   ├── login_icon.png      # Login screen icon
    │   └── dashboard_bg.jpg    # Dashboard background image
    │
    └── data/                   # File-Based Database
        ├── pets_db.txt         # Storage for pet records
        ├── adopters_db.txt     # Storage for adopter records
        └── shelter_db.txt      # General shelter data
```
## Project Presentation Video
-  https://drive.google.com/file/d/1DGZJn9hFwHZZhum5OyLnTmLRZ6xDJqzw/view?usp=sharing

## Contributions of The Group Members

---

### My Contributions (Esra İlayda Günindi - 22050151037)

In this repository, I focused on developing the core backend logic and designing custom user interface components using C++ and Qt6.

#### 1. Custom UI Components (addpetdialog.cpp)

Instead of relying solely on drag-and-drop tools, I implemented the Add Pet Dialog programmatically to achieve a specific design language:

Programmatic Layouts: Constructed dynamic interfaces using QVBoxLayout and QHBoxLayout for responsive positioning.  
Custom Styling: Applied CSS-like stylesheets directly within the C++ code to create a modern look (custom fonts, borders, and colors for inputs and buttons).  
Input Validation: Integrated QIntValidator to ensure data integrity for numeric fields like age.

#### 2. Core Logic (ShelterLogic.h)

Designed the ShelterLogic.h header to structure the fundamental business logic and operations required for the shelter management system.

#### 3. Resource Management (resources.qrc)

Configured the Qt Resource System to bundle application assets (icons and background images) directly into the executable, ensuring portability and correct path management.

#### 4. Design Fidelity & Architectural Alignment

I prioritized ensuring high fidelity between the implemented software and the conceptual interface schema outlined in the project report.

Schema Implementation: I meticulously translated the theoretical design diagrams from our group report into functional C++ code, ensuring the layout structure and visual hierarchy matched the agreed-upon specifications.  
Design Consistency: By manually coding the UI components, I achieved precise control over the interface, guaranteeing that the final application visually aligned with the team's proposed architectural model.

---

### My Contributions (Rümeysa Ayhan - 23050151015)

#### Project Overwiev

The project is implemented in C++ following object-oriented programming principles and a layered architecture based on the Entity–Service–Controller design. As a group project, the main graphical user interface (GUI) of the application was implemented using the Qt Framework.

For my individual development and testing process, I implemented and tested the Pet Management functionality on macOS using native dialog-based user interaction. This allowed me to verify the correctness of the backend logic independently from the main Qt interface.

#### Individual Responsibility

I was responsible – Pet Management Module.

#### Backend / Business Logic (PetService)

The following functionalities were implemented and tested by me:

Adding new pet records (addPet)  
Deleting pet records (deletePet)  
Updating pet health and adoption status (updatePet)  
Searching pets by name (searchPet)  
Listing all pets in the shelter inventory (getInventory)  
Ensuring data integrity and consistency  
File-based persistence of pet records  

These operations are part of the service layer and are independent from the GUI technology.

#### Development & Testing Environment  
#### Individual MacOs Implementation (Testing)

During my personal development process, I implemented and tested the Pet Management module on macOS.  
User interaction was provided via macOS native dialogs using AppleScript (osascript).

This implementation was used:  
For testing backend correctness  
To validate service-layer logic  
To demonstrate GUI-independent design  

**Note:**  
The macOS dialog-based interface was used only for individual development and testing purposes.  
The final project GUI remains Qt-based.

---

### My Contributions (Fatih Kocaay – 21050111071)

In this project, I primarily focused on GUI development and user interaction enhancements using C++ and the Qt Framework. My contributions aimed to improve usability, input safety, and overall user experience of the application.

#### GUI Development & User Interaction (Qt)

Actively worked on the graphical user interface (GUI) using Qt.  
Improved user interaction flow and usability across different screens.

#### Login Screen Improvements

Enhanced the login process by enabling keyboard interaction:

Added Enter key support in addition to mouse-based login.

Implemented visual feedback for invalid login attempts:

The login button changes color (red) when incorrect credentials are entered.

Improved user experience by preventing multiple simultaneous selections where applicable.

#### Input Validation & User Safety

Implemented strict input validation rules for form fields:

Restricted fields such as ID and Age to accept numeric input only.  
Prevented users from entering out-of-range values.  
Marked critical input fields as required and enforced mandatory completion before submission.  
Ensured that invalid or incomplete input cannot be processed by the system.

#### Table Interaction & Data Sorting

Improved usability of data tables by enabling column-based sorting:

Clicking on a column header (e.g., Name, ID) sorts the data accordingly.

---

### My Contributions (ARZU BAL -23050151006)

In this project, I was responsible for the **Infrastructure and Base Module**, which establishes the foundational structure of the Pet Shelter Management System. My work focused on preparing a stable, reusable, and well-organized base that other modules could build upon.

#### Backend / Logic Responsibilities

- Initialized the overall project structure and organized source files to support a clean and maintainable layered architecture.
- Uploaded, managed, and maintained the project repository on GitHub/GitLab to ensure proper version control and smooth collaborative development.
- Implemented the core entity classes: **Pet, Adopter, and Staff**, defining class headers, member variables, constructors, and essential getter/setter methods.
- Designed entity classes to be reusable and directly usable by the service and controller layers without modification.
- Developed the **DatabaseConnector** class to handle file-based input/output (File I/O) operations, ensuring reliable reading and writing of persistent data.
- Ensured consistent data formatting and safe data access across the system.
- Implemented the **Validator** class to perform numeric checks, empty input validation, and basic data consistency rules, improving overall system stability.

#### GUI Base Configuration (Windows Interface)

- Worked on the basic **Windows-based user interface configuration** of the application.
- Prepared shared visual and structural interface settings to ensure consistency across different application windows.
- Configured common interface elements to support user interaction without relying on external GUI frameworks.

#### Contribution Focus

My contributions focused on building a strong and reliable infrastructure layer, ensuring correct data handling and validation, and providing a stable foundation. This groundwork enabled other team members to efficiently implement higher-level service, controller, and user interaction functionalities.
