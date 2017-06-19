#ifndef MAINTABLEVIEW_H
#define MAINTABLEVIEW_H

#include <QWidget>

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
};

#endif // MAINTABLEVIEW_H
