#ifndef BSORTFILTERPROXYMODEL_H
#define BSORTFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>

class BSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    Q_OBJECT

public:
    //BSortFilterProxyModel(QObject *parent = 0);
    BSortFilterProxyModel(int column0 = 0, int row0 = -1, QObject *parent = 0);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    bool filterAcceptsColumn(int sourceColumn, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

private:
    int column;
    int row;
};

#endif // BSORTFILTERPROXYMODEL_H
