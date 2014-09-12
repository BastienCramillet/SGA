#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>

class QPoint;
class MainView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();



signals:

public slots:

protected:

    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent ( QMouseEvent * event );
    void update();
    bool isInPoint(QPoint& point, QPointF& click);

private:

    QGraphicsScene* scene;
    std::vector<QPoint>* points;
    QPoint currentPoint;
    QGraphicsPolygonItem* currentPolygonItem;
    bool creation;
    QPolygon polygon;

};

#endif // MAINVIEW_HPP
