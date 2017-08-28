#include "Window.h"

Window::Window()
{
    setWindowTitle("Administrador Hopperdietzel");
    resize(800,600);

    verticalLayout->setSpacing(0);
    verticalLayout->setMargin(0);
    verticalLayout->addWidget(mainTopBar);
    verticalLayout->addWidget(bottomContainer,1);

    horizontalLayout->setSpacing(0);
    horizontalLayout->setMargin(0);


}


