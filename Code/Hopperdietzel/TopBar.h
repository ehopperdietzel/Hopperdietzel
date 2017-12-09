#ifndef LLL
#define LLL

#include "headers.h"
#include "topbarcounter.h"


class TopBar : public QWidget
{
    Q_OBJECT
public:
    TopBar();
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *title = new QLabel("HOPPERDIETZEL");
    TopBarCounter *amarillas = new TopBarCounter(QPixmap(":/Images/Caja.svg"),QColor("#FF931E"));
    TopBarCounter *rojas = new TopBarCounter(QPixmap(":/Images/Caja.svg"),QColor("#FF1D25"));
    TopBarCounter *negras = new TopBarCounter(QPixmap(":/Images/Caja.svg"),QColor("#3FA9F5"));
    TopBarCounter *encargos = new TopBarCounter(QPixmap(":/Images/Pedidos.svg"),QColor("#BDCCD4"));
    TopBarCounter *deudas = new TopBarCounter(QPixmap(":/Images/Deudas.svg"),QColor("#7AC943"));


signals:

public slots:
};

#endif
