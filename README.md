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


MY CONTRIBUTIONS (Fatih Kocaay – 21050111071)

In this project, I primarily focused on GUI development and user interaction enhancements using C++ and the Qt Framework. My contributions aimed to improve usability, input safety, and overall user experience of the application.

GUI Development & User Interaction (Qt)

Actively worked on the graphical user interface (GUI) using Qt.

Improved user interaction flow and usability across different screens.

Login Screen Improvements

Enhanced the login process by enabling keyboard interaction:

Added Enter key support in addition to mouse-based login.

Implemented visual feedback for invalid login attempts:

The login button changes color (red) when incorrect credentials are entered.

Improved user experience by preventing multiple simultaneous selections where applicable.

Input Validation & User Safety

Implemented strict input validation rules for form fields:

Restricted fields such as ID and Age to accept numeric input only.

Prevented users from entering out-of-range values.

Marked critical input fields as required and enforced mandatory completion before submission.

Ensured that invalid or incomplete input cannot be processed by the system.

Table Interaction & Data Sorting

Improved usability of data tables by enabling column-based sorting:

Clicking on a column header (e.g., Name, ID) sorts the data accordingly.

Alphabetical sorting for text fields (e.g., Name).

Numerical sorting for numeric fields (e.g., ID, Age).

This feature was implemented to allow users to navigate large data sets more easily.

Contribution Focus

My contributions were centered on creating a user-friendly, robust, and responsive GUI, ensuring that user input is validated correctly and interactions are intuitive, safe, and visually clear.






