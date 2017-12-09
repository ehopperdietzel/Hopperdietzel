#ifndef GG
#define GG

#include "headers.h"
#include "leftbarheader.h"
#include "leftbaritem.h"

class LeftBar : public QWidget
{
    Q_OBJECT
public:
    LeftBar();
    QVBoxLayout *layout = new QVBoxLayout(this);
    LeftBarHeader *header = new LeftBarHeader();
    LeftBarItem *clients = new LeftBarItem(":/Images/Clientes.svg", "Clientes");
    LeftBarItem *orders = new LeftBarItem(":/Images/Pedidos.svg", "Pedidos");
    LeftBarItem *production = new LeftBarItem(":/Images/Produccion.svg", "Producción");
    LeftBarItem *stats = new LeftBarItem(":/Images/Estadisticas.svg", "Estadísticas");
    LeftBarItem *configurations = new LeftBarItem(":/Images/Configuraciones.svg", "Configuraciones");
    QList<LeftBarItem*> items;


signals:
    void itemSelected(LeftBarItem *);
public slots:
    void itemSelection(LeftBarItem *);
};

#endif
