#include "tableview.h"
#include "ui_maintableview.h"

MainTableView::MainTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTableView)
{
    ui->setupUi(this);

    ///Get local app directory
    QString dir = QDir::currentPath();
    QDir::
    dir.resize(dir.lastIndexOf("/build"));
    dir+= "/src/database/";

    //Load in existing database
    localDB = new Database( dir + "GameDB_TestRecord.db", "QSQLITE");

    //DEBUG
    localDB->GetAllGames();

    qDebug() << dir;

}

MainTableView::~MainTableView()
{
    delete ui;
}

void MainTableView::on_MTV_AddButton_clicked()
{
    //TODO Call Push to Temporary QVector, Update Table, Add Dynamically Show Save/Cancel Button
    //DEBUG
    if(DEBUG)
    {
        qDebug() << "Clicked Add Button";
    }
}

void MainTableView::on_MTV_DeleteButton_clicked()
{
    //TODO Call Pop_at on Temporary QVector, Update Table, Add Dynamically Show Save/Cancel Button
    //DEBUG
    if(DEBUG)
    {
        qDebug() << "Clicked Delete Button";
    }
}
