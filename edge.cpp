#include "edge.h"
#include "qmath.h"
#include <cmath>
#include <iostream>

Edge::Edge(Node* firstNode, Node* secondNode) : firstNode(firstNode), secondNode(secondNode)
{
}

bool Edge::operator==(const Edge& other)
{
	return (firstNode == other.firstNode) && (secondNode == other.secondNode);
}

Node* Edge::getFirst() const
{
	return firstNode;
}

Node* Edge::getSecond() const
{
	return secondNode;
}
