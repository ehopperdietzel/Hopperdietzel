#include "editclient.h"

EditClient::EditClient(DataBase *_db, TableButton *item)
{
    clientIT = item;
    db =_db;
    qDebug()<< item->number;
    resize(300,300);
    setStyleSheet("QLineEdit{border-radius:3px;padding:3px}");
    nombre->setPlaceholderText("Nombre");
    ciudad->setPlaceholderText("Ciudad");
    direccion->setPlaceholderText("Dirección");
    rut->setPlaceholderText("RUT");
    numero->setPlaceholderText("Teléfono");
    correo->setPlaceholderText("Correo");

    QVariantMap user = db->userById(item->number);

    nombre->setText(user["name"].toString());
    ciudad->setText(user["city"].toString());
    direccion->setText(user["address"].toString());
    rut->setText(user["rut"].toString());
    numero->setText(user["phone"].toString());
    correo->setText(user["mail"].toString());

    layout->addWidget(nombre);
    layout->addWidget(ciudad);
    layout->addWidget(direccion);
    layout->addWidget(rut);
    layout->addWidget(numero);
    layout->addWidget(correo);
    layout->addWidget(bottom);

    bottomLayout->addWidget(cancel);
    bottomLayout->addWidget(del);
    bottomLayout->addWidget(save);


    setWindowTitle("Editor de Cliente");
    save->setFocus();

    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(cancelar(bool)));
    connect(save,SIGNAL(clicked(bool)),this,SLOT(guardar(bool)));
    connect(del,SIGNAL(clicked(bool)),this,SLOT(eliminar(bool)));


}

void EditClient::cancelar(bool mode)
{
    close();
}

void EditClient::guardar(bool mode)
{
    QVariantMap client = QVariantMap();
    client["id"] = clientIT->number;
    client["name"] = nombre->text();
    client["city"] = ciudad->text();
    client["address"] = direccion->text();
    client["rut"] = rut->text();
    client["phone"] = numero->text();
    client["mail"] = correo->text();

    db->clients.replace(db->clients.indexOf(db->userById(clientIT->number)),client);

    clientEdited();
    close();
}

void EditClient::eliminar(bool mode)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("El usuario y toda información relacioada a este será eliminada.");
    msgBox.setInformativeText("Desea continuar?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    if( ret == QMessageBox::Ok )
    {
        db->clients.removeOne(db->userById(clientIT->number));
        clientDeleted();
        close();
    }
}
