#ifndef TOPBAR_H
#define TOPBAR_H

#include "Headers.h"


class TopBar : public QWidget
{
    Q_OBJECT
public:
    TopBar();
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *title = new QLabel("HOPPERDIETZEL");

signals:

public slots:
};

#endif // TOPBAR_H
