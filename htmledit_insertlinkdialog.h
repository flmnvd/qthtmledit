#ifndef INSERTLINKDIALOG_H
#define INSERTLINKDIALOG_H

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class InsertLinkDialog : public QDialog
{
    Q_OBJECT
public:

    explicit InsertLinkDialog(QWidget *parent = NULL);

    QString text();

    QString link();

    int result();

protected:

    int dialogResult;

    QLineEdit *textEdit;

    QLabel *textLabel;

    QLineEdit *linkEdit;

    QLabel *linkLabel;

    QPushButton *okButton;

    QPushButton *cancelButton;

    QGroupBox *buttons;

protected slots:

    void onOkButtonClicked();

    void onCancelButtonClicked();
};

#endif // INSERTLINKDIALOG_H
