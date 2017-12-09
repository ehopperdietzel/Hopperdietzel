#ifndef NN
#define NN

#include "headers.h"

class UserNameRequest : public QWidget
{
    Q_OBJECT
public:
    QLineEdit *input;
    UserNameRequest()
    {
        QLabel *title = new QLabel("Identificación");
        title->setStyleSheet("font-weight:bold");
        QLabel *message = new QLabel("Ingrese su primer nombre:");
        input = new QLineEdit();
        input->setPlaceholderText("Nombre");
        QPushButton *ready = new QPushButton("Listo");

        connect(ready,SIGNAL(released()),this,SLOT(readyPSD()));

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(title);
        layout->addWidget(message);
        layout->addWidget(input);
        layout->addWidget(ready);

        setFixedSize(300,150);

        move(QPoint(
                 QApplication::primaryScreen()->size().width()/2,
                 QApplication::primaryScreen()->size().height()/2) -
                 QPoint(150,75));
        setWindowFlags(Qt::FramelessWindowHint);
        show();
    }

private slots:
    void readyPSD()
    {
        if(input->text().length() != 0)
        {
            namePicked(input->text());
            deleteLater();
        }
    }

signals:
    void namePicked( const QString &name);

};
#endif
