#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datamanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
    ///dispaly qml
    DataManager *d=new DataManager;
    /// get file main.qml
    view= new QQuickView(QUrl(QLatin1String("qrc:/main.qml")));
    /// set data class datamanager to main qml
    view->engine()->rootContext()->setContextProperty("datamanager",d);
    ///set qml to widget
    qmlwidget=QWidget::createWindowContainer(view);
    /// horizontalLayout creat in ui
    ui->horizontalLayout->addWidget(qmlwidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
