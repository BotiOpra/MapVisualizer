#include "Utils.h"

qreal utils::calculateDistance(const QPointF& point1, const QPointF& point2)
{
    return std::sqrt(std::pow(point1.x() - point2.x(), 2) + std::pow(point1.y() - point2.y(), 2));
}
