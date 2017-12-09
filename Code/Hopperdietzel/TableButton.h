#ifndef KK
#define KK

#include "headers.h"

class TableButton : public QPushButton
{
    Q_OBJECT

public:
    TableButton( const QString &tit)
    {
        setText(tit);
        setStyleSheet("border:none;background:transparent;color:#29ABE2;font-weight:bold");
    }
    int number = 0;
private:
    void mouseReleaseEvent(QMouseEvent *)
    {
        clickEvent(this);
    }
signals:
    void clickEvent(TableButton*);
};

#endif
