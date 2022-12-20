#pragma once

#include "mainwindow.h"
#include <iostream>
#include "graph.h"
#include <QFrame>
#include <QMouseEvent>
#include <random>
#include <QPaintEvent>
#include <QPainter>
#include <cstdlib>
#include <cmath>
#include <queue>

#include "Utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class DrawableArea : public QFrame
{
public:
	DrawableArea(QWidget* parent = 0);
	~DrawableArea();

public:
	void mouseReleaseEvent(QMouseEvent* ev);
	void paintEvent(QPaintEvent* ev);

	void normalizeNodeCoords(Graph::NodeIterator node);

	void normalizeNodes();
	
	void reset();

	friend MainWindow;

private:
	Graph m_graph;
	Graph::NodeIterator m_firstNode;
	Graph::NodeIterator m_highlighted;
};

Node* ItrToPtr(const Graph::NodeIterator& itr);

