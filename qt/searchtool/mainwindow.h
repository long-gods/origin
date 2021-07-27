#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void insertrow(int i,int j);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu *pop;
    QAction *action;
public slots:
    void search(QString name);
private slots:
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
};

#endif // MAINWINDOW_H
