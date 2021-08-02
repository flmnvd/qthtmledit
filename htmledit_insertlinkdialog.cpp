#include "htmledit_insertlinkdialog.h"

InsertLinkDialog::InsertLinkDialog(QWidget *parent) : QDialog(parent)
{
    this->dialogResult = QMessageBox::Cancel;

    this->textLabel = new QLabel(QString::fromLocal8Bit("Текст:"), this);

    this->linkLabel = new QLabel(QString::fromLocal8Bit("Ссылка:"), this);

    this->textEdit = new QLineEdit(this);

    this->linkEdit = new QLineEdit(this);

    this->okButton = new QPushButton(this);

    this->okButton->setText(QString::fromLocal8Bit("Готово"));

    this->okButton->setFixedSize(this->okButton->sizeHint());

    this->cancelButton = new QPushButton(this);

    this->cancelButton->setText(QString::fromLocal8Bit("Отмена"));

    this->cancelButton->setFixedSize(this->cancelButton->sizeHint());

    this->buttons = new QGroupBox(this);

    this->buttons->setLayout(new QHBoxLayout(this));

    this->buttons->layout()->setAlignment(Qt::AlignRight);

    this->buttons->layout()->addWidget(this->okButton);

    this->buttons->layout()->addWidget(this->cancelButton);

    this->setLayout(new QVBoxLayout(this));

    this->layout()->addWidget(this->textLabel);

    this->layout()->addWidget(this->textEdit);

    this->layout()->addWidget(this->linkLabel);

    this->layout()->addWidget(this->linkEdit);

    this->layout()->addWidget(this->buttons);

    this->setWindowTitle(QString::fromLocal8Bit("Гиперссылка"));

    this->setFixedHeight(this->sizeHint().height());

    QObject::connect(this->okButton, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));

    QObject::connect(this->cancelButton, SIGNAL(clicked()), this, SLOT(onCancelButtonClicked()));
}

QString InsertLinkDialog::text()
{
    return this->textEdit->text();
}

QString InsertLinkDialog::link()
{
    return this->linkEdit->text();
}

int InsertLinkDialog::result()
{
    return dialogResult;
}

void InsertLinkDialog::onOkButtonClicked()
{
    this->dialogResult = QMessageBox::Ok;

    this->hide();
}

void InsertLinkDialog::onCancelButtonClicked()
{
    this->dialogResult = QMessageBox::Cancel;

    this->hide();
}
