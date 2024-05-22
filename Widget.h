#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QPushButton>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // WIDGET_H
