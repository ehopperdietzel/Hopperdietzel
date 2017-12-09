#ifndef LL
#define LL

#include "headers.h"

class TableItem : public QTableWidgetItem
{
public:
    TableItem( const QString &text)
    {
        setText(text);
        //setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QFont f = font();
        f.setPixelSize(10);
        setFont(f);
    }
};
#endif
