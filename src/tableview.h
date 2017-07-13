#ifndef MAINTABLEVIEW_H
#define MAINTABLEVIEW_H

#include <QWidget>
#include <QVector>
#include "videogames.h"
#include "database.h"
#include <QStandardPaths>
#include <QMessageBox>

#ifndef DEBUG
#define DEBUG 1
#include <QtDebug>
#endif

namespace Ui {
class MainTableView;
}

class MainTableView : public QWidget
{
    Q_OBJECT

public:
    explicit MainTableView(QWidget *parent = 0);
    ~MainTableView();

    /**
     * @brief LoadFromExistingDatabase
     * Checks for an existing database and loads it into a container for runtime operations
     * Note: Only works for debugging builds
     * @return bool : success or failed
     */
    bool LoadFromExistingDatabase();

    /**
     * @brief UpdateTableView
     * Repopulates table view with data from uiTableVector;
     */
    void UpdateTableView();

    /**
     * @brief ConvertToTableModel
     * Converts a Vector of VideoGames into a table model
     * @param tableVector
     * @return QSqlTableModel
     */
    QSqlTableModel* ConvertToTableModel(QVector<VideoGames> tableVector);

private slots:
    /**
     * @brief on_MTV_AddButton_clicked
     * Called Event when Add button is clicked
     */
    void on_MTV_AddButton_clicked();

    /**
     * @brief on_MTV_DeleteButton_clicked
     * Called Event when Delete button is clicked
     */
    void on_MTV_DeleteButton_clicked();

private:
    Ui::MainTableView *ui;

    Database* localDB;

    QVector<VideoGames> uiTableVector;
};

#endif // MAINTABLEVIEW_H
