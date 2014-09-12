#ifndef TESTWIDGET_HPP
#define TESTWIDGET_HPP

#include "ui_TestWidget.h"

class TestWidget : public QWidget, private Ui::TestWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = 0);
};

#endif // TESTWIDGET_HPP
