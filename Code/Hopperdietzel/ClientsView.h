#include "editclient.h"

#ifndef CC
#define CC

#include "headers.h"
#include "tablebutton.h"
#include "database.h"
#include "tableitem.h"

class DataBase;
class AddClient;

class ClientsView : public QWidget
{
    Q_OBJECT
public:
    ClientsView(DataBase *_db);

    void showClients();

    QWidget *topBar = new QWidget();
    QHBoxLayout *tbLayout = new QHBoxLayout(topBar);
    QLineEdit *search = new QLineEdit();
    QPushButton *addButton = new QPushButton("Añadir Cliente");

    QVBoxLayout *layout = new QVBoxLayout(this);
    QTableWidget *table = new QTableWidget();
    DataBase *db;

public slots:
    void addsClient(bool mode);
    void clientsChange();
    void editsClient(TableButton *btn);

};
#endif
