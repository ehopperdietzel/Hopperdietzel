#ifndef WINDOW_H
#define WINDOW_H

#include "Headers.h"
#include "TopBar.h"
#include "LeftBar.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    // Main Window
    Window();

    // Bottom container
    QWidget *bottomContainer = new QWidget();

    // Bars
    TopBar *mainTopBar = new TopBar();
    LeftBar *leftBar = new LeftBar();

    // Layouts
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QHBoxLayout *horizontalLayout = new QHBoxLayout(bottomContainer);




};

#endif // WINDOW_H
