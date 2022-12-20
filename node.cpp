#include "node.h"

Node::Node(bool isClicked)
	: info(InfoType()), coord(QPointF()), m_isClicked(isClicked)
{
}

Node::Node(const InfoType& info)
	:info(info), coord(QPointF()), m_isClicked(false)
{
}

Node::Node(QPointF coord)
	: info(InfoType()), coord(coord), m_isClicked(false)
{
}

Node::Node(QPointF coord, int info) : info(info), coord(coord), m_isClicked(false)
{

}

Node::Node(const Node& other)
{
	info = other.info;
	coord = other.coord;
	m_isClicked = other.m_isClicked;
}

bool Node::operator==(const Node& other)
{
	return this->info == other.info;
}

QPointF Node::getCoord() const { return coord; }
int Node::getInfo() const { return info; }
void Node::setCoord(QPointF coord) { this->coord = coord; }
void Node::setInfo(int info) { this->info = info; }

qreal calculateDistance(const QPointF& point1, const QPointF& point2)
{
	return std::sqrt(std::pow(point1.x() - point2.x(), 2) + std::pow(point1.y() - point2.y(), 2));
}
