#include "htmledit_extendedtextedit.h"

ExtendedTextEdit::ExtendedTextEdit(QWidget *parent) : QTextEdit(parent)
{
    this->oldBlockFormat = this->textCursor().blockFormat();

    this->oldCharFormat = this->textCursor().charFormat();

    QObject::connect(this, SIGNAL(currentCharFormatChanged(const QTextCharFormat&)), this, SLOT(onCharFormatChanged()));

    QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorChanged()));

    this->setMouseTracking(true);
}

void ExtendedTextEdit::setFontBold(bool state)
{
    if(state)
    {
        if(this->fontWeight() != QFont::Bold)
        {
            this->setFontWeight(QFont::Bold);
        }
    }
    else
    {
        if(this->fontWeight() != QFont::Normal)
        {
            this->setFontWeight(QFont::Normal);
        }
    }
}

void ExtendedTextEdit::setFontStrikeOut(bool state)
{
    if(this->textCursor().charFormat().fontStrikeOut() != state)
    {
        QTextCharFormat charFormat;

        charFormat.setFontStrikeOut(state);

        this->mergeCurrentCharFormat(charFormat);
    }
}

void ExtendedTextEdit::setBulletList(bool state)
{
    this->textCursor().beginEditBlock();

    if(state)
    {
        QTextListFormat listFormat;

        listFormat.setStyle(QTextListFormat::ListDisc);

        this->textCursor().createList(listFormat);
    }
    else
    {
        QTextBlockFormat blockFormat;

        blockFormat.setIndent(0);

        this->textCursor().setBlockFormat(blockFormat);
    }

    this->textCursor().endEditBlock();
}

void ExtendedTextEdit::setNumberedList(bool state)
{
    this->textCursor().beginEditBlock();

    if(state)
    {
        QTextListFormat listFormat;

        listFormat.setStyle(QTextListFormat::ListDecimal);

        this->textCursor().createList(listFormat);
    }
    else
    {
        QTextBlockFormat blockFormat;

        blockFormat.setIndent(0);

        this->textCursor().setBlockFormat(blockFormat);
    }

    this->textCursor().endEditBlock();
}

void ExtendedTextEdit::indentMore()
{
    this->textCursor().beginEditBlock();

    QTextBlockFormat blockFormat = this->textCursor().blockFormat();

    blockFormat.setIndent(blockFormat.indent() + 1);

    this->textCursor().setBlockFormat(blockFormat);

    this->textCursor().endEditBlock();
}

void ExtendedTextEdit::indentLess()
{
    this->textCursor().beginEditBlock();

    QTextBlockFormat blockFormat = this->textCursor().blockFormat();

    if(blockFormat.indent() > 0)
    {
        blockFormat.setIndent(blockFormat.indent() - 1);
    }

    this->textCursor().setBlockFormat(blockFormat);

    this->textCursor().endEditBlock();
}

void ExtendedTextEdit::setForeground(QBrush brush)
{
    QTextCharFormat charFormat;
    charFormat.setForeground(brush);
    this->mergeCurrentCharFormat(charFormat);
}

void ExtendedTextEdit::setBackground(QBrush brush)
{
    QTextCharFormat charFormat;
    charFormat.setBackground(brush);
    this->mergeCurrentCharFormat(charFormat);
}

void ExtendedTextEdit::setDefaultFormat()
{
    this->setFontFamily(QApplication::font().family());

    this->setFontPointSize(QApplication::font().pointSize());

    this->setAlignment(Qt::AlignAbsolute);

    QTextCharFormat format;

    format.setForeground(QBrush());

    format.setBackground(QBrush());

    format.setFontWeight(QFont::Normal);

    format.setFontItalic(false);

    format.setFontUnderline(false);

    format.setFontStrikeOut(false);

    this->mergeCurrentCharFormat(format);

    this->textCursor().beginEditBlock();

    QTextBlockFormat blockFormat;

    blockFormat.setIndent(0);

    this->textCursor().setBlockFormat(blockFormat);

    this->textCursor().endEditBlock();
}

void ExtendedTextEdit::clearSelection()
{
    QTextCursor cursor = this->textCursor();

    cursor.clearSelection();

    this->setTextCursor(cursor);
}

void ExtendedTextEdit::select(int begin, int end)
{
    if(begin < 0)
    {
        begin = 0;
    }

    if(end > this->toPlainText().length())
    {
        end = this->toPlainText().length();
    }

    QTextCursor cursor = this->textCursor();

    cursor.setPosition(begin, QTextCursor::MoveAnchor);

    cursor.setPosition(end, QTextCursor::KeepAnchor);

    this->setTextCursor(cursor);
}

