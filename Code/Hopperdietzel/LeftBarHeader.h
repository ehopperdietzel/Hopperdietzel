#ifndef HH
#define HH

#include "headers.h"

class LeftBarHeader : public QFrame
{
    Q_OBJECT

public:
    QLabel *title = new QLabel("MENU");
    QHBoxLayout *layout = new QHBoxLayout(this);
    LeftBarHeader()
    {
        layout->addWidget(title);
        layout->setMargin(4);
        layout->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-weight:bold;color:#444");
        setFixedHeight(30);
        setObjectName("HEADER");
        setStyleSheet("#HEADER{border:solid;border-bottom-color:#CCC;border-bottom-width:1px;border-bottom-style:solid}");

    }
};

#endif
