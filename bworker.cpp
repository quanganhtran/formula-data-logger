#include <cstdlib>
#include "bworker.h"

BWorker::BWorker()
{
    srand(time(NULL));

    connect(&timer, SIGNAL (timeout()), this, SLOT (onTimeout()));
    timer.start(200);
}

void BWorker::onTimeout()
{
    //qDebug()<<"Worker::onTimeout get called from?: "<<QThread::currentThreadId();
    for (int i = 0; i < 144; i++) {
//        int cell = rand() % 144;
//        emit updateVoltage(cell, rand() % 40 + 80);
//        emit updateTemp(cell, rand() % 100 + 50);

        emit updateVoltage(i, rand() % 40 + 80);
        emit updateTemp(i, rand() % 100 + 50);
    }
//    emit updateVoltage(2, 18);
//    emit updateTemp(3, 5);
}

