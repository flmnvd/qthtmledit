#include "htmledit.h"

HtmlEdit::HtmlEdit(QWidget *parent)
    : QWidget(parent)
{
    this->mode = Edit;

    this->undoAction = new QAction(this);

    this->undoAction->setIcon(QIcon(":resources/htmledit/undo.png"));

    this->undoAction->setToolTip(QString::fromLocal8Bit("Отменить действие"));

    this->redoAction = new QAction(this);

    this->redoAction->setIcon(QIcon(":resources/htmledit/redo.png"));

    this->redoAction->setToolTip(QString::fromLocal8Bit("Повторить действие"));

    this->fontFamilyBox = new QFontComboBox(this);

    this->fontFamilyBox->setFont(this->font());

    this->fontFamilyBox->setToolTip(QString::fromLocal8Bit("Шрифт"));

    this->fontSizeBox = new QSpinBox(this);

    this->fontSizeBox->setMinimum(1);

    this->fontSizeBox->setMaximum(100);

    this->fontSizeBox->setValue(this->font().pointSize());

    this->fontSizeBox->setToolTip(QString::fromLocal8Bit("Размер шрифта"));

    this->fontColorAction = new QAction(this);

    this->fontColorAction->setIcon(QIcon(":resources/htmledit/font-color.png"));

    this->fontColorAction->setToolTip(QString::fromLocal8Bit("Цвет шрифта"));

    this->backgroundColorAction = new QAction(this);

    this->backgroundColorAction->setIcon(QIcon(":resources/htmledit/background-color.png"));

    this->backgroundColorAction->setToolTip(QString::fromLocal8Bit("Цвет фона"));

    this->boldAction = new QAction(this);

    this->boldAction->setIcon(QIcon(":resources/htmledit/bold.png"));

    this->boldAction->setCheckable(true);

    this->boldAction->setToolTip(QString::fromLocal8Bit("Жирный"));

    this->italicAction = new QAction(this);

    this->italicAction->setIcon(QIcon(":resources/htmledit/italic.png"));

    this->italicAction->setCheckable(true);

    this->italicAction->setToolTip(QString::fromLocal8Bit("Курсивный"));

    this->underlineAction = new QAction(this);

    this->underlineAction->setIcon(QIcon(":resources/htmledit/underline.png"));

    this->underlineAction->setCheckable(true);

    this->underlineAction->setToolTip(QString::fromLocal8Bit("Подчеркнутый"));

    this->strikeOutAction = new QAction(this);

    this->strikeOutAction->setIcon(QIcon(":resources/htmledit/strikeout.png"));

    this->strikeOutAction->setCheckable(true);

    this->strikeOutAction->setToolTip(QString::fromLocal8Bit("Зачеркнутый"));

    this->clearFormatAction = new QAction(this);

    this->clearFormatAction->setIcon(QIcon(":resources/htmledit/clear-format.png"));

    this->clearFormatAction->setToolTip(QString::fromLocal8Bit("Сброс форматирования"));

    this->leftAction = new QAction(this);

    this->leftAction->setIcon(QIcon(":resources/htmledit/align-left.png"));

    this->leftAction->setCheckable(true);

    this->leftAction->setToolTip(QString::fromLocal8Bit("Выравнивание по левому краю"));

    this->centerAction = new QAction(this);

    this->centerAction->setIcon(QIcon(":resources/htmledit/align-center.png"));

    this->centerAction->setCheckable(true);

    this->centerAction->setToolTip(QString::fromLocal8Bit("Выравнивание по центру"));

    this->rightAction = new QAction(this);

    this->rightAction->setIcon(QIcon(":resources/htmledit/align-right.png"));

    this->rightAction->setCheckable(true);

    this->rightAction->setToolTip(QString::fromLocal8Bit("Выравнивание по правому краю"));

    this->fillAction = new QAction(this);

    this->fillAction->setIcon(QIcon(":resources/htmledit/align-fill.png"));

    this->fillAction->setCheckable(true);

    this->fillAction->setToolTip(QString::fromLocal8Bit("Выравнивание по всей ширине"));

    this->bulletListAction = new QAction(this);

    this->bulletListAction->setIcon(QIcon(":resources/htmledit/bullet-list.png"));

    this->bulletListAction->setCheckable(true);

    this->bulletListAction->setToolTip(QString::fromLocal8Bit("Список"));

    this->numberedListAction = new QAction(this);

    this->numberedListAction->setIcon(QIcon(":resources/htmledit/numbered-list.png"));

    this->numberedListAction->setCheckable(true);

    this->numberedListAction->setToolTip(QString::fromLocal8Bit("Нумерованный список"));

    this->indentMoreAction = new QAction(this);

    this->indentMoreAction->setIcon(QIcon(":resources/htmledit/indent-more.png"));

    this->indentMoreAction->setToolTip(QString::fromLocal8Bit("Отступ вправо"));

    this->indentLessAction = new QAction(this);

    this->indentLessAction->setIcon(QIcon(":resources/htmledit/indent-less.png"));

    this->indentLessAction->setToolTip(QString::fromLocal8Bit("Отступ влево"));

    this->insertLinkAction = new QAction(this);

    this->insertLinkAction->setIcon(QIcon(":resources/htmledit/hyperlink.png"));

    this->insertLinkAction->setToolTip(QString::fromLocal8Bit("Гиперссылка"));

    this->sourceCodeAction = new QAction(this);

    this->sourceCodeAction->setIcon(QIcon(":resources/htmledit/source.png"));

    this->sourceCodeAction->setCheckable(true);

    this->sourceCodeAction->setToolTip(QString::fromLocal8Bit("Исходный код"));

    this->textField = new ExtendedTextEdit(this);

    QObject::connect(this->undoAction, SIGNAL(triggered()), this->textField, SLOT(undo()));

    QObject::connect(this->redoAction, SIGNAL(triggered()), this->textField, SLOT(redo()));

    QObject::connect(this->italicAction, SIGNAL(toggled(bool)), this->textField, SLOT(setFontItalic(bool)));

    QObject::connect(this->underlineAction, SIGNAL(toggled(bool)), this->textField, SLOT(setFontUnderline(bool)));

    QObject::connect(this->boldAction, SIGNAL(toggled(bool)), this->textField, SLOT(setFontBold(bool)));

    QObject::connect(this->strikeOutAction, SIGNAL(toggled(bool)), this->textField, SLOT(setFontStrikeOut(bool)));

    QObject::connect(this->indentLessAction, SIGNAL(triggered()), this->textField, SLOT(indentLess()));

    QObject::connect(this->indentMoreAction, SIGNAL(triggered()), this->textField, SLOT(indentMore()));

    this->textField->setTextInteractionFlags(this->textField->textInteractionFlags() | Qt::LinksAccessibleByMouse);

    this->toolBar = new QToolBar(this);

    this->toolBar->addAction(this->undoAction);

    this->toolBar->addAction(this->redoAction);

    this->toolBar->addSeparator();

    this->toolBar->addWidget(this->fontFamilyBox);

    this->toolBar->addWidget(this->fontSizeBox);

    this->toolBar->addAction(this->fontColorAction);

    this->toolBar->addAction(this->backgroundColorAction);

    this->toolBar->addSeparator();

    this->toolBar->addAction(this->boldAction);

    this->toolBar->addAction(this->italicAction);

    this->toolBar->addAction(this->underlineAction);

    this->toolBar->addAction(this->strikeOutAction);

    this->toolBar->addSeparator();

    this->toolBar->addAction(this->leftAction);

    this->toolBar->addAction(this->centerAction);

    this->toolBar->addAction(this->rightAction);

    this->toolBar->addAction(this->fillAction);

    this->toolBar->addSeparator();

    this->toolBar->addAction(this->bulletListAction);

    this->toolBar->addAction(this->numberedListAction);

    this->toolBar->addAction(this->indentMoreAction);

    this->toolBar->addAction(this->indentLessAction);

    this->toolBar->addSeparator();

    this->toolBar->addAction(this->clearFormatAction);

    this->toolBar->addAction(this->insertLinkAction);

    this->toolBar->addAction(this->sourceCodeAction);

    this->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);

    this->setLayout(new QVBoxLayout(this));

    this->layout()->addWidget(toolBar);

    this->layout()->addWidget(textField);

    this->layout()->setMargin(0);

    QObject::connect(this->textField, SIGNAL(currentCharFormatChanged(const QTextCharFormat &)), this, SLOT(onCursorChanged()));

    QObject::connect(this->textField, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorChanged()));

    QObject::connect(this->fontFamilyBox, SIGNAL(activated(int)), this, SLOT(onFontFamilyActivated()));

    QObject::connect(this->fontSizeBox, SIGNAL(valueChanged(int)), this, SLOT(onFontSizeChanged(int)));

    QObject::connect(this->fontColorAction, SIGNAL(triggered()), this, SLOT(onFontColorTriggered()));

    QObject::connect(this->backgroundColorAction, SIGNAL(triggered()), this, SLOT(onBackgroundColorTriggered()));

    QObject::connect(this->leftAction, SIGNAL(toggled(bool)), this, SLOT(onLeftActionToggled(bool)));

    QObject::connect(this->centerAction, SIGNAL(toggled(bool)), this, SLOT(onCenterActionToggled(bool)));

    QObject::connect(this->rightAction, SIGNAL(toggled(bool)), this, SLOT(onRightActionToggled(bool)));

    QObject::connect(this->fillAction, SIGNAL(toggled(bool)), this, SLOT(onFillActionToggled(bool)));

    QObject::connect(this->clearFormatAction, SIGNAL(triggered()), this, SLOT(onClearFormatTriggered()));

    QObject::connect(this->insertLinkAction, SIGNAL(triggered()), this, SLOT(onInsertLinkTriggered()));

    QObject::connect(this->sourceCodeAction, SIGNAL(toggled(bool)), this, SLOT(onSourceCodeToggled(bool)));

    QObject::connect(this->bulletListAction, SIGNAL(toggled(bool)), this, SLOT(onBulletListToggled(bool)));

    QObject::connect(this->numberedListAction, SIGNAL(toggled(bool)), this, SLOT(onNumberedListToggled(bool)));

    connect(this->textField, SIGNAL(textChanged()), this, SIGNAL(textChanged()));
    connect(this->textField, SIGNAL(linkActivated(QString)), this, SLOT(onLinkActivated(QString)));
}


