#ifndef ADDPETDIALOG_H
#define ADDPETDIALOG_H

#include <QDialog>
#include <QLineEdit>

class AddPetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPetDialog(QWidget *parent = nullptr);

    QString getName() const;
    QString getSpecies() const;
    int getAge() const;
    QString getHealth() const;

private:
    QLineEdit *txtName;
    QLineEdit *txtSpecies;
    QLineEdit *txtAge;
    QLineEdit *txtHealth;

    void setupUI();
};

#endif // ADDPETDIALOG_H
