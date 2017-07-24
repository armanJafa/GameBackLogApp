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

//Force the Table to update and go into No Edit Mode, ReadOnly table
void MainTableView::UpdateTableView()
{
    //Read-only Update
    ui->MTV_TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Hide Vertical Header
    ui->MTV_TableView->verticalHeader()->setVisible(false);

    //Call ConvertFunction to update the table
    ui->MTV_TableView->clear();

    ConvertToTableModel(uiTableVector);

    //Display new stuff
    ui->MTV_TableView->show();

}

//Takes a Vector of VideoGames and converts it into a TableModel
void MainTableView::ConvertToTableModel(QVector<VideoGames> tableVector)
{

//    QSqlTableModel* model = new QSqlTableModel;

//    model->setHeaderData(0, Qt::Orientation::Horizontal, QObject::tr("Title"),0);
//    model->setHeaderData(1, Qt::Orientation::Horizontal, QObject::tr("Year of Release"),0);
//    model->setHeaderData(2, Qt::Orientation::Horizontal, QObject::tr("Platform"),0);
//    model->setHeaderData(3, Qt::Orientation::Horizontal, QObject::tr("ESRB"),0);
//    model->setHeaderData(4, Qt::Orientation::Horizontal, QObject::tr("Developer"),0);
//    model->setHeaderData(5, Qt::Orientation::Horizontal, QObject::tr("Publisher"),0);

    QStringList stringlist;
    stringlist << "Title" << "Year of Release" << "Platform" << "ESRB" << "Developer" << "Publisher";
    ui->MTV_TableView->setHorizontalHeaderLabels(stringlist);


    for(int i = 0; i < tableVector.size(); i++)
    {
        //DEBUG
        qDebug() << tableVector.size() << " Inside for";

//        model->insertRows(i, 1);
//        model->setData(model->index(i, 0), tableVector[i].GetTitle());
//        model->setData(model->index(i, 1), tableVector[i].GetYearOfRelease());
//        model->setData(model->index(i, 2), tableVector[i].GetPlatform());
//        model->setData(model->index(i, 3), tableVector[i].GetESRB());
//        model->setData(model->index(i, 4), tableVector[i].GetDeveloper());
//        model->setData(model->index(i, 5), tableVector[i].GetPublisher());
//        model->submitAll();


        ui->MTV_TableView->insertRow(i);

        QTableWidgetItem *dataItem = new QTableWidgetItem;

        dataItem->setData(Qt::DisplayRole, tableVector[i].GetTitle());
        ui->MTV_TableView->setItem(i, 0, dataItem);

        dataItem = new QTableWidgetItem;
        dataItem->setData(Qt::DisplayRole, tableVector[i].GetYearOfRelease());
        ui->MTV_TableView->setItem(i, 1, dataItem);
    }

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