HtmlEdit::~HtmlEdit()
{

}

void HtmlEdit::setReadOnlyMode()
{
    if(this->mode != ReadOnly)
    {
        if(this->mode == RawEdit)
        {
            this->fontFamilyBox->setEnabled(true);

            this->fontSizeBox->setEnabled(true);

            this->fontColorAction->setEnabled(true);

            this->backgroundColorAction->setEnabled(true);

            this->boldAction->setEnabled(true);

            this->italicAction->setEnabled(true);

            this->underlineAction->setEnabled(true);

            this->strikeOutAction->setEnabled(true);

            this->leftAction->setEnabled(true);

            this->centerAction->setEnabled(true);

            this->rightAction->setEnabled(true);

            this->fillAction->setEnabled(true);

            this->bulletListAction->setEnabled(true);

            this->numberedListAction->setEnabled(true);

            this->indentMoreAction->setEnabled(true);

            this->indentLessAction->setEnabled(true);

            this->clearFormatAction->setEnabled(true);

            this->insertLinkAction->setEnabled(true);

            this->textField->setHtml(this->textField->toPlainText());
        }

        this->toolBar->setEnabled(false);

        this->toolBar->setVisible(false);

        this->textField->setReadOnly(true);

        this->mode = ReadOnly;
    }
}

