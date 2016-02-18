#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bcell.h"
#include "bcellmodel.h"
#include "bcelltablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QStandardItemModel* model = new QStandardItemModel(144,2,this);

//    for (int row = 0; row < 144; ++row) {
//        for (int column = 0; column < 2; ++column) {
//            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
//            model->setItem(row, column, item);
//        }
//    }
//    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Cell ID")));
//    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));

    QList<BCell> cells;
    for (int row = 0; row < 144; ++row) {
        BCell cell(row, 100 + row, 50 + row);
        cells.append(cell);
    }
    BCellModel* model = new BCellModel(cells);
    ui->tableViewMain->setModel(model);

    //==========
//    QList<QPair<QVariant, QVariant>> cells;
//    for (int row = 0; row < 144; ++row) {
//        QPair<QVariant, QVariant> cell(QVariant(row), QVariant(100));
//        cells.append(cell);
//    }

//    BCellTableModel* bmodel = new BCellTableModel(cells);
//    ui->tableViewMain->setModel(bmodel);

//    QThread dataThread;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}
