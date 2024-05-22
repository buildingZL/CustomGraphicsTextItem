#include "Widget.h"
#include "ui_Widget.h"

#include "CTextItem.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout *mainlayout = new QVBoxLayout;

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene,this);
    view->setScene(scene);

    scene->setSceneRect(0,0,400,400);

    CTextItem *text = new CTextItem;
    text->setPos(100,100);
    scene->addItem(text);

    mainlayout->addWidget(view);

    this->setLayout(mainlayout);
}

Widget::~Widget()
{
    delete ui;
}




