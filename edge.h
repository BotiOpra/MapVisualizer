#ifndef ARC_H
#define ARC_H

#include "node.h"
#include <QLine>

class Edge
{
    Node *firstNode, *secondNode;
public:
    Edge();
    Edge(Node *firstNode, Node *secondNode);

    bool operator==(const Edge& other);

    Node *getFirst() const;
    Node *getSecond() const;
};

#endif // ARC_H