void ExtendedTextEdit::onCursorChanged()
{
    QTextBlockFormat newBlockFormat = this->textCursor().blockFormat();

    if(this->oldBlockFormat.alignment() != newBlockFormat.alignment())
    {
        emit this->alignChanged(newBlockFormat.alignment());
    }

    if(this->oldBlockFormat.isListFormat())
    {
        if(newBlockFormat.isListFormat())
        {
            if(this->oldBlockFormat.toListFormat().style() != newBlockFormat.toListFormat().style())
            {
                emit this->listStateChanged(newBlockFormat.toListFormat().style());
            }
        }
        else
        {
            emit this->listStateChanged(0);
        }
    }
    else
    {
        if(newBlockFormat.isListFormat())
        {
            emit this->listStateChanged(newBlockFormat.toListFormat().style());
        }
    }

    this->oldBlockFormat = newBlockFormat;
}

void ExtendedTextEdit::onCharFormatChanged()
{
    QTextCharFormat newCharFormat = this->textCursor().charFormat();

    if(this->oldCharFormat.fontFamily() != newCharFormat.fontFamily())
    {
        emit this->fontFamilyChanged(newCharFormat.fontFamily());
    }

    if(this->oldCharFormat.fontPointSize() != newCharFormat.fontPointSize())
    {
        emit this->fontSizeChanged(newCharFormat.fontPointSize());
    }

    if(this->oldCharFormat.foreground().color() != newCharFormat.foreground().color())
    {
        emit this->fontColorChanged(newCharFormat.foreground().color());
    }

    if(this->oldCharFormat.background().color() != newCharFormat.background().color())
    {
        emit this->backgroundColorChanged(newCharFormat.background().color());
    }

    if(this->oldCharFormat.fontWeight() != newCharFormat.fontWeight())
    {
        emit this->boldStateChanged(newCharFormat.fontWeight() == QFont::Bold);
    }

    if(this->oldCharFormat.fontItalic() != newCharFormat.fontItalic())
    {
        emit this->italicStateChanged(newCharFormat.fontItalic());
    }

    if(this->oldCharFormat.fontUnderline() != newCharFormat.fontUnderline())
    {
        emit this->underlineStateChanged(newCharFormat.fontUnderline());
    }

    if(this->oldCharFormat.fontStrikeOut() != newCharFormat.fontStrikeOut())
    {
        emit this->italicStateChanged(newCharFormat.fontStrikeOut());
    }

    this->oldCharFormat = newCharFormat;
}

void ExtendedTextEdit::mouseMoveEvent(QMouseEvent *e)
{
    this->QTextEdit::mouseMoveEvent(e);

    if((QApplication::keyboardModifiers() & Qt::ControlModifier) && (e->button() == Qt::NoButton) && this->hasFocus())
    {
        QString hoveredLink = this->document()->documentLayout()->anchorAt(e->pos());

        if(hoveredLink.isEmpty())
        {
            this->viewport()->setCursor(Qt::ArrowCursor);
        }
        else
        {
            emit this->linkHovered(hoveredLink);

            this->viewport()->setCursor(Qt::PointingHandCursor);
        }
    }
    else
    {
        if((this->cursor().shape() != Qt::IBeamCursor))
        {
            this->viewport()->setCursor(Qt::IBeamCursor);
        }
    }
}

void ExtendedTextEdit::mousePressEvent(QMouseEvent *e)
{
    this->QTextEdit::mousePressEvent(e);

    this->mousePressBeginPosition = e->pos();

    this->pressedButton = e->button();
}

void ExtendedTextEdit::mouseReleaseEvent(QMouseEvent *e)
{
    this->QTextEdit::mouseReleaseEvent(e);

    this->pressedButton = Qt::NoButton;

    if(e->pos() == this->mousePressBeginPosition)
    {
        this->mouseClickEvent(e);
    }
}

void ExtendedTextEdit::keyPressEvent(QKeyEvent *e)
{
    this->QTextEdit::keyPressEvent(e);

    if((e->key() == Qt::Key_Control) && this->hasFocus())
    {
        QString hoveredLink = this->document()->documentLayout()->anchorAt(this->mapFromGlobal(this->cursor().pos()));

        if(hoveredLink.isEmpty())
        {
            this->viewport()->setCursor(Qt::ArrowCursor);
        }
        else
        {
            emit this->linkHovered(hoveredLink);

            this->viewport()->setCursor(Qt::PointingHandCursor);
        }
    }
}

void ExtendedTextEdit::keyReleaseEvent(QKeyEvent *e)
{
    this->QTextEdit::keyReleaseEvent(e);

    if((e->key() == Qt::Key_Control) && this->hasFocus())
    {
        this->viewport()->setCursor(Qt::IBeamCursor);
    }
}

void ExtendedTextEdit::mouseClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(QApplication::keyboardModifiers() & Qt::ControlModifier)
        {
            QString hoveredLink = this->document()->documentLayout()->anchorAt(e->pos());

            if(!hoveredLink.isEmpty())
            {
                emit this->linkActivated(hoveredLink);
            }
        }
    }
}
