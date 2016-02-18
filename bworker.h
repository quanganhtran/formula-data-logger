#ifndef BWORKER_H
#define BWORKER_H


class BWorker
{
public:
    BWorker(int id0);
    ~BWorker();
    int id;
    int voltage = 0;
    int temp = 0;
};

#endif // BWORKER_H
