#include "maintableview.h"
#include "ui_maintableview.h"

MainTableView::MainTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTableView)
{
    ui->setupUi(this);
}

MainTableView::~MainTableView()
{
    delete ui;
}
