#ifndef MM
#define MM

#include "headers.h"
#include "icon.h"

class TopBarCounter : public QWidget
{
    Q_OBJECT
public:
    TopBarCounter(const QPixmap &icon, QColor col)
    {
        ico = new Icon(icon,col);
        ico->setFixedSize(20,20);
        text->setStyleSheet("font-weight:bold;color:white");
        layout->addWidget(ico,0,Qt::AlignCenter);
        layout->addWidget(text,0,Qt::AlignCenter);

    }
    void setNumber(uint num)
    {
        text->setText(QString::number(num));
    }

private:
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *text = new QLabel("0");
    Icon *ico;

};
#endif
