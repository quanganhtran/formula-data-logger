#ifndef BPARTIALPROXYMODEL_H
#define BPARTIALPROXYMODEL_H
#include <QtDebug>
#include <QSortFilterProxyModel>

class BPartialProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    BPartialProxyModel(QObject *parent = 0);
    BPartialProxyModel(int part0, QObject *parent = 0);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    //bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

private:
    int part;
};

#endif // BPARTIALPROXYMODEL_H
