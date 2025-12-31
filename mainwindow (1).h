#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Services.h"
#include "addpetdialog.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QComboBox>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Login
    void onLoginClicked();
    void onLogoutClicked();

    // Dashboard
    void onDashboardAddPetClicked();

    // Pet Management Tab Slots
    void onAddPetClicked();
    void onDeletePetClicked();
    void onUpdatePetClicked();
    void onPetSearchChanged(const QString &text);
    void onPetTableClicked(int row, int col);

    // Adopter Management Tab Slots
    void onAddAdopterClicked();
    void onDeleteAdopterClicked();
    void onUpdateAdopterClicked();
    void onAdopterSearchChanged(const QString &text);
    void onAdopterTableClicked(int row, int col);

    // Adoption Tab Slots
    void onAdoptClicked();
    void refreshAdoptionTab();

private:
    PetService petService;
    AdopterService adopterService;
    AdoptionService adoptionService;

    QStackedWidget *stackedWidget;

    // --- PAGE 1: LOGIN ---
    QLineEdit *txtUsername;
    QLineEdit *txtPassword;

    // --- PAGE 2: DASHBOARD ---
    QTabWidget *mainTabs;
    QWidget *homeTab;

    // Dashboard Buttons
    QPushButton *btnDashPets;
    QPushButton *btnDashAddPet;
    QPushButton *btnDashAdopters;
    QPushButton *btnDashStats;

    void setupUI();
    void setupLoginScreen(QWidget *parent);
    void setupDashboard(QWidget *parent);
    void setupHomeTab();

    // Pet UI Elements
    QLineEdit *txtPetId, *txtPetName, *txtPetSpecies, *txtPetAge, *txtPetHealth, *txtPetSearch;
    QTableWidget *tblPets;

    // Adopter UI Elements
    QLineEdit *txtAdopterId, *txtAdopterName, *txtAdopterPhone, *txtAdopterAddress, *txtAdopterSearch;
    QTableWidget *tblAdopters;

    // Adoption UI Elements
    QComboBox *cmbAvailablePets;
    QComboBox *cmbAdopters;

    // Auxiliary Functions
    void refreshPetList(QString query = "");
    void refreshAdopterList(QString query = "");
};
#endif // MAINWINDOW_H
