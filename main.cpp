#include "mainwindow.h"
#include <QApplication>
#include "bcell.h"
#include "bcellmodel.h"
#include "bcelltablemodel.h"
#include "bworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;

    qRegisterMetaType<int16_t>("int16_t");

    QThread thread;
    MainWindow w(&thread);

//    QList<BCell> cells;
//    for (int row = 0; row < 144; ++row) {
//        BCell cell(row, 100 + row, 50 + row);
//        cells.append(cell);
//    }
//    BCellModel* model = new BCellModel(cells);

//    QThread t;
//    BWorker worker;

//    QObject::connect(&worker, SIGNAL(updateVoltage(int16_t,int16_t)), model, SLOT(onVoltageChanged(int16_t,int16_t)));
//    QObject::connect(&worker, SIGNAL(updateTemp(int16_t,int16_t)), model, SLOT(onTempChanged(int16_t,int16_t)));
//    worker.moveToThread(&t);

//    t.start();

//    thread.start();

    w.show();

    return a.exec();
}
