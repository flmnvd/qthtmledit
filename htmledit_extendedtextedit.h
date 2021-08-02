#ifndef EXTENDEDTEXTEDIT_H
#define EXTENDEDTEXTEDIT_H

#include <QString>
#include <QTextList>
#include <QTextEdit>
#include <QMouseEvent>
#include <QApplication>
#include <QTextDocument>
#include <QTextBlockFormat>
#include <QTextDocumentFragment>
#include <QAbstractTextDocumentLayout>

class ExtendedTextEdit : public QTextEdit
{
    Q_OBJECT
public:

    explicit ExtendedTextEdit(QWidget *parent = NULL);

public slots:

    void setFontBold(bool state);

    void setFontStrikeOut(bool state);

    void setBulletList(bool state);

    void setNumberedList(bool state);

    void indentMore();

    void indentLess();

    void setForeground(QBrush brush);

    void setBackground(QBrush brush);

    void setDefaultFormat();

    void clearSelection();

    void select(int begin, int end);

signals:

    void boldStateChanged(bool state);

    void underlineStateChanged(bool state);

    void italicStateChanged(bool state);

    void strikeOutStateChanged(bool state);

    void bulletListStateChanged(bool state);

    void fontFamilyChanged(QString fontFamily);

    void fontSizeChanged(int size);

    void fontColorChanged(QColor color);

    void backgroundColorChanged(QColor color);

    void listStateChanged(int format);

    void alignChanged(Qt::Alignment alignment);

    void linkActivated(QString link);

    void linkHovered(QString link);

protected slots:

    void onCursorChanged();

    void onCharFormatChanged();

protected:

    QTextBlockFormat oldBlockFormat;

    QTextCharFormat oldCharFormat;

    Qt::MouseButtons pressedButton;

    QPoint mousePressBeginPosition;

    void mouseMoveEvent(QMouseEvent *e);

    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    void keyPressEvent(QKeyEvent *e);

    void keyReleaseEvent(QKeyEvent *e);

    virtual void mouseClickEvent(QMouseEvent *e);
};

#endif // EXTENDEDTEXTEDIT_H
