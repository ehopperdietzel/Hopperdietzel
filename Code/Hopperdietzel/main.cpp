#include "headers.h"
#include "dataBase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase *db = new DataBase();
    return a.exec();
}
