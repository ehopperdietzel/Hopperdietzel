#include "addorder.h"

AddOrder::AddOrder(DataBase *_db)
{
    db = _db;
    setWindowTitle("Nuevo Pedido");

    setStyleSheet("QLineEdit{border-radius:3px;padding:3px;}");

    aCaja->setFixedSize(30,30);
    rCaja->setFixedSize(30,30);
    nCaja->setFixedSize(30,30);
    aBotella->setFixedSize(30,30);
    rBotella->setFixedSize(30,30);
    nBotella->setFixedSize(30,30);

    cliente->setPlaceholderText("Cliente");
    factura->setPlaceholderText("Factura");
    guia->setPlaceholderText("Guía");

    QDateTime date = QDateTime::currentDateTime();
    fechaEntrega->setText(date.toString("dd/MM/yyyy"));
    fechaPago->setText(date.toString("dd/MM/yyyy"));

    fechaEntrega->hide();
    fechaPago->hide();
    fEntrega->hide();
    fPago->hide();

    connect(entregado,SIGNAL(toggled(bool)),this,SLOT(deliverToggle(bool)));
    connect(pagado,SIGNAL(toggled(bool)),this,SLOT(payToggle(bool)));

    precio->setStyleSheet("font-size:25px;text-align:center;color:#444");

    aCajasNum->setPlaceholderText("0");
    rCajasNum->setPlaceholderText("0");
    nCajasNum->setPlaceholderText("0");
    aSortNum->setPlaceholderText("0");
    rSortNum->setPlaceholderText("0");
    nSortNum->setPlaceholderText("0");

    layout->addWidget(entregado,0,0,1,2,Qt::AlignLeft);
    layout->addWidget(pagado,0,2,1,3,Qt::AlignLeft);

    layout->addWidget(cliente,1,0,1,6);
    layout->addWidget(factura,2,0,1,6);
    layout->addWidget(guia,3,0,1,6);

    layout->addWidget(fEntrega,4,0,1,2);
    layout->addWidget(fPago,4,2,1,4);
    layout->addWidget(fechaEntrega,5,0,1,2);
    layout->addWidget(fechaPago,5,2,1,4);

    layout->addWidget(tCajas,6,0,1,1);
    layout->addWidget(tSorteada,6,2,1,2);
    layout->addWidget(tStock,6,4,1,1);

    layout->addWidget(aCaja,7,0);
    layout->addWidget(aCajasNum,7,1);
    layout->addWidget(aBotella,7,2);
    layout->addWidget(aSortNum,7,3);
    layout->addWidget(aStock,7,4,1,2);

    layout->addWidget(rCaja,8,0);
    layout->addWidget(rCajasNum,8,1);
    layout->addWidget(rBotella,8,2);
    layout->addWidget(rSortNum,8,3);
    layout->addWidget(rStock,8,4,1,2);

    layout->addWidget(nCaja,9,0);
    layout->addWidget(nCajasNum,9,1);
    layout->addWidget(nBotella,9,2);
    layout->addWidget(nSortNum,9,3);
    layout->addWidget(nStock,9,4,1,2);

    layout->addWidget(precio,10,0,1,6);

    layout->addWidget(cancel,11,0,1,2);
    layout->addWidget(add,11,2,1,4);



    show();

}

void AddOrder::deliverToggle(bool mode)
{
    if(mode)
    {
        fechaEntrega->show();
        fEntrega->show();
    }
    else
    {
        fechaEntrega->hide();
        fEntrega->hide();
    }
}

void AddOrder::payToggle(bool mode)
{
    if(mode)
    {
        fechaPago->show();
        fPago->show();
    }
    else
    {
        fechaPago->hide();
        fPago->hide();
    }
}
