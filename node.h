#ifndef NODE_H
#define NODE_H

#define NodeSize 3

#include <QPointF>
#include <cmath>
#include <stdint.h>
#include <list>
#include <vector>

class Node;

qreal calculateDistance(const QPointF& point1, const QPointF& point2);

class Node
{
public:
	using InfoType = int;
private:
	InfoType info;
	QPointF coord;
	bool m_isClicked;

	// hw 4
public:
	Node(bool isClicked = false);
	Node(const InfoType& info);
	Node(QPointF coord);
	Node(QPointF coord, int info);
	Node(const Node& other);

	bool operator==(const Node& other);
	QPointF getCoord() const;
	void setCoord(QPointF coord);
	int getInfo() const;
	void setInfo(int info);
};

#endif // NODE_H
