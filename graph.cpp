#include "graph.h"
#include <utility>
#include <exception>

Graph::Graph()
{
}

Graph::Graph(const Graph& other)
{
	this->nodes = other.nodes;
	this->edges = other.edges;	
}

Graph& Graph::operator=(const Graph& other)
{
	if (this == &other)
		return *this;
	this->nodes = other.nodes;
	this->edges = other.edges;
	return *this;
}

void Graph::setTitle(const QString& title)
{
	m_title = title;
}

const QString Graph::getTitle() const
{
	return m_title;
}

Graph& Graph::operator=(Graph&& other) noexcept
{
	if (this == &other)
		return *this;
	this->nodes = std::move(other.nodes);
	this->edges = std::move(other.edges);
	return *this;
}

Graph::EdgeIterator Graph::getEdge(Node* first, Node* second)
{
	/*modify*/
	return std::find(edges.begin(), edges.end(), Edge(first, second));
}

Graph::NodeContainer& Graph::getNodes()
{
	return nodes;
}

Graph::EdgeContainer& Graph::getEdges()
{
	return edges;
}

Graph::NodeIterator Graph::addNode(Node n)
{
	nodes.push_back(n);
	return --nodes.end();
}

// if edge was found, return iterator to edge that didn't allow insertion
Graph::EdgeIterator Graph::addEdge(Edge edge)
{
	EdgeIterator searchedEdge = std::find(edges.begin(), edges.end(), edge);
	if (searchedEdge != edges.end())
		return searchedEdge;
	edges.push_back(edge);

	return --edges.end();
	//edge.getFirst()->addAdjacentNode(edge.getSecond());
}

int Graph::getNodeCount()
{
	return (int)nodes.size();
}

void Graph::clear()
{
	nodes.clear();
	edges.clear();
}

Graph::NodeIterator Graph::getNode(const Node::InfoType& info)
{
	return std::find(nodes.begin(), nodes.end(), Node(info));
}

Graph::NodeIterator Graph::findNode(const QPointF& coords)
{
	for (auto itr = nodes.begin(); itr != nodes.end(); ++itr)
	{
		if (utils::calculateDistance(itr->getCoord(), coords) <= NodeSize)
			return itr;
	}
	return nodes.end();
}

Graph::~Graph() { /*EMPTY*/ }