void HtmlEdit::setEditMode()
{
    if(this->mode != Edit)
    {
        if(this->mode == ReadOnly)
        {
            this->toolBar->setEnabled(true);

            this->toolBar->setVisible(true);

            this->textField->setReadOnly(false);

            this->mode = Edit;
        }

        if(this->mode == RawEdit)
        {
            this->fontFamilyBox->setEnabled(true);

            this->fontSizeBox->setEnabled(true);

            this->fontColorAction->setEnabled(true);

            this->backgroundColorAction->setEnabled(true);

            this->boldAction->setEnabled(true);

            this->italicAction->setEnabled(true);

            this->underlineAction->setEnabled(true);

            this->strikeOutAction->setEnabled(true);

            this->leftAction->setEnabled(true);

            this->centerAction->setEnabled(true);

            this->rightAction->setEnabled(true);

            this->fillAction->setEnabled(true);

            this->bulletListAction->setEnabled(true);

            this->numberedListAction->setEnabled(true);

            this->indentMoreAction->setEnabled(true);

            this->indentLessAction->setEnabled(true);

            this->clearFormatAction->setEnabled(true);

            this->insertLinkAction->setEnabled(true);

            this->mode = Edit;

            this->textField->setHtml(this->textField->toPlainText());
        }
    }
}

