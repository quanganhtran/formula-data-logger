#ifndef BCELLTABLEMODEL_H
#define BCELLTABLEMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <QPair>

class BCellTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    BCellTableModel(QObject *parent = 0);
    BCellTableModel(QList<QPair<QVariant, QVariant>> cells0, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

private:
    QList<QPair<QVariant, QVariant>> cells;
};

#endif // BCELLTABLEMODEL_H
