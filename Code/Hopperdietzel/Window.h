#ifndef NNNN
#define NNNN

#include "headers.h"
#include "tableButton.h"
#include "topBar.h"
#include "leftBar.h"

class DataBase;
class ClientsView;
class OrdersView;

class Window : public QWidget
{
    Q_OBJECT

public:
    // Main Window
    Window(DataBase *_db);

    // Bottom container
    QWidget *bottomContainer = new QWidget();

    // Views
    ClientsView *clientsView;
    OrdersView *ordersView;

    // Bars
    TopBar *mainTopBar = new TopBar();
    LeftBar *leftBar = new LeftBar();

    // Layouts
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QHBoxLayout *horizontalLayout = new QHBoxLayout(bottomContainer);

    // Database
    DataBase *db;

private:
    void closeEvent(QCloseEvent *close);

public slots:
    void itemSelected(LeftBarItem *);
};

#endif
