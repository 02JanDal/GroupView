#include "CategorizedProxyModel.h"

#include "CategorizedView.h"

CategorizedProxyModel::CategorizedProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
}
bool CategorizedProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	const QString leftCategory = left.data(CategorizedViewRoles::CategoryRole).toString();
	const QString rightCategory = right.data(CategorizedViewRoles::CategoryRole).toString();
	if (leftCategory == rightCategory)
	{
		return left.row() < right.row();
	}
	else
	{
		return leftCategory < rightCategory;
	}
}
