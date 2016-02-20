#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include "bworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QThread *thread0, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_exitBtn_clicked();

private:
    QThread *thread;
    BWorker *worker;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
