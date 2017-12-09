#include "clientsview.h"
#include "addclient.h"


ClientsView::ClientsView(DataBase *_db)
{
    db = _db;
    setAutoFillBackground(true);
    setPalette( Qt::white );

    QString tbStyle = "#TB{border:solid;border-bottom-color:#CCC;border-left-color:#CCC;border-left-width:1px;border-left-style:solid;border-bottom-width:1px;border-bottom-style:solid;background:#DDD}";

    topBar->setFixedHeight(30);
    topBar->setObjectName("TB");
    topBar->setStyleSheet(tbStyle);

    tbLayout->addWidget(search);
    tbLayout->addStretch(1);
    tbLayout->addWidget(addButton);
    tbLayout->setMargin(5);

    search->setPlaceholderText("Buscar Cliente");
    search->setMinimumWidth(200);
    search->setStyleSheet("border-radius:3px;font-size:10px;padding:2px");

    addButton->setStyleSheet("font-size:10px");


    QStringList headers;
    headers << "Nombre" << "Ciudad" << "Dirección" << "Teléfono" << "RUT" << "Correo" << "Editar";

    table->setRowCount(20);
    table->setColumnCount(7);
    table->setHorizontalHeaderLabels(headers);
    table->verticalHeader()->hide();
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setStyleSheet("QTableWidget{border:none;}QTableWidget::item{}");

    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(topBar);
    layout->addWidget(table);

    connect(addButton,SIGNAL(clicked(bool)),this,SLOT(addsClient(bool)));
    showClients();
    table->show();
}

void ClientsView::showClients()
{
    table->clearContents();
    int row = 0;
    foreach(QVariant c,db->clients)
    {
        QVariantMap client = c.toMap();
        table->setItem(row,0,new TableItem(client["name"].toString()));
        table->setItem(row,1,new TableItem(client["city"].toString()));
        table->setItem(row,2,new TableItem(client["address"].toString()));
        table->setItem(row,3,new TableItem(client["phone"].toString()));
        table->setItem(row,4,new TableItem(client["rut"].toString()));
        table->setItem(row,5,new TableItem(client["mail"].toString()));
        TableButton *btn = new TableButton("EDITAR");
        btn->number = client["id"].toInt();
        btn->clearFocus();
        connect(btn,SIGNAL(clickEvent(TableButton*)),this,SLOT(editsClient(TableButton*)));
        table->setCellWidget(row,6,btn);
        table->setRowHeight(row,20);

        row++;
    }
}

void ClientsView::addsClient(bool mode)
{
    AddClient *addWindow = new AddClient(db);
    connect(addWindow,SIGNAL(clientAdded()),this,SLOT(clientsChange()));
    addWindow->show();
}

void ClientsView::editsClient(TableButton *btn)
{

    EditClient *addWindow = new EditClient(db,btn);
    connect(addWindow,SIGNAL(clientDeleted()),this,SLOT(clientsChange()));
    connect(addWindow,SIGNAL(clientEdited()),this,SLOT(clientsChange()));
    addWindow->show();
}

void ClientsView::clientsChange()
{
    showClients();
}

