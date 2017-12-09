#ifndef HHHA
#define HHHA

#include "headers.h"
#include "icon.h"

class LeftBarItem : public QWidget
{
    Q_OBJECT

public:
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *text = new QLabel();
    Icon *icon;
    LeftBarItem(const QString &ico, const QString &title)
    {
        icon = new Icon(QPixmap(ico),gray);
        icon->setFixedSize(15,15);
        layout->setContentsMargins(10,5,10,5);
        layout->setSpacing(10);
        setFixedHeight(30);
        setObjectName("item");
        text->setText(title);
        layout->addWidget(icon);
        layout->addWidget(text);
        setAutoFillBackground(true);
        setActive(false);
    }

    void mousePressEvent(QMouseEvent *event)
    {
        setActive(true);
        selected(this);
    }

    void setActive(bool mode)
    {
        if(mode)
        {
            text->setStyleSheet("color:#FFF");
            icon->setColor(Qt::white);
            setPalette(blue);
        }
        else
        {
            text->setStyleSheet("color:#666");
            icon->setColor(gray);
            setPalette(Qt::transparent);
        }
    }
signals:
    void selected(LeftBarItem *item);
};
#endif
