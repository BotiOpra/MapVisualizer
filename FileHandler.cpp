#include "FileHandler.h"

bool XmlGraphReader::read()
{
	xmlReader->clear();
	if (!xmlFile->reset())
		xmlReader->raiseError(QObject::tr("File couldn't be reset"));
	xmlReader->setDevice(xmlFile);

	if (xmlReader->readNextStartElement()) {
		if (xmlReader->name().toString() == "map")
		{
			curGraph->setTitle(xmlReader->attributes().value("description").toString());
			readMap();
		}
	}
	else
	{
		xmlReader->raiseError(QObject::tr("Not a map file"));
		return !xmlReader->error();
	}

}

XmlGraphReader::XmlGraphReader(const QString& name, Graph* graph) : xmlName(name), xmlFile(new QFile(xmlName)), curGraph(graph)
{
	if (!curGraph)
	{
		qCritical() << "Graph doesn't exist";
		return;
	}

	if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
		qCritical() << "Couldn't open xmlfile.xml to load settings for download";
		return;
	}

	if (!curGraph->getNodes().empty() || !curGraph->getEdges().empty())
	{
		qCritical() << "Graph must be empty";
		return;
	}

	xmlReader = new QXmlStreamReader(xmlFile);
}

inline void XmlGraphReader::readMap()
{
	xmlReader->readNextStartElement();
	Q_ASSERT(xmlReader->name().toString() == "nodes");

	qDebug() << xmlReader->name();
	while (xmlReader->readNextStartElement())
	{
		qDebug() << xmlReader->name();
		if (xmlReader->name().toString() == "node")
		{
			readNode();
			xmlReader->readNext();
		}
	}
}

void XmlGraphReader::readNode()
{
	Q_ASSERT(xmlReader->name().toString() == "node");

	Node::InfoType info = xmlReader->attributes().value("id").toInt();
	qint32 latitude = xmlReader->attributes().value("latitude").toInt();
	qint32 longitude = xmlReader->attributes().value("longitude").toInt();

	if (smallest > latitude)
		smallest = latitude;
	if (largest < latitude)
		largest = latitude;
	QPoint coordinates(latitude, longitude);

	Node newNode(QPoint(coordinates.x(), coordinates.y()), info);
	curGraph->addNode(newNode);
}

void XmlGraphReader::readEdge()
{
}

XmlGraphReader::~XmlGraphReader()
{
	xmlFile->close();
	xmlReader->clear();
}
