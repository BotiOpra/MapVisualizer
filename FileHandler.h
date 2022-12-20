#pragma once

#include <fstream>
#include <string>
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>

#include "Graph.h"

class XmlGraphReader
{
public:
	XmlGraphReader(const QString&, Graph* graph);
	bool read();

	inline void readMap();
	void readNode();
	void readEdge();

	~XmlGraphReader();
private:
	qint64 smallest{INT_MAX}, largest{INT_MIN};
	QString xmlName;
	Graph* curGraph;
	QFile* xmlFile;
	QXmlStreamReader* xmlReader;
};

