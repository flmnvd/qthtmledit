#ifndef HTMLEDIT_H
#define HTMLEDIT_H

#include <QUrl>
#include <QIcon>
#include <QWidget>
#include <QAction>
#include <QSpinBox>
#include <QToolBar>
#include <QTextEdit>
#include <QLineEdit>
#include <QTextList>
#include <QTextBlock>
#include <QToolButton>
#include <QHBoxLayout>
#include <QColorDialog>
#include <QWidgetAction>
#include <QFontComboBox>
//#include <QDesktopServices>
#include <QTextDocumentFragment>

#include "htmledit_insertlinkdialog.h"
#include "htmledit_extendedtextedit.h"

class HtmlEdit : public QWidget
{
    Q_OBJECT

public:

    HtmlEdit(QWidget *parent = 0);

    QString toPlainText();

    QString toHtml();

    void setSpecialLinksUsing(bool value);

    bool specialLinksUsed();

    ~HtmlEdit();

public slots:

    void setReadOnlyMode();

    void setEditMode();

    void setRawEditMode();

    void setText(QString text);

    void select(int begin, int end);

    void selectAll();

    void clearFormat();

    void clear();

    void insertLink(QString text, QString link);

protected:

    enum Modes{ ReadOnly, Edit, RawEdit};

    Modes mode;

    ExtendedTextEdit *textField;

    QToolBar *toolBar;

    QAction *undoAction, *redoAction;

    QFontComboBox *fontFamilyBox;

    QSpinBox *fontSizeBox;

    QAction *fontColorAction, *backgroundColorAction;

    QAction *boldAction, *italicAction, *underlineAction, *strikeOutAction;

    QAction *leftAction, *centerAction, *rightAction, *fillAction;

    QAction *bulletListAction, *numberedListAction, *indentMoreAction, *indentLessAction;

    QAction *clearFormatAction, *insertLinkAction, *sourceCodeAction;

protected slots:

    void onCursorChanged();

    void onFontFamilyActivated();

    void onFontSizeChanged(int index);

    void onFontColorTriggered();

    void onBackgroundColorTriggered();

    void onLeftActionToggled(bool state);

    void onCenterActionToggled(bool state);

    void onRightActionToggled(bool state);

    void onFillActionToggled(bool state);

    void onBulletListToggled(bool state);

    void onNumberedListToggled(bool state);

    void onClearFormatTriggered();

    void onInsertLinkTriggered();

    void onSourceCodeToggled(bool state);

    void onLinkActivated(QString link);

signals:

    void textChanged();

    void insertLinkClicked();

    void linkActivated(QString string);

protected:

    bool isSpecialLinksUsed;
};

#endif // HTMLEDIT_H
