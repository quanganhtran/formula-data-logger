#ifndef BCELLMODEL_H
#define BCELLMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include "bcell.h"

class BCellModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    BCellModel(QObject *parent = 0);
    BCellModel(QList<BCell> cells0, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

private:
    QList<BCell> cells;
};

#endif // BCELLMODEL_H
