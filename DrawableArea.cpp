#include "DrawableArea.h"

DrawableArea::DrawableArea(QWidget* parent) : QFrame(parent)
{
	m_firstNode = m_graph.getNodes().end();
	m_highlighted = m_graph.getNodes().end();
}

DrawableArea::~DrawableArea() {}

void DrawableArea::mouseReleaseEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
		m_highlighted = m_graph.findNode(ev->position());
	update();
}

void DrawableArea::paintEvent(QPaintEvent* ev)
{
	Q_UNUSED(ev);

	QPainter painter(this);
	for (auto itr = m_graph.getNodes().begin(); itr != m_graph.getNodes().end(); ++itr)
	{
		painter.setPen(QPen(Qt::black, NodeSize));
		painter.setBrush(Qt::black);
		if (m_highlighted == itr)
		{
			painter.setPen(QPen(Qt::red, NodeSize + 3));
			painter.setBrush(Qt::red);
		}
		painter.drawEllipse(QPointF(itr->getCoord()), NodeSize, NodeSize);
	}

	painter.setPen(Qt::black);

	for (const Edge& a : m_graph.getEdges())
	{
		QLineF edgeLine(a.getFirst()->getCoord(), a.getSecond()->getCoord());
		painter.drawLine(edgeLine);
	}
	update();
}

void DrawableArea::normalizeNodeCoords(Graph::NodeIterator node)
{
	qint32 frameWidth = frameGeometry().width();
	qint32 frameHeight = frameGeometry().height();
	qint32 normalizedX = qint32(node->getCoord().x()) % this->frameGeometry().width();
	qint32 normalizedY = qint32(node->getCoord().y()) % this->frameGeometry().height();
	node->setCoord(QPoint(normalizedX, normalizedY));
}

void DrawableArea::normalizeNodes()
{
	for (auto itr = m_graph.getNodes().begin(); itr != m_graph.getNodes().end(); ++itr)
		normalizeNodeCoords(itr);
}

void DrawableArea::reset()
{
	m_graph.clear();
	m_firstNode = m_graph.getNodes().end();
	m_highlighted = m_graph.getNodes().end();
	update();
}

Node* ItrToPtr(const Graph::NodeIterator& itr)
{
	return &*itr;
}
