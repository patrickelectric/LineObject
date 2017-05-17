#include <QQuickView>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("qrc:///main.qml"));
    ui->verticalLayout->addWidget(container);
}

MainWindow::~MainWindow()
{
    delete ui;
}
