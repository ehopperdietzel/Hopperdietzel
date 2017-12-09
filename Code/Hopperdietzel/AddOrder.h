#ifndef BB
#define BB

#include "headers.h"
#include "icon.h"
#include "database.h"

class AddOrder : public QWidget
{
    Q_OBJECT
public:
    AddOrder(DataBase *_db);

    DataBase *db;

    QCheckBox *entregado = new QCheckBox("Entregado");
    QCheckBox *pagado = new QCheckBox("Pagado");

    QLineEdit *cliente = new QLineEdit();
    QLineEdit *factura = new QLineEdit();
    QLineEdit *guia = new QLineEdit();
    QLineEdit *fechaEntrega = new QLineEdit();
    QLineEdit *fechaPago = new QLineEdit();

    QLineEdit *aCajasNum = new QLineEdit("");
    QLineEdit *rCajasNum = new QLineEdit("");
    QLineEdit *nCajasNum = new QLineEdit("");
    QLineEdit *aSortNum = new QLineEdit("");
    QLineEdit *rSortNum = new QLineEdit("");
    QLineEdit *nSortNum = new QLineEdit("");

    QLabel *fEntrega = new QLabel("Fecha de Entrega");
    QLabel *fPago = new QLabel("Fecha de Pago");
    QLabel *tCajas = new QLabel("Cajas");
    QLabel *tSorteada = new QLabel("Sorteada");
    QLabel *tStock = new QLabel("Stock");

    QLabel *aStock = new QLabel("0");
    QLabel *rStock = new QLabel("0");
    QLabel *nStock = new QLabel("0");
    QLabel *precio = new QLabel("Costo: $0");

    Icon *aCaja = new Icon(QPixmap(":/Images/Caja.svg"),QColor("#FF931E"));
    Icon *rCaja = new Icon(QPixmap(":/Images/Caja.svg"),QColor("#FF1D25"));
    Icon *nCaja = new Icon(QPixmap(":/Images/Caja.svg"),QColor("#3FA9F5"));

    Icon *aBotella = new Icon(QPixmap(":/Images/Cerveza.svg"),QColor("#FF931E"));
    Icon *rBotella = new Icon(QPixmap(":/Images/Cerveza.svg"),QColor("#FF1D25"));
    Icon *nBotella = new Icon(QPixmap(":/Images/Cerveza.svg"),QColor("#3FA9F5"));

    QPushButton *cancel = new QPushButton("Cancelar");
    QPushButton *add = new QPushButton("Crear Pedido");

    QGridLayout *layout = new QGridLayout(this);

public slots:
    void deliverToggle(bool mode);
    void payToggle(bool mode);








};

#endif
