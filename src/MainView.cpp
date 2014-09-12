#include "MainView.hpp"
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QGraphicsItem>

MainView::MainView(QWidget *parent) :
    QGraphicsView(parent)
{

    scene = new QGraphicsScene(this);
    setScene(scene);
    this->setSceneRect(0, 0, 1000, 1000);
    setBackgroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

    points = new std::vector<QPoint>();

    //currentPoint = nullptr;
    currentPolygonItem = nullptr;
    creation = false;
}

MainView::~MainView()
{
    delete scene;
    points->clear();
    delete points;
}

void MainView::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
            currentPolygonItem = scene->addPolygon(polygon, QPen(Qt::SolidLine));
            creation = true;
            break;

        case Qt::Key_Right:
            creation = false;
            scene->removeItem(currentPolygonItem);
            break;

    case Qt::Key_Up:
        creation = false;
        QPolygonF poly;
        poly << QPointF(100,100) << QPointF(200,100) << QPointF(152,200) << QPointF(100,200);
        scene->addPolygon(poly, QPen(Qt::SolidLine));
        break;
    }
}

void MainView::mousePressEvent ( QMouseEvent * event )
{

//    scene->clear();
    QPointF pt = mapToScene(event->pos());


    if (creation)
    {
        QGraphicsRectItem* item = new QGraphicsRectItem(pt.x()-5, pt.y()-5, 10, 10);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
        scene->addItem(item);

        QPolygonF poly = currentPolygonItem->polygon();
        poly << pt;
        currentPolygonItem->setPolygon(poly);
    }
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
    QGraphicsView::mousePressEvent(event);
}

bool MainView::isInPoint(QPoint &point, QPointF &click)
{
    if (point.x()-5 > click.x()) return false;
    if (point.x()+5 < click.x()) return false;
    if (point.y()-5 > click.y()) return false;
    if (point.y()+5 < click.y()) return false;

    return true;
}

void MainView::update()
{
    scene->clear();

    for (QPoint point : *points)
    {
        scene->addRect(point.x()-5, point.y()-5, 10, 10);
    }
}