void HtmlEdit::setRawEditMode()
{
    if(this->mode != RawEdit)
    {
        if(this->mode == ReadOnly)
        {
            this->toolBar->setEnabled(true);

            this->toolBar->setVisible(true);

            this->textField->setReadOnly(false);
        }

        this->fontFamilyBox->setEnabled(false);

        this->fontSizeBox->setEnabled(false);

        this->fontColorAction->setEnabled(false);

        this->backgroundColorAction->setEnabled(false);

        this->boldAction->setEnabled(false);

        this->italicAction->setEnabled(false);

        this->underlineAction->setEnabled(false);

        this->strikeOutAction->setEnabled(false);

        this->leftAction->setEnabled(false);

        this->centerAction->setEnabled(false);

        this->rightAction->setEnabled(false);

        this->fillAction->setEnabled(false);

        this->bulletListAction->setEnabled(false);

        this->numberedListAction->setEnabled(false);

        this->indentMoreAction->setEnabled(false);

        this->indentLessAction->setEnabled(false);

        this->clearFormatAction->setEnabled(false);

        this->insertLinkAction->setEnabled(false);

        this->mode = RawEdit;

        QString html = this->textField->toHtml();

        this->textField->clear();

        this->textField->setPlainText(html);

        this->textField->selectAll();

        this->textField->setDefaultFormat();

        this->textField->select(0, 0);
    }
}

void HtmlEdit::setText(QString text)
{
    if(mode == RawEdit)
    {
        this->textField->setPlainText(text);
    }
    else
    {
        this->textField->setText(text);
    }
}

QString HtmlEdit::toPlainText()
{
    if(mode == RawEdit)
    {
        QTextDocument doc;
        doc.setHtml(this->textField->toPlainText());
        return doc.toPlainText();
    }
    else
    {
        return this->textField->toPlainText();
    }
}

QString HtmlEdit::toHtml()
{
    if(mode == RawEdit)
    {
        return this->textField->toPlainText();
    }
    else
    {
        return this->textField->toHtml();
    }
}

void HtmlEdit::setSpecialLinksUsing(bool value)
{
    this->isSpecialLinksUsed = value;
}

bool HtmlEdit::specialLinksUsed()
{
    return this->isSpecialLinksUsed;
}

void HtmlEdit::select(int begin, int end)
{
    this->textField->select(begin, end);
}

void HtmlEdit::selectAll()
{
    this->textField->selectAll();
}

void HtmlEdit::clearFormat()
{
    this->onClearFormatTriggered();
}

void HtmlEdit::clear()
{
    this->textField->clear();
}

void HtmlEdit::insertLink(QString text, QString link)
{
    QString ref = "<a href=\"" + link + "\">" + text + "</a> ";

    this->textField->insertHtml(ref);
}

void HtmlEdit::onCursorChanged()
{
    this->boldAction->blockSignals(true);

    if(this->textField->fontWeight() == QFont::Normal)
    {
        this->boldAction->setChecked(false);
    }
    else
    {
        this->boldAction->setChecked(true);
    }

    this->boldAction->blockSignals(false);

    this->italicAction->blockSignals(true);

    this->italicAction->setChecked(this->textField->fontItalic());

    this->italicAction->blockSignals(false);

    this->underlineAction->blockSignals(true);

    this->underlineAction->setChecked(this->textField->fontUnderline());

    this->underlineAction->blockSignals(false);

    this->strikeOutAction->blockSignals(true);

    this->strikeOutAction->setChecked(this->textField->textCursor().charFormat().fontStrikeOut());

    this->strikeOutAction->blockSignals(false);

    this->leftAction->blockSignals(true);

    this->centerAction->blockSignals(true);

    this->rightAction->blockSignals(true);

    this->fillAction->blockSignals(true);

    switch(this->textField->alignment())
    {
    case Qt::AlignLeft:

        this->leftAction->setChecked(true);

        this->centerAction->setChecked(false);

        this->rightAction->setChecked(false);

        this->fillAction->setChecked(false);

        break;
    case Qt::AlignHCenter:

        this->leftAction->setChecked(false);

        this->centerAction->setChecked(true);

        this->rightAction->setChecked(false);

        this->fillAction->setChecked(false);

        break;
    case Qt::AlignRight:

        this->leftAction->setChecked(false);

        this->centerAction->setChecked(false);

        this->rightAction->setChecked(true);

        this->fillAction->setChecked(false);

        break;
    case Qt::AlignJustify:

        this->leftAction->setChecked(false);

        this->centerAction->setChecked(false);

        this->rightAction->setChecked(false);

        this->fillAction->setChecked(true);

        break;
    }

    this->leftAction->blockSignals(false);

    this->centerAction->blockSignals(false);

    this->rightAction->blockSignals(false);

    this->fillAction->blockSignals(false);

    this->fontFamilyBox->blockSignals(true);

    this->fontFamilyBox->setCurrentFont(this->textField->textCursor().charFormat().font());

    this->fontFamilyBox->blockSignals(false);

    this->fontSizeBox->blockSignals(true);

    this->fontSizeBox->setValue(this->textField->textCursor().charFormat().font().pointSize());

    this->fontSizeBox->blockSignals(false);

    this->bulletListAction->blockSignals(true);

    this->numberedListAction->blockSignals(true);

    bool isBulletList = false;

    bool isNumberedList = false;

    QTextList* list = this->textField->textCursor().currentList();

    if(list)
    {
        if(list->format().style() == QTextListFormat::ListDisc)
        {
            isBulletList = true;
        }

        if(list->format().style() == QTextListFormat::ListDecimal)
        {
            isNumberedList = true;
        }
    }

    this->bulletListAction->setChecked(isBulletList);

    this->numberedListAction->setChecked(isNumberedList);

    this->bulletListAction->blockSignals(false);

    this->numberedListAction->blockSignals(false);
}

