#include "leftbar.h"

LeftBar::LeftBar()
{
    setAutoFillBackground(true);
    setPalette(QColor("#DDD"));
    setFixedWidth(180);

    layout->setMargin(0);
    layout->setSpacing(0);

    layout->addWidget(header);
    layout->addWidget(clients);
    layout->addWidget(orders);
    layout->addWidget(production);
    layout->addWidget(stats);
    layout->addWidget(configurations);

    items << clients << orders << production << stats << configurations;

    connect(clients,SIGNAL(selected(LeftBarItem*)),this,SLOT(itemSelection(LeftBarItem*)));
    connect(orders,SIGNAL(selected(LeftBarItem*)),this,SLOT(itemSelection(LeftBarItem*)));
    connect(production,SIGNAL(selected(LeftBarItem*)),this,SLOT(itemSelection(LeftBarItem*)));
    connect(stats,SIGNAL(selected(LeftBarItem*)),this,SLOT(itemSelection(LeftBarItem*)));
    connect(configurations,SIGNAL(selected(LeftBarItem*)),this,SLOT(itemSelection(LeftBarItem*)));

    layout->addStretch(1);
}

void LeftBar::itemSelection(LeftBarItem *it)
{
    foreach( LeftBarItem *item, items)
    {
        item->setActive(false);
    }
    it->setActive(true);
    itemSelected(it);
}
