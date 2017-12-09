#ifndef AA
#define AA

#include "headers.h"

class DataBase;

class AddClient : public QWidget
{
    Q_OBJECT
public:
    AddClient(DataBase *_db);

    QLineEdit *nombre = new QLineEdit();
    QLineEdit *ciudad = new QLineEdit();
    QLineEdit *direccion = new QLineEdit();
    QLineEdit *rut = new QLineEdit();
    QLineEdit *numero = new QLineEdit();
    QLineEdit *correo = new QLineEdit();

    QPushButton *cancel = new QPushButton("Cancelar");
    QPushButton *add = new QPushButton("Añadir");

    QWidget *bottom = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *bottomLayout = new QHBoxLayout(bottom);

    DataBase *db;


signals:
    void clientAdded();

public slots:
    void cancelar(bool mode);
    void añadir(bool mode);
};

#endif
