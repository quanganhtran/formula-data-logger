#include "bcelltablemodel.h"

BCellTableModel::BCellTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

BCellTableModel::BCellTableModel(QList<QPair<QVariant, QVariant> > cells0, QObject *parent) : QAbstractTableModel(parent)
{
    cells = cells0;
}

int BCellTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 144;
}

int BCellTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant BCellTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= cells.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        QPair<QVariant, QVariant> pair = cells.at(index.row());

        if (index.column() == 0)
            return pair.first;
        else if (index.column() == 1)
            return pair.second;
    }
    return QVariant();
}

QVariant BCellTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Voltage");

        case 1:
            return tr("Temperature");

        default:
            return QVariant();
        }
    }
    return QVariant();
}
