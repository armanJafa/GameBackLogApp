#ifndef MAINTABLEVIEW_H
#define MAINTABLEVIEW_H

#include <QWidget>

namespace Ui {
class MainTableView;
}

class MainTableView : public QWidget
{
    Q_OBJECT

public:
    explicit MainTableView(QWidget *parent = 0);
    ~MainTableView();

private:
    Ui::MainTableView *ui;
};

#endif // MAINTABLEVIEW_H
