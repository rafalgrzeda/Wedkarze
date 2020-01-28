#include "displaytext.h"
#include <QFont>

DisplayText::DisplayText(QString _text)
{
    QFont myfont;
    myfont.setPixelSize(20);
    myfont.setBold(true);
    setFont(myfont);

    text = _text;
    setPlainText(text);
}

QString DisplayText::getText() const
{
    return text;
}

void DisplayText::setText(const QString &value)
{
    text = value;
}
