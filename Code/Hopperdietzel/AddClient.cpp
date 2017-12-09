#include "addclient.h"
#include "database.h"

AddClient::AddClient(DataBase *_db)
{
    db =_db;
    resize(300,300);
    setStyleSheet("QLineEdit{border-radius:3px;padding:3px}");
    nombre->setPlaceholderText("Nombre");
    ciudad->setPlaceholderText("Ciudad");
    direccion->setPlaceholderText("Dirección");
    rut->setPlaceholderText("RUT");
    numero->setPlaceholderText("Teléfono");
    correo->setPlaceholderText("Correo");

    layout->addWidget(nombre);
    layout->addWidget(ciudad);
    layout->addWidget(direccion);
    layout->addWidget(rut);
    layout->addWidget(numero);
    layout->addWidget(correo);
    layout->addWidget(bottom);

    bottomLayout->addWidget(cancel);
    bottomLayout->addWidget(add);

    setWindowTitle("Nuevo Cliente");
    add->setFocus();

    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(cancelar(bool)));
    connect(add,SIGNAL(clicked(bool)),this,SLOT(añadir(bool)));



}

void AddClient::cancelar(bool mode)
{
    close();
}

void AddClient::añadir(bool mode)
{
    QVariantMap client = QVariantMap();
    client["id"] = db->lastClientId() + 1;
    client["name"] = nombre->text();
    client["city"] = ciudad->text();
    client["address"] = direccion->text();
    client["rut"] = rut->text();
    client["phone"] = numero->text();
    client["mail"] = correo->text();

    db->clients.append(client);

    clientAdded();
    close();
}
