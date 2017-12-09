#ifndef FF
#define FF

#include "headers.h"

class Icon : public QLabel
{
    Q_OBJECT

public:
    Icon( const QPixmap &pix, QColor col)
    {
        storedPix = pix;
        setColor(col);
        setScaledContents(true);
    }
    void setColor( QColor col)
    {
        color = col;
        QImage im = storedPix.toImage();
        for( int x=0; x<im.width(); x++)
        {
            for( int y=0; y<im.width(); y++)
            {
                color.setAlpha(im.pixelColor(x,y).alpha());
                im.setPixelColor(x,y,color);
            }
        }
        setPixmap(QPixmap::fromImage(im));
    }

private:
    QPixmap storedPix;
    QColor color;

};
#endif
