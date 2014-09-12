#include "include/View.hpp"
#include <QMouseEvent>
#include <QGraphicsRectItem>

View::View(QObject *parent) :
    QGraphicsScene(parent)
{
}

void View::mousePressEvent ( QMouseEvent * event )
{

//    scene->clear();

    QGraphicsRectItem* item = new QGraphicsRectItem(event->pos().x()-5, event->pos().y()-5, 10, 10);

    addItem(item);

//    qDebug() << QString::number(pt.x()) << " et " << QString::number(pt.y());

//    if (points->empty())
//    {
//        points->push_back(QPoint(pt.x(), pt.y()));
//    }

//    for (QPoint point : *points)
//    {
//        qDebug() << "point : " << QString::number(point.x()) << " et " << QString::number(point.y());
//        if (isInPoint(point, pt))
//        {
//            scene->addLine(0,0,pt.x(), pt.y());
//        }
//        else
//        {
//            points->push_back(QPoint(pt.x(), pt.y()));
//        }
//    }


//    scene->addRect(pt.x()-5, pt.y()-5, 10, 10);
//    scene->addLine(0,0,pt.x(), pt.y());
//    update();
}
