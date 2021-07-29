#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemWatcher>
#include<windows.h>
#include<QDir>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void insertrow(int i,int j,QFileInfoList fileinfolist);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    ~MainWindow();

private:
    bool check=false;
    Ui::MainWindow *ui;
    QMenu *pop;
    QFileSystemWatcher *watch;
    QAction *action;
    QAction *action2;
    QString path="C:\\Users\\wps\\Desktop";
    QString filename;

public slots:
    void search(QString name);
    void filesearch(QString path);
private slots:
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void on_action_triggered();
    void start();
    void del();
};

#endif // MAINWINDOW_H
