#include "bpartialproxymodel.h"

BPartialProxyModel::BPartialProxyModel(int part0, QObject *parent) : QSortFilterProxyModel(parent), part(part0)
{

}

bool BPartialProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    Q_UNUSED(sourceParent);
    return (sourceRow / 24 == part);
}
