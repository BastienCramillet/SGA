#ifndef VIEW_HPP
#define VIEW_HPP

#include <QGraphicsScene>
#include <QMouseEvent>

class View : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit View(QObject *parent = 0);
    void mousePressEvent ( QMouseEvent * event );

signals:

public slots:

};

#endif // VIEW_HPP
