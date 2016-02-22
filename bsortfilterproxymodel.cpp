#include "bsortfilterproxymodel.h"
#include <QtDebug>

BSortFilterProxyModel::BSortFilterProxyModel(int column0, int row0, QObject *parent) : QSortFilterProxyModel(parent), column(column0), row(row0)
{

}

bool BSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    Q_UNUSED(sourceParent);
    if (row == -1) return true;
    return sourceRow == row;
}

bool BSortFilterProxyModel::filterAcceptsColumn(int sourceColumn, const QModelIndex &sourceParent) const {
    Q_UNUSED(sourceParent);
    if (column == 0) return true;
    return (sourceColumn == 0 || sourceColumn == column);
}

bool BSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);
    return leftData.toInt() < rightData.toInt();
}

