#ifndef JJ
#define JJ

#include "editclient.h"
#include "headers.h"
#include "tablebutton.h"
#include "database.h"
#include "tableitem.h"

class DataBase;

class OrdersView : public QWidget
{
    Q_OBJECT
public:
    OrdersView(DataBase *_db);

    void showOrders();

    QWidget *topBar = new QWidget();
    QHBoxLayout *tbLayout = new QHBoxLayout(topBar);
    QLineEdit *search = new QLineEdit();
    QPushButton *addButton = new QPushButton("Nuevo Pedido");

    QVBoxLayout *layout = new QVBoxLayout(this);
    QTableWidget *table = new QTableWidget();
    DataBase *db;

public slots:
    void addsOrder(bool mode);
    void ordersChange();
    void editsOrder(TableButton *btn);

};

#endif
