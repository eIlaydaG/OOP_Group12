#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout> // Grid layout için
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();

    // ================= DESIGN (CSS) =================
    QString styleSheet = R"(
        QMainWindow { background-color: #F0F2F5; }
        QWidget { font-family: 'Segoe UI', sans-serif; font-size: 14px; color: #263238; }

        /* LOGIN CARD */
        QFrame#loginCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }

        /* INPUTS */
        QLineEdit { background-color: #FAFAFA; border: 1px solid #CFD8DC; border-radius: 22px; padding: 0 20px; color: #455A64; }
        QLineEdit:focus { border: 2px solid #4DB6AC; background-color: #FFFFFF; }
        QLineEdit[error="true"] { border: 2px solid #EF5350; background-color: #FFEBEE; }

        /* BUTTONS */
        QPushButton#loginBtn { background-color: #4DB6AC; color: white; border-radius: 25px; font-weight: bold; border: none; }
        QPushButton#loginBtn:hover { background-color: #26A69A; }
        QPushButton#loginBtn:disabled { background-color: #B2DFDB; color: #E0F2F1; }

        QPushButton { border-radius: 8px; }

        /* DASHBOARD CARDS */
        QPushButton#cardBlue { background-color: #448AFF; color: white; border: none; border-radius: 15px; font-size: 18px; font-weight: bold; }
        QPushButton#cardGreen { background-color: #26A69A; color: white; border: none; border-radius: 15px; font-size: 18px; font-weight: bold; }
        QPushButton#cardTeal { background-color: #4DB6AC; color: white; border: none; border-radius: 15px; font-size: 18px; font-weight: bold; }
        QPushButton#cardYellow { background-color: #FBC02D; color: white; border: none; border-radius: 15px; font-size: 18px; font-weight: bold; }

        QPushButton#cardBlue:hover { margin-top: -5px; padding-bottom: 5px; }
        QPushButton#cardGreen:hover { margin-top: -5px; padding-bottom: 5px; }
        QPushButton#cardTeal:hover { margin-top: -5px; padding-bottom: 5px; }
        QPushButton#cardYellow:hover { margin-top: -5px; padding-bottom: 5px; }

        /* HEADER */
        QWidget#headerWidget { background-color: #FFFFFF; border-bottom: 1px solid #E0E0E0; }
        QLabel#headerTitle { font-size: 28px; font-weight: bold; color: #37474F; }
        QLabel#headerSubTitle { font-size: 14px; color: #90A4AE; }

        /* TABS */
        QTabWidget::pane { border: none; }
        QTabBar::tab { background: #ECEFF1; color: #546E7A; padding: 10px 20px; margin-right: 2px; border-top-left-radius: 8px; border-top-right-radius: 8px; font-weight: bold; }
        QTabBar::tab:selected { background: #FFFFFF; color: #263238; border-bottom: 2px solid #4DB6AC; }
    )";
    setStyleSheet(styleSheet);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);

    stackedWidget = new QStackedWidget();
    mainLayout->addWidget(stackedWidget);

    // Page 1: Login
    QWidget *loginPage = new QWidget();
    setupLoginScreen(loginPage);
    stackedWidget->addWidget(loginPage);

    // Page 2: Dashboard
    QWidget *dashboardPage = new QWidget();
    setupDashboard(dashboardPage);
    stackedWidget->addWidget(dashboardPage);

    stackedWidget->setCurrentIndex(0);
}

void MainWindow::setupLoginScreen(QWidget *page) {
    QVBoxLayout *mainLayout = new QVBoxLayout(page);
    mainLayout->setAlignment(Qt::AlignCenter);

    QFrame *loginCard = new QFrame();
    loginCard->setObjectName("loginCard");
    loginCard->setFixedWidth(400);

    QVBoxLayout *cardLayout = new QVBoxLayout(loginCard);
    cardLayout->setSpacing(15);
    cardLayout->setContentsMargins(40, 40, 40, 40);

    QLabel *lblIcon = new QLabel();
    lblIcon->setAlignment(Qt::AlignCenter);
    QPixmap pix(":/login_icon.png");
    if(!pix.isNull()){
        lblIcon->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        lblIcon->setText("🐾");
        lblIcon->setStyleSheet("font-size: 50px;");
    }

    QLabel *lblTitle = new QLabel("PET SHELTER LOGIN");
    lblTitle->setAlignment(Qt::AlignCenter);
    lblTitle->setStyleSheet("font-size: 22px; font-weight: bold; color: #37474F; margin-bottom: 10px;");

    QLabel *lblUser = new QLabel("Username");
    txtUsername = new QLineEdit();
    txtUsername->setPlaceholderText("Enter your username");
    txtUsername->setFixedHeight(45);

    QLabel *lblPass = new QLabel("Password");
    txtPassword = new QLineEdit();
    txtPassword->setPlaceholderText("Enter your password");
    txtPassword->setEchoMode(QLineEdit::Password);
    txtPassword->setFixedHeight(45);

    QPushButton *btnLogin = new QPushButton("Login");
    btnLogin->setObjectName("loginBtn");
    btnLogin->setCursor(Qt::PointingHandCursor);
    btnLogin->setFixedHeight(50);
    btnLogin->setEnabled(false);

    cardLayout->addWidget(lblIcon);
    cardLayout->addWidget(lblTitle);
    cardLayout->addWidget(lblUser);
    cardLayout->addWidget(txtUsername);
    cardLayout->addWidget(lblPass);
    cardLayout->addWidget(txtPassword);
    cardLayout->addSpacing(20);
    cardLayout->addWidget(btnLogin);

    mainLayout->addWidget(loginCard);

    connect(txtUsername, &QLineEdit::textChanged, this, [=]() {
        btnLogin->setEnabled(!txtUsername->text().trimmed().isEmpty() && !txtPassword->text().trimmed().isEmpty());
    });
    connect(txtPassword, &QLineEdit::textChanged, this, [=]() {
        btnLogin->setEnabled(!txtUsername->text().trimmed().isEmpty() && !txtPassword->text().trimmed().isEmpty());
    });
    connect(txtPassword, &QLineEdit::returnPressed, this, &MainWindow::onLoginClicked);
    connect(btnLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
}

void MainWindow::onLoginClicked()
{

    QString user = txtUsername->text();
    QString pass = txtPassword->text();


    if (user == "Group12" && pass == "esarrüfa1234") {

        // Successful login process...
        txtUsername->setProperty("error", false);
        txtPassword->setProperty("error", false);
        txtUsername->style()->polish(txtUsername);
        txtPassword->style()->polish(txtPassword);

        stackedWidget->setCurrentIndex(1);
        refreshPetList();
        refreshAdopterList();
        txtPassword->clear();
    }
    else {
        // Incorrect login procedures...
        txtUsername->setProperty("error", true);
        txtPassword->setProperty("error", true);
        txtUsername->style()->polish(txtUsername);
        txtPassword->style()->polish(txtPassword);

        QMessageBox::warning(
            this,
            "Login Failed",
            "Username or password is wrong, try again."
            );

        txtPassword->clear();
        txtPassword->setFocus();
    }
}

void MainWindow::setupDashboard(QWidget *page) {
    QVBoxLayout *layout = new QVBoxLayout(page);
    layout->setContentsMargins(0, 0, 0, 0);

    // Header
    QWidget *headerWidget = new QWidget();
    headerWidget->setObjectName("headerWidget");
    headerWidget->setFixedHeight(70);
    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(30, 0, 30, 0);

    QLabel *title = new QLabel("Dashboard");
    title->setObjectName("headerTitle");
    QLabel *welcomeObj = new QLabel("Welcome, Staff Member");
    welcomeObj->setObjectName("headerSubTitle");
    QPushButton *btnLogout = new QPushButton("Logout");
    btnLogout->setFixedWidth(100);
    connect(btnLogout, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);

    headerLayout->addWidget(title);
    headerLayout->addStretch();
    headerLayout->addWidget(welcomeObj);
    headerLayout->addSpacing(20);
    headerLayout->addWidget(btnLogout);
    layout->addWidget(headerWidget);

    // Tabs
    mainTabs = new QTabWidget();
    layout->addWidget(mainTabs);

    // TAB 1: HOME
    setupHomeTab();
    mainTabs->addTab(homeTab, "🏠 Dashboard");

    // TAB 2: PET MANAGEMENT
    QWidget *petTab = new QWidget();
    QVBoxLayout *petLayout = new QVBoxLayout(petTab);

    txtPetSearch = new QLineEdit();
    txtPetSearch->setPlaceholderText("🔍 Search Pets by Name...");
    connect(txtPetSearch, &QLineEdit::textChanged, this, &MainWindow::onPetSearchChanged);
    petLayout->addWidget(txtPetSearch);

    QHBoxLayout *petForm = new QHBoxLayout();
    txtPetName = new QLineEdit(); txtPetName->setPlaceholderText("Name");
    txtPetSpecies = new QLineEdit(); txtPetSpecies->setPlaceholderText("Species");
    txtPetAge = new QLineEdit(); txtPetAge->setPlaceholderText("Age"); txtPetAge->setFixedWidth(70);
    txtPetHealth = new QLineEdit(); txtPetHealth->setPlaceholderText("Health");

    txtPetAge->setValidator(new QIntValidator(0, 40, this));

    petForm->addWidget(txtPetName);
    petForm->addWidget(txtPetSpecies);
    petForm->addWidget(txtPetAge);
    petForm->addWidget(txtPetHealth);
    petLayout->addLayout(petForm);

    QHBoxLayout *petBtns = new QHBoxLayout();
    QPushButton *btnAddPet = new QPushButton("Add");
    QPushButton *btnUpdatePet = new QPushButton("Update");
    QPushButton *btnDelPet = new QPushButton("Delete");

    petBtns->addWidget(btnAddPet); petBtns->addWidget(btnUpdatePet); petBtns->addWidget(btnDelPet);
    petLayout->addLayout(petBtns);

    tblPets = new QTableWidget();
    tblPets->setColumnCount(6);
    tblPets->setHorizontalHeaderLabels({"ID", "Name", "Species", "Age", "Health", "Condition"});
    tblPets->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tblPets->setSelectionBehavior(QAbstractItemView::SelectRows);
    tblPets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tblPets->setSelectionMode(QAbstractItemView::SingleSelection);
    tblPets->verticalHeader()->setVisible(false);
    petLayout->addWidget(tblPets);

    connect(btnAddPet, &QPushButton::clicked, this, &MainWindow::onAddPetClicked);
    connect(btnUpdatePet, &QPushButton::clicked, this, &MainWindow::onUpdatePetClicked);
    connect(btnDelPet, &QPushButton::clicked, this, &MainWindow::onDeletePetClicked);
    connect(tblPets, &QTableWidget::cellClicked, this, &MainWindow::onPetTableClicked);

    mainTabs->addTab(petTab, "🐕 Pet Management");

    // TAB 3: ADOPTER MANAGEMENT
    QWidget *adopterTab = new QWidget();
    QVBoxLayout *adopterLayout = new QVBoxLayout(adopterTab);

    txtAdopterSearch = new QLineEdit();
    txtAdopterSearch->setPlaceholderText("🔍 Search Adopters...");
    connect(txtAdopterSearch, &QLineEdit::textChanged, this, &MainWindow::onAdopterSearchChanged);
    adopterLayout->addWidget(txtAdopterSearch);

    QHBoxLayout *adopterForm = new QHBoxLayout();
    txtAdopterId = new QLineEdit(); txtAdopterId->setPlaceholderText("ID"); txtAdopterId->setFixedWidth(60);
    txtAdopterName = new QLineEdit(); txtAdopterName->setPlaceholderText("Full Name");
    txtAdopterPhone = new QLineEdit(); txtAdopterPhone->setPlaceholderText("Phone");
    txtAdopterAddress = new QLineEdit(); txtAdopterAddress->setPlaceholderText("Address");
    txtAdopterId->setValidator(new QIntValidator(1, 9999, this));

    adopterForm->addWidget(txtAdopterId); adopterForm->addWidget(txtAdopterName);
    adopterForm->addWidget(txtAdopterPhone); adopterForm->addWidget(txtAdopterAddress);
    adopterLayout->addLayout(adopterForm);

    QHBoxLayout *adopterBtns = new QHBoxLayout();
    QPushButton *btnAddAdopter = new QPushButton("Add");
    QPushButton *btnUpdateAdopter = new QPushButton("Update");
    QPushButton *btnDelAdopter = new QPushButton("Delete");

    adopterBtns->addWidget(btnAddAdopter); adopterBtns->addWidget(btnUpdateAdopter); adopterBtns->addWidget(btnDelAdopter);
    adopterLayout->addLayout(adopterBtns);

    tblAdopters = new QTableWidget();
    tblAdopters->setColumnCount(4);
    tblAdopters->setHorizontalHeaderLabels({"ID", "Full Name", "Phone", "Address"});
    tblAdopters->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tblAdopters->setSelectionBehavior(QAbstractItemView::SelectRows);
    tblAdopters->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tblAdopters->setSelectionMode(QAbstractItemView::SingleSelection);
    tblAdopters->verticalHeader()->setVisible(false);
    adopterLayout->addWidget(tblAdopters);

    connect(btnAddAdopter, &QPushButton::clicked, this, &MainWindow::onAddAdopterClicked);
    connect(btnUpdateAdopter, &QPushButton::clicked, this, &MainWindow::onUpdateAdopterClicked);
    connect(btnDelAdopter, &QPushButton::clicked, this, &MainWindow::onDeleteAdopterClicked);
    connect(tblAdopters, &QTableWidget::cellClicked, this, &MainWindow::onAdopterTableClicked);

    mainTabs->addTab(adopterTab, "👤 Adopter Management");

    // TAB 4: ADOPTION
    QWidget *adoptTab = new QWidget();
    QVBoxLayout *adoptLayout = new QVBoxLayout(adoptTab);
    adoptLayout->addWidget(new QLabel("Select Available Pet:"));
    cmbAvailablePets = new QComboBox();
    adoptLayout->addWidget(cmbAvailablePets);
    adoptLayout->addWidget(new QLabel("Select Adopter:"));
    cmbAdopters = new QComboBox();
    adoptLayout->addWidget(cmbAdopters);
    QPushButton *btnDoAdopt = new QPushButton("Complete Adoption");
    adoptLayout->addWidget(btnDoAdopt);
    adoptLayout->addStretch();

    connect(btnDoAdopt, &QPushButton::clicked, this, &MainWindow::onAdoptClicked);
    connect(mainTabs, &QTabWidget::currentChanged, this, [this](int index){
        if(index == 3) refreshAdoptionTab();
    });
    mainTabs->addTab(adoptTab, "🤝 Adoption Process");
}

// --- DASHBOARD (HOME) LOGIC ---
void MainWindow::setupHomeTab() {
    homeTab = new QWidget();
    QVBoxLayout *homeLayout = new QVBoxLayout(homeTab);
    homeLayout->setContentsMargins(40, 40, 40, 40);
    homeLayout->setSpacing(20);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(20);

    // 1. Pets Button
    btnDashPets = new QPushButton("🐾\nPets");
    btnDashPets->setObjectName("cardBlue");
    btnDashPets->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnDashPets->setMinimumHeight(120);
    connect(btnDashPets, &QPushButton::clicked, this, [this](){ mainTabs->setCurrentIndex(1); });

    // 2. Add Pet Button
    btnDashAddPet = new QPushButton("+\nAdd Pet");
    btnDashAddPet->setObjectName("cardGreen");
    btnDashAddPet->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnDashAddPet->setMinimumHeight(120);
    connect(btnDashAddPet, &QPushButton::clicked, this, &MainWindow::onDashboardAddPetClicked);

    // 3. Adopters Button
    btnDashAdopters = new QPushButton("👤\nAdopters");
    btnDashAdopters->setObjectName("cardTeal");
    btnDashAdopters->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnDashAdopters->setMinimumHeight(120);
    connect(btnDashAdopters, &QPushButton::clicked, this, [this](){ mainTabs->setCurrentIndex(2); });

    // 4. Adopt Button
    btnDashStats = new QPushButton("🤝\nAdopt");
    btnDashStats->setObjectName("cardYellow");
    btnDashStats->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnDashStats->setMinimumHeight(120);
    connect(btnDashStats, &QPushButton::clicked, this, [this](){ mainTabs->setCurrentIndex(3); });

    gridLayout->addWidget(btnDashPets, 0, 0);
    gridLayout->addWidget(btnDashAddPet, 0, 1);
    gridLayout->addWidget(btnDashAdopters, 0, 2);
    gridLayout->addWidget(btnDashStats, 0, 3);
    homeLayout->addLayout(gridLayout);

    QLabel *lblWelcome = new QLabel("Welcome to the Pet Shelter Management System!");
    lblWelcome->setAlignment(Qt::AlignCenter);
    lblWelcome->setStyleSheet("font-size: 24px; color: #546E7A; margin-top: 30px; font-weight: bold;");
    homeLayout->addWidget(lblWelcome);

    QLabel *lblImage = new QLabel();
    lblImage->setAlignment(Qt::AlignCenter);
    QPixmap dashboardPix(":/dashboard_bg.jpg");
    if (!dashboardPix.isNull()) {
        lblImage->setPixmap(dashboardPix.scaled(900, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        lblImage->setText("Dashboard Image");
    }
    homeLayout->addWidget(lblImage);
    homeLayout->addStretch();
}

void MainWindow::onDashboardAddPetClicked() {
    AddPetDialog dlg(this);

    if (dlg.exec() == QDialog::Accepted) {

        if(dlg.getName().isEmpty()) {
            QMessageBox::warning(this, "Warning", "Name is required!");
            return;
        }

        // --- ID'yi ARTIK DIALOGDAN DEĞİL, SİSTEMDEN ALIYORUZ ---
        // (Bunun çalışması için Services.h içine generateId eklemiş olmalısın)
        int autoId = petService.generateId();

        // Veriyi ekle
        bool success = petService.addPet(
            autoId,              // <-- Otomatik ID buraya geliyor
            dlg.getName(),
            dlg.getSpecies(),
            dlg.getAge(),
            dlg.getHealth()
            );

        if(success) {
            QMessageBox::information(this, "Success", "Pet Added Successfully!");
            refreshPetList();
        }
    }
}

void MainWindow::onLogoutClicked() {
    stackedWidget->setCurrentIndex(0);
    txtPassword->clear();
    txtUsername->clear();
    txtUsername->setFocus();
}

// ================= PET LOGIC =================

void MainWindow::refreshPetList(QString query) {
    tblPets->setRowCount(0);
    auto pets = petService.getAllPets();

    for(const auto& p : pets) {
        if(!query.isEmpty() && !p.name.contains(query, Qt::CaseInsensitive)) continue;

        int row = tblPets->rowCount();
        tblPets->insertRow(row);

        tblPets->setItem(row, 0, new QTableWidgetItem(QString::number(p.id)));
        tblPets->setItem(row, 1, new QTableWidgetItem(p.name));
        tblPets->setItem(row, 2, new QTableWidgetItem(p.species));
        tblPets->setItem(row, 3, new QTableWidgetItem(QString::number(p.age)));
        tblPets->setItem(row, 4, new QTableWidgetItem(p.health));


        QString displayCondition;
        QColor conditionColor;

        QString cleanStatus = p.status.trimmed().toLower();
        QString cleanHealth = p.health.trimmed().toLower();

        // Rule 1: If dead
        if (cleanHealth == "dead") {
            displayCondition = "Passed Away";
            conditionColor = QColor("#D32F2F"); // Red
        }
        // Rule 2: If 'available' OR 'no injury'
        else if (cleanStatus == "available" || cleanStatus == "no injury") {
            displayCondition = p.status;
            conditionColor = QColor("#2E7D32"); // Green
        }
        // Rule 3: Others
        else {
            displayCondition = p.status;
            conditionColor = QColor("#C62828"); // Red
        }

        QTableWidgetItem *statusItem = new QTableWidgetItem(displayCondition);
        statusItem->setForeground(QBrush(conditionColor));
        statusItem->setFont(QFont("Helvetica Neue", 13, QFont::Bold));

        tblPets->setItem(row, 5, statusItem);
    }
}

void MainWindow::onAddPetClicked() {
    if(txtPetId->text().isEmpty() || txtPetName->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "ID and Name required!"); return;
    }

    petService.addPet(txtPetId->text().toInt(), txtPetName->text(), txtPetSpecies->text(),
                      txtPetAge->text().toInt(), txtPetHealth->text());
    refreshPetList();
    QMessageBox::information(this, "Success", "Pet Added!");
    txtPetId->clear(); txtPetName->clear(); txtPetSpecies->clear();
    txtPetAge->clear(); txtPetHealth->clear();
}

void MainWindow::onDeletePetClicked() {
    int row = tblPets->currentRow();
    if(row < 0) { QMessageBox::warning(this, "Select", "Please select a pet to delete."); return; }
    int id = tblPets->item(row, 0)->text().toInt();
    if (QMessageBox::question(this, "Confirm", "Delete this pet?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        if(petService.deletePet(id)) {
            refreshPetList();
            QMessageBox::information(this, "Deleted", "Pet record deleted.");
        }
    }
}

void MainWindow::onUpdatePetClicked() {
    // 1. Tablodan seçim yapılmış mı kontrol et
    int row = tblPets->currentRow();
    if(row < 0) {
        QMessageBox::warning(this, "Select", "Please select a pet from the list to update.");
        return;
    }

    // 2. ID'yi tablodaki seçili satırdan al (Gizli kahraman burası)
    int id = tblPets->item(row, 0)->text().toInt();

    // 3. Güncelleme işlemini yap
    bool success = petService.updatePet(
        id,
        txtPetName->text(),
        txtPetSpecies->text(),
        txtPetAge->text().toInt(),
        txtPetHealth->text()
        );

    if(success) {
        refreshPetList();
        QMessageBox::information(this, "Updated", "Pet details updated.");
    } else {
        QMessageBox::warning(this, "Error", "Update failed.");
    }
}

void MainWindow::onPetSearchChanged(const QString &text) { refreshPetList(text); }
void MainWindow::onPetTableClicked(int row, int col) {
    txtPetName->setText(tblPets->item(row, 1)->text());
    txtPetSpecies->setText(tblPets->item(row, 2)->text());
    txtPetAge->setText(tblPets->item(row, 3)->text());
    txtPetHealth->setText(tblPets->item(row, 4)->text());
}

// ================= ADOPTER LOGIC =================
void MainWindow::refreshAdopterList(QString query) {
    tblAdopters->setRowCount(0);
    auto adopters = adopterService.getAllAdopters();
    for(const auto& a : adopters) {
        if(!query.isEmpty() && !a.fullName.contains(query, Qt::CaseInsensitive)) continue;
        int row = tblAdopters->rowCount();
        tblAdopters->insertRow(row);
        tblAdopters->setItem(row, 0, new QTableWidgetItem(QString::number(a.id)));
        tblAdopters->setItem(row, 1, new QTableWidgetItem(a.fullName));
        tblAdopters->setItem(row, 2, new QTableWidgetItem(a.phone));
        tblAdopters->setItem(row, 3, new QTableWidgetItem(a.address));
    }
}

void MainWindow::onAddAdopterClicked() {
    if(txtAdopterId->text().isEmpty() || txtAdopterName->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "ID and Name required!"); return;
    }
    if(adopterService.addAdopter(txtAdopterId->text().toInt(), txtAdopterName->text(),
                                  txtAdopterPhone->text(), txtAdopterAddress->text())) {
        refreshAdopterList();
        QMessageBox::information(this, "Success", "Adopter Registered!");
        txtAdopterId->clear(); txtAdopterName->clear(); txtAdopterPhone->clear(); txtAdopterAddress->clear();
    } else {
        QMessageBox::critical(this, "Error", "ID already exists!");
    }
}

void MainWindow::onDeleteAdopterClicked() {
    int row = tblAdopters->currentRow();
    if(row < 0) { QMessageBox::warning(this, "Select", "Please select an adopter to delete."); return; }
    int id = tblAdopters->item(row, 0)->text().toInt();
    if (QMessageBox::question(this, "Confirm", "Delete this adopter?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        if(adopterService.deleteAdopter(id)) {
            refreshAdopterList();
            QMessageBox::information(this, "Deleted", "Adopter removed.");
        }
    }
}

void MainWindow::onUpdateAdopterClicked() {
    if(txtAdopterId->text().isEmpty()) return;
    if(adopterService.updateAdopter(txtAdopterId->text().toInt(), txtAdopterName->text(),
                                     txtAdopterPhone->text(), txtAdopterAddress->text())) {
        refreshAdopterList();
        QMessageBox::information(this, "Updated", "Adopter info updated.");
    }
}

void MainWindow::onAdopterSearchChanged(const QString &text) { refreshAdopterList(text); }
void MainWindow::onAdopterTableClicked(int row, int col) {
    txtAdopterId->setText(tblAdopters->item(row, 0)->text());
    txtAdopterName->setText(tblAdopters->item(row, 1)->text());
    txtAdopterPhone->setText(tblAdopters->item(row, 2)->text());
    txtAdopterAddress->setText(tblAdopters->item(row, 3)->text());
}

// ================= ADOPTION LOGIC =================

void MainWindow::refreshAdoptionTab() {
    cmbAvailablePets->clear();
    cmbAdopters->clear();

    auto pets = petService.getAllPets();
    for(const auto& p : pets) {

        if(p.status == "Available" && p.health.toLower() != "dead") {
            cmbAvailablePets->addItem(p.name + " (" + p.species + ")", p.id);
        }
    }

    auto adopters = adopterService.getAllAdopters();
    for(const auto& a : adopters) {
        cmbAdopters->addItem(a.fullName, a.id);
    }
}

void MainWindow::onAdoptClicked() {
    if(cmbAvailablePets->currentIndex() == -1 || cmbAdopters->currentIndex() == -1) {
        QMessageBox::warning(this, "Warning", "Please select both a pet and an adopter!"); return;
    }
    int petId = cmbAvailablePets->currentData().toInt();
    int adopterId = cmbAdopters->currentData().toInt();
    adoptionService.performAdoption(petId, adopterId, petService);
    QMessageBox::information(this, "Congratulations", "Adoption Process Completed! 🎉");
    refreshAdoptionTab();
    refreshPetList();
}
