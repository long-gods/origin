#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    ~Dialog();
protected:

private:
        QPoint pLast,poss;
        bool m_bPressed;
   void loadStyleSheet(const QString &sheetName);
private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
