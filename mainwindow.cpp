//#include
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bcell.h"
#include "bcellmodel.h"
#include "bcelltablemodel.h"
#include "bpartialproxymodel.h"
#include "bsortfilterproxymodel.h"
#include "bworker.h"

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

    //==========
//    QList<BCell> cells;
//    for (int row = 0; row < 144; ++row) {
//        BCell cell(row, 100 + row, 50 + row);
//        cells.append(cell);
//    }
//    BCellModel* model = new BCellModel(cells);
//    ui->tableViewMain->setModel(model);

//    QThread t;
//    BWorker worker;

//    QObject::connect(&worker, SIGNAL(updateVoltage(int16_t,int16_t)), model, SLOT(onVoltageChanged(int16_t,int16_t)));
//    QObject::connect(&worker, SIGNAL(updateTemp(int16_t,int16_t)), model, SLOT(onTempChanged(int16_t,int16_t)));
//    worker.moveToThread(&t);

//    t.start();

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

MainWindow::MainWindow(QThread *thread0, QWidget *parent) :
    QMainWindow(parent),
    thread(new QThread),
    worker(new BWorker),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Data init
    QList<BCell> cells;
    for (int row = 0; row < 144; ++row) {
        BCell cell(row, 100 + row, 50 + row);
        cells.append(cell);
    }
    // Main model init
    BCellModel* model = new BCellModel(cells);
    //ui->tableViewMain->setModel(model);

    // Partial proxy init
//    BPartialProxyModel* part1 = new BPartialProxyModel(0, this);
//    part1->setSourceModel(model);
//    ui->tView1->setModel(part1);
    QTableView* views[] = { ui->tView0, ui->tView1, ui->tView2, ui->tView3, ui->tView4, ui->tView5 };
    for (int i = 0; i < 6; i++) {
        BPartialProxyModel* part = new BPartialProxyModel(i, this);
        part->setSourceModel(model);
        //QTableView* partialView = new QTableView();
        //partialView->setModel(part);
        //ui->horizontalLayout->addWidget(partialView);
        //views[i]->setColumnWidth(0, 50);
        views[i]->setModel(model);
    }

    // Sorted proxy init
    BSortFilterProxyModel* vSorted = new BSortFilterProxyModel();
    vSorted->setSourceModel(model);
    vSorted->sort(1, Qt::DescendingOrder);
    BSortFilterProxyModel* maxVoltage = new BSortFilterProxyModel(1, 0);
    maxVoltage->setSourceModel(vSorted);
    ui->tViewMaxVolt->setModel(maxVoltage);
    BSortFilterProxyModel* minVoltage = new BSortFilterProxyModel(1, 143);
    minVoltage->setSourceModel(vSorted);
    ui->tViewMinVolt->setModel(minVoltage);


    BSortFilterProxyModel* tSorted = new BSortFilterProxyModel();
    tSorted->setSourceModel(model);
    tSorted->sort(2, Qt::DescendingOrder);
    BSortFilterProxyModel* maxTemp = new BSortFilterProxyModel(2, 0);
    maxTemp->setSourceModel(tSorted);
    ui->tViewMaxTemp->setModel(maxTemp);
    BSortFilterProxyModel* minTemp = new BSortFilterProxyModel(2, 143);
    minTemp->setSourceModel(tSorted);
    ui->tViewMinTemp->setModel(minTemp);

    // Thread init
    QObject::connect(worker, SIGNAL(updateVoltage(int16_t,int16_t)), model, SLOT(onVoltageChanged(int16_t,int16_t)));
    QObject::connect(worker, SIGNAL(updateTemp(int16_t,int16_t)), model, SLOT(onTempChanged(int16_t,int16_t)));

    worker->moveToThread(thread);
    thread->start();
}

MainWindow::~MainWindow()
{
    delete thread;
    delete worker;
    delete ui;
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}
