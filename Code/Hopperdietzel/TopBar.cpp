#include "topbar.h"

TopBar::TopBar()
{
    setFixedHeight(60);
    setAutoFillBackground(true);
    setPalette(QColor("#1A1A1A"));

    layout->setMargin(10);

    title->setStyleSheet("font-family:Impact;color:#DDD;font-size:30px");
    layout->setAlignment(Qt::AlignVCenter);
    layout->addWidget(title);
    layout->addWidget(amarillas);
    layout->addWidget(rojas);
    layout->addWidget(negras);
    layout->addWidget(encargos);
    layout->addWidget(deudas);
    layout->addStretch(1);

}
