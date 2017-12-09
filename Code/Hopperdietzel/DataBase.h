#ifndef DD
#define DD

#include "headers.h"
#include "window.h"
#include "usernamerequest.h"

class DataBase : public QObject
{

    Q_OBJECT

public:
    DataBase();
    QString settingsPath = EXPATH +"/settings.json";
    QString dbPath = EXPATH +"/db.json";

    void checkSettings();
    void checkDB();
    void loadApp();
    void saveData();

    int lastClientId();
    QVariantMap userById(int id);

    QVariantMap settings, db;
    QVariantList orders, clients;
    Window *mainWindow;

signals:

public slots:
    void namePicked(const QString &name);
};

#endif
