#ifndef EE
#define EE

#include "headers.h"
#include "tablebutton.h"
#include "database.h"

class EditClient : public QWidget
{
    Q_OBJECT
public:
    EditClient(DataBase *_db, TableButton *item);

    QLineEdit *nombre = new QLineEdit();
    QLineEdit *ciudad = new QLineEdit();
    QLineEdit *direccion = new QLineEdit();
    QLineEdit *rut = new QLineEdit();
    QLineEdit *numero = new QLineEdit();
    QLineEdit *correo = new QLineEdit();

    QPushButton *cancel = new QPushButton("Cancelar");
    QPushButton *save = new QPushButton("Guardar");
    QPushButton *del = new QPushButton("Eliminar");

    QWidget *bottom = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *bottomLayout = new QHBoxLayout(bottom);

    TableButton *clientIT;
    DataBase *db;


signals:
    void clientEdited();
    void clientDeleted();

public slots:
    void cancelar(bool mode);
    void guardar(bool mode);
    void eliminar(bool mode);
};

#endif
