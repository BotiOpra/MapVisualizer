#ifndef GRAF_H
#define GRAF_H

#include "edge.h"
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <stack>
#include <algorithm>
#include <QDebug>

#include "Utils.h"

class Graph
{
public:
	using NodeContainer = std::list<Node>;
	using EdgeContainer = std::vector<Edge>;

	using NodeIterator = NodeContainer::iterator;
	using EdgeIterator = EdgeContainer::iterator;
private:
	QString m_title;

	NodeContainer nodes;
	EdgeContainer edges;

public:
	Graph();

	Graph(const Graph& other);
	Graph& operator=(Graph&& other) noexcept;
	Graph& operator=(const Graph& other);

	void setTitle(const QString&);
	const QString getTitle() const;

	NodeContainer& getNodes();
	EdgeContainer& getEdges();
	NodeIterator addNode(Node n);
	EdgeIterator addEdge(Edge arc);

	int getNodeCount();
	void clear();

	NodeIterator getNode(const Node::InfoType&);
	EdgeIterator getEdge(Node* first, Node* second);

	NodeIterator findNode(const QPointF& coords);
	~Graph();
};

#endif // GRAF_H
