#include "database.h"

DataBase::DataBase()
{
    checkSettings();
}

void DataBase::checkSettings()
{

    if(QFileInfo::exists(settingsPath))
    {
        QFile file(settingsPath);
        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            settings = doc.toVariant().toMap();
            file.close();
            checkDB();
        }
    }
    else
    {
        UserNameRequest *req = new UserNameRequest();
        connect(req,SIGNAL(namePicked(QString)),this,SLOT(namePicked(QString)));
    }
}

void DataBase::checkDB()
{
    if(QFileInfo::exists(dbPath))
    {
        QFile file(dbPath);
        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            db = doc.toVariant().toMap();
            clients = db["clients"].toList();
            orders = db["orders"].toList();
            file.close();
            loadApp();
        }
    }
    else
    {
        db["id"] = 0;
        db["uploader"] = settings["user"].toString();
        db["date"] = QDate::currentDate().toString("dd:MM:yyyy");
        db["orders"] = QVariantList();
        db["clients"] = QVariantList();

        clients = db["clients"].toList();
        orders = db["orders"].toList();

        QFile file(dbPath);
        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument doc = QJsonDocument::fromVariant(db);
            file.write(doc.toJson());
            loadApp();
        }

    }
}

void DataBase::loadApp()
{
    mainWindow = new Window(this);
}

void DataBase::saveData()
{
    // Save Settings
    QVariantMap window;
    window["x"] = mainWindow->x();
    window["y"] = mainWindow->y();
    window["w"] = mainWindow->width();
    window["h"] = mainWindow->height();
    settings["window"] = window;

    QFile file(settingsPath);
    if (file.open(QIODevice::ReadWrite))
    {
        QJsonDocument doc = QJsonDocument::fromVariant(settings);
        file.write(doc.toJson());
        file.close();
    }

    // Save DataBase

    db["clients"] = clients;
    db["orders"] = orders;

    QFile fil(dbPath);
    if (fil.open(QIODevice::ReadWrite))
    {
        QJsonDocument doc = QJsonDocument::fromVariant(db);
        fil.write(doc.toJson());
        loadApp();
    }
}

int DataBase::lastClientId()
{
    int id = -1;
    foreach (QVariant c, clients)
    {
       QVariantMap client = c.toMap();
       if(client["id"].toInt() > id)
           id = client["id"].toInt();
    }
    return id;
}

QVariantMap DataBase::userById(int id)
{
    QVariantMap client = QVariantMap();
    foreach (QVariant c, clients)
    {
       client = c.toMap();
       if(client["id"].toInt() == id)
           return client;
    }
    return client;
}

void DataBase::namePicked(const QString &name)
{
    settings["user"] = name;
    settings["menu"] = 0;
    settings["device"] = "MacBook";

    QVariantMap window;
    window["x"] = QApplication::primaryScreen()->size().width()/2 - 500;
    window["y"] = QApplication::primaryScreen()->size().height()/2 - 350;
    window["w"] = 1000;
    window["h"] = 700;

    settings["window"] = window;

    QVariantMap clientsView;
    clientsView["aW"] = 100;
    clientsView["bW"] = 100;
    clientsView["cW"] = 100;
    clientsView["dW"] = 100;
    clientsView["eW"] = 100;
    clientsView["fW"] = 100;

    settings["clientsTable"] = clientsView;

    QFile file(settingsPath);
    if (file.open(QIODevice::ReadWrite))
    {
        QJsonDocument doc = QJsonDocument::fromVariant(settings);
        file.write(doc.toJson());
        file.close();
        loadApp();        
    }
}
