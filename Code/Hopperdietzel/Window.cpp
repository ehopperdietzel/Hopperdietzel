#include "window.h"
#include "dataBase.h"
#include "clientsview.h"
#include "ordersview.h"

Window::Window(DataBase *_db)
{
    db = _db;

    clientsView = new ClientsView(db);
    ordersView = new OrdersView(db);

    setWindowTitle("Administrador Hopperdietzel");

    QVariantMap windowSettings = db->settings["window"].toMap();

    resize(windowSettings["w"].toInt(),windowSettings["h"].toInt());
    move(windowSettings["x"].toInt(),windowSettings["y"].toInt());

    verticalLayout->setSpacing(0);
    verticalLayout->setMargin(0);
    verticalLayout->addWidget(mainTopBar);
    verticalLayout->addWidget(bottomContainer,1);

    horizontalLayout->setSpacing(0);
    horizontalLayout->setMargin(0);

    horizontalLayout->addWidget(leftBar);
    horizontalLayout->addWidget(clientsView);
    horizontalLayout->addWidget(ordersView);

    connect(leftBar,SIGNAL(itemSelected(LeftBarItem*)),this,SLOT(itemSelected(LeftBarItem*)));

    show();
}

void Window::closeEvent(QCloseEvent *close)
{
    db->saveData();
    close->accept();
    QApplication::exit();
}

void Window::itemSelected(LeftBarItem *it)
{
    clientsView->hide();
    ordersView->hide();

    if( it == leftBar->clients )
    {
        clientsView->show();
    }
    else if( it == leftBar->orders )
    {
        ordersView->show();
    }
}