void HtmlEdit::onFontFamilyActivated()
{
    this->textField->setFontFamily(this->fontFamilyBox->currentFont().family());
}

void HtmlEdit::onFontSizeChanged(int index)
{
    this->textField->setFontPointSize(index);
}

void HtmlEdit::onFontColorTriggered()
{
    QColorDialog *colorDialog = new QColorDialog(this);

    QColor color = colorDialog->getColor();

    delete colorDialog;

    if(color.isValid())
    {
        this->textField->setForeground(QBrush(color));
    }
}

void HtmlEdit::onBackgroundColorTriggered()
{
    QColorDialog *colorDialog = new QColorDialog(this);

    QColor color = colorDialog->getColor();

    delete colorDialog;

    if(color.isValid())
    {
        this->textField->setBackground(QBrush(color));
    }
}

void HtmlEdit::onLeftActionToggled(bool state)
{
    if(state)
    {
        this->centerAction->setChecked(false);

        this->rightAction->setChecked(false);

        this->fillAction->setChecked(false);

        this->textField->setAlignment(Qt::AlignLeft);
    }
    else
    {
        this->textField->setAlignment(Qt::AlignAbsolute);
    }
}

void HtmlEdit::onCenterActionToggled(bool state)
{
    if(state)
    {
        this->leftAction->setChecked(false);

        this->rightAction->setChecked(false);

        this->fillAction->setChecked(false);

        this->textField->setAlignment(Qt::AlignHCenter);
    }
    else
    {
        this->textField->setAlignment(Qt::AlignAbsolute);
    }

}

void HtmlEdit::onRightActionToggled(bool state)
{
    if(state)
    {
        this->leftAction->setChecked(false);

        this->centerAction->setChecked(false);

        this->fillAction->setChecked(false);

        this->textField->setAlignment(Qt::AlignRight);
    }
    else
    {
        this->textField->setAlignment(Qt::AlignAbsolute);
    }

}

void HtmlEdit::onFillActionToggled(bool state)
{
    if(state)
    {
        this->leftAction->setChecked(false);

        this->centerAction->setChecked(false);

        this->rightAction->setChecked(false);

        this->textField->setAlignment(Qt::AlignJustify);
    }
    else
    {
        this->textField->setAlignment(Qt::AlignAbsolute);
    }

}

void HtmlEdit::onBulletListToggled(bool state)
{
    this->numberedListAction->blockSignals(true);

    this->numberedListAction->setChecked(false);

    this->numberedListAction->blockSignals(false);

    this->textField->setBulletList(state);
}

void HtmlEdit::onNumberedListToggled(bool state)
{
    this->bulletListAction->blockSignals(true);

    this->bulletListAction->setChecked(false);

    this->bulletListAction->blockSignals(false);

    this->textField->setNumberedList(state);
}

void HtmlEdit::onClearFormatTriggered()
{
    this->textField->setDefaultFormat();

    this->onCursorChanged();
}

void HtmlEdit::onInsertLinkTriggered()
{
    if(this->isSpecialLinksUsed)
    {
        emit insertLinkClicked();
    }
    else
    {
        InsertLinkDialog* d = new InsertLinkDialog(this);

        d->exec();

        if(d->result() == QMessageBox::Ok)
        {
            insertLink(d->text(), d->link());
        }

       delete d;
    }
}

void HtmlEdit::onSourceCodeToggled(bool state)
{
    if(state)
    {
        this->setRawEditMode();
    }
    else
    {
        this->setEditMode();
    }
}

void HtmlEdit::onLinkActivated(QString link)
{
    if(this->isSpecialLinksUsed)
    {
        emit linkActivated(link);
    }
    else
    {
        //QDesktopServices::openUrl(QUrl::fromUserInput(link));
    }
}
