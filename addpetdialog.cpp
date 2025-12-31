#include "addpetdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIntValidator>

AddPetDialog::AddPetDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Add New Pet");
    setModal(true);
    resize(600, 450);
    setupUI();
}

void AddPetDialog::setupUI() {
    // --- STYLE ---
    setStyleSheet(R"(
        QDialog { background-color: #F4F7F6; }
        QLabel { font-family: 'Segoe UI'; font-size: 14px; font-weight: bold; color: #455A64; margin-bottom: 2px; }
        QLineEdit { background-color: #FFFFFF; border: 1px solid #CFD8DC; border-radius: 8px; padding: 10px; font-size: 14px; color: #263238; }
        QLineEdit:focus { border: 2px solid #4DB6AC; background-color: #FFFFFF; }
        QPushButton { background-color: #009688; color: white; border-radius: 22px; font-size: 16px; font-weight: bold; padding: 12px; margin-top: 10px; }
        QPushButton:hover { background-color: #26A69A; }
    )");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 30, 40, 40);
    mainLayout->setSpacing(20);

    // --- TITlE ---
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *iconLabel = new QLabel("🐾");
    iconLabel->setStyleSheet("font-size: 40px;");
    QLabel *titleLabel = new QLabel("Add New Pet");
    titleLabel->setStyleSheet("font-size: 26px; font-weight: 800; color: #263238; margin-left: 10px;");
    headerLayout->addWidget(iconLabel);
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // --- FORM ---
    QHBoxLayout *formContainer = new QHBoxLayout();
    formContainer->setSpacing(40);

    QVBoxLayout *leftColumn = new QVBoxLayout(); leftColumn->setSpacing(15);
    QVBoxLayout *rightColumn = new QVBoxLayout(); rightColumn->setSpacing(15);

    txtName = new QLineEdit(); txtName->setPlaceholderText("Pet Name");
    txtSpecies = new QLineEdit(); txtSpecies->setPlaceholderText("Dog, Cat...");
    txtAge = new QLineEdit(); txtAge->setPlaceholderText("Age");
    txtAge->setValidator(new QIntValidator(0, 50, this));
    txtHealth = new QLineEdit(); txtHealth->setPlaceholderText("Healthy, Injured...");

    // LEFT COLUMN
    leftColumn->addWidget(new QLabel("Name"));
    leftColumn->addWidget(txtName);
    leftColumn->addWidget(new QLabel("Species"));
    leftColumn->addWidget(txtSpecies);
    leftColumn->addStretch();

    // RIGHT COLUMN
    rightColumn->addWidget(new QLabel("Age"));
    rightColumn->addWidget(txtAge);
    rightColumn->addWidget(new QLabel("Health Status"));
    rightColumn->addWidget(txtHealth);
    rightColumn->addStretch();

    formContainer->addLayout(leftColumn);
    formContainer->addLayout(rightColumn);
    mainLayout->addLayout(formContainer);

    mainLayout->addStretch();

    // --- SAVE BUTTON ---
    QPushButton *btnSave = new QPushButton("Save Pet");
    btnSave->setCursor(Qt::PointingHandCursor);
    connect(btnSave, &QPushButton::clicked, this, &QDialog::accept);

    mainLayout->addWidget(btnSave);
}

// --- GETTER METODS ---
QString AddPetDialog::getName() const { return txtName->text(); }
QString AddPetDialog::getSpecies() const { return txtSpecies->text(); }
int AddPetDialog::getAge() const { return txtAge->text().toInt(); }
QString AddPetDialog::getHealth() const { return txtHealth->text(); }
