#include "bcellmodel.h"

BCellModel::BCellModel(QObject *parent) : QAbstractTableModel(parent)
{

}

BCellModel::BCellModel(QList<BCell> cells0, QObject *parent) : QAbstractTableModel(parent)
{
    cells = cells0;
}

int BCellModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 144;
}

int BCellModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant BCellModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= cells.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        BCell cell = cells.at(index.row());

        if (index.column() == 0)
            return QVariant(cell.id);
        else if (index.column() == 1)
            return QVariant(cell.voltage);
        else if (index.column() == 2)
            return QVariant(cell.temp);
    }
    return QVariant();
}

QVariant BCellModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Cell ID");

        case 1:
            return tr("Voltage");

        case 2:
            return tr("Temperature");

        default:
            return QVariant();
        }
    }
    return QVariant();
}
