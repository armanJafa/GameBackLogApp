#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //When main window is created,
    //Initialize the table view, set this to it's parent and show it
    tableView = new MainTableView();
    tableView->setParent(this);

    centralWidget()->layout()->addWidget(tableView);

    tableView->show();

}

MainWindow::~MainWindow()
{
    //Destroy TableView
    //TODO tableview cleanup
    delete tableView;

    delete ui;
}
