#ifndef BWORKER_H
#define BWORKER_H
#include <QtCore>

class BWorker : public QObject
{
    Q_OBJECT
public:
    BWorker();
private slots:
    void onTimeout();
signals:
    void updateVoltage(int16_t id, int16_t value);
    void updateTemp(int16_t id, int16_t value);
private:
    QTimer timer;
};

#endif // BWORKER_H
