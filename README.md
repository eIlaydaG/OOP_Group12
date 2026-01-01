# OOP_Group12
# Pet Shelter Management System 

## Group Members:
- Fatih Kocaay  -21050111071
- Esra İlayda Günidi  -22050151037
- Arzu Bal  -230501506
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

## Contributions of The Group Members:

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

### 4. Design Fidelity & Architectural Alignment
I prioritized ensuring high fidelity between the implemented software and the **conceptual interface schema** outlined in the project report.
* **Schema Implementation:** I meticulously translated the theoretical design diagrams from our group report into functional C++ code, ensuring the layout structure and visual hierarchy matched the agreed-upon specifications.
* **Design Consistency:** By manually coding the UI components, I achieved precise control over the interface, guaranteeing that the final application visually aligned with the team's proposed architectural model.


## MY CONTRIBUTIONS (RÜMEYSA AYHAN - 23050151015) 
##  PROJECT OVERVIEW
The project is implemented in **C++** following **object-oriented programming principles** and a **layered architecture** based on the **Entity–Service–Controller** design.
As a group project, the **main graphical user interface (GUI) of the application was implemented using the Qt Framework**.

For my individual development and testing process, I implemented and tested the Pet Management functionality on **macOS** using **native dialog-based user interaction**. This allowed me to verify the correctness of the backend logic independently from the main Qt interface.


##  INDIVIDUAL RESPONSIBILITY
I was responsible – Pet Management Module.

### Backend / Business Logic (PetService)
The following functionalities were implemented and tested by me:

- Adding new pet records (`addPet`)
- Deleting pet records (`deletePet`)
- Updating pet health and adoption status (`updatePet`)
- Searching pets by name (`searchPet`)
- Listing all pets in the shelter inventory (`getInventory`)
- Ensuring data integrity and consistency
- File-based persistence of pet records

 
These operations are part of the service layer and are independent from the GUI technology.
##  DEVELOPMENT & TESTING ENVIRONMENT
### INDIVIDUAL MACOS IMPLEMENTATION (TESTING)
- During my personal development process, I implemented and tested the Pet Management module on **macOS**.
- User interaction was provided via **macOS native dialogs** using **AppleScript (osascript)**.
- This implementation was used:
  - For testing backend correctness
  - To validate service-layer logic
  - To demonstrate GUI-independent design
 

**Note:**  
The macOS dialog-based interface was used **only for individual development and testing purposes**.  
The final project GUI remains **Qt-based**.


## MY CONTRIBUTIONS (Fatih Kocaay – 21050111071)

In this project, I primarily focused on **GUI development and user interaction enhancements** using **C++ and the Qt Framework**. My contributions aimed to improve usability, input safety, and overall user experience of the application.

## GUI Development & User Interaction (Qt)

- Actively worked on the **graphical user interface (GUI)** using Qt.

- Improved user interaction flow and usability across different screens.

## Login Screen Improvements

- Enhanced the login process by enabling **keyboard interaction**:

- Added **Enter key support** in addition to mouse-based login.

- Implemented **visual feedback for invalid login attempts**:

- The login button changes color (red) when incorrect credentials are entered.

- Improved user experience by preventing **multiple simultaneous selections** where applicable.

## Input Validation & User Safety

- Implemented strict **input validation rules** for form fields:

- Restricted fields such as **ID** and **Age** to accept **numeric input only**.

- Prevented users from entering **out-of-range values**.

- Marked critical input fields as **required** and enforced mandatory completion before submission.

- Ensured that invalid or incomplete input cannot be processed by the system.

## Table Interaction & Data Sorting

- Improved usability of data tables by enabling **column-based sorting**:

- Clicking on a column header (e.g., **Name, ID**) sorts the data accordingly.



## MY CONTRIBUTIONS (ARZU BAL -23050151006)

In this project, I was responsible for the **Infrastructure and Base Module**, which establishes the foundational structure of the Pet Shelter Management System. My role focused on setting up the core backend components, data management utilities, and basic user interface configuration that other modules depend on.

Backend / Logic Responsibilities

Project Initialization  
- Initialized the project structure and organized source files to support a clean and maintainable layered architecture.  
- Uploaded and maintained the project on the GitHub/GitLab repository to support collaborative development and version control.

Entity Class Implementation  
- Implemented the core entity classes: `Pet`, `Adopter`, and `Staff`.  
- Defined class header files, member variables, constructors, and essential getter and setter methods.  
- Ensured that entity classes were reusable and could be directly utilized by service and controller layers.

Database Management  
- Developed the `DatabaseConnector` class to manage **file-based input/output (File I/O)** operations.  
- Implemented general-purpose functions for reading data from files and writing updated records back to persistent storage.  
- Ensured consistent data formatting and reliable data access across the system.

Input Validation  
- Implemented the `Validator` class to validate user inputs.  
- Added checks for numeric values, empty inputs, and basic data consistency rules.  
- Improved system stability by preventing invalid or malformed input from being processed.

GUI Base Configuration (Windows Interface)

- Worked on the basic **Windows-based user interface configuration** of the application.  
- Prepared shared visual and structural settings for the interface to ensure consistency across application windows.  
- Configured common interface elements to support user interaction without relying on external GUI frameworks.

Contribution Focus

My contributions focused on building a solid infrastructure layer, ensuring correct data handling and validation, and preparing a stable Windows-based interface foundation. This work enabled other team members to develop higher-level service, controller, and user interaction functionalities efficiently.


- Alphabetical sorting for text fields (e.g., Name).

- Numerical sorting for numeric fields (e.g., ID, Age).

- This feature was implemented to allow users to navigate large data sets more easily.

## Contribution Focus

My contributions were centered on creating a **user-friendly, robust, and responsive GUI**, ensuring that user input is validated correctly and interactions are intuitive, safe, and visually clear.



