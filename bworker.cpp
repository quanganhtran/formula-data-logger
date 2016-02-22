#include "bworker.h"

BWorker::BWorker()
{
    connect(&timer, SIGNAL (timeout()), this, SLOT (onTimeout()));
    timer.start(1000);
}

void BWorker::onTimeout()
{
    //qDebug()<<"Worker::onTimeout get called from?: "<<QThread::currentThreadId();
    emit updateVoltage(2, 18);
    emit updateTemp(3, 5);
}

