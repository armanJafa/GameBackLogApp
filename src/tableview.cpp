#include "tableview.h"
#include "ui_maintableview.h"

MainTableView::MainTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTableView)
{
    ui->setupUi(this);

    LoadFromExistingDatabase();
}

MainTableView::~MainTableView()
{
    delete ui;
}

bool MainTableView::LoadFromExistingDatabase()
{
    bool ok = false;

    ///Get local app directory
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(path);

    if(!dir.exists())
        dir.mkdir(path);

    path.append("/GameDB.db");
    //Load in existing database
    localDB = new Database(path, "QSQLITE");

    if(localDB->isValid())
    {
        uiTableVector = localDB->GetAllGames();
        ok = true;
    }



    //Debug
    qDebug() << path;

    return ok;
}

void MainTableView::UpdateTableView()
{

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
