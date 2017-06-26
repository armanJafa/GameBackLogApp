#include "tableview.h"
#include "ui_maintableview.h"

MainTableView::MainTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTableView)
{
    ui->setupUi(this);

    //If database fails to load, display warning
    if(!LoadFromExistingDatabase())
    {
        QMessageBox errorDialog;
        errorDialog.setText("Database Failed to Load Correctly!");
        errorDialog.setInformativeText("The path to database may not exist or be correct.");
        errorDialog.setIcon(QMessageBox::Warning);
        errorDialog.exec();
    }
    else
    {
        //Updates Table view with data from database
        UpdateTableView();
    }

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

    for(int i = 0; i < uiTableVector.size(); i++)
    {
        ui->MTV_TableView->model()->insertRow(ui->MTV_TableView->model()->rowCount());
    }


//    ui->MTV_TableView->setCurrentIndex();
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
