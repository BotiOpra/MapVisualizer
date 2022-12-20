#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unordered_set>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) 
{
	ui->setupUi(this);

	xmlHandler = new XmlGraphReader("Harta_Test.xml", &ui->frame->m_graph);
	
	connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::handleClear);
	connect(ui->actionExit_2, &QAction::triggered, this, &MainWindow::close);
	connect(ui->actionXml, &QAction::triggered, this, &MainWindow::readXml);
}

MainWindow::~MainWindow()
{
	delete xmlHandler;
	delete ui;
}

Ui::MainWindow* MainWindow::accessUi()
{
	return ui;
}

void MainWindow::handleClear()
{
	ui->frame->reset();
}

void MainWindow::readXml()
{
	xmlHandler->read();
	ui->frame->normalizeNodes();
	ui->indicatorLabel->setText(ui->frame->m_graph.getTitle());
	update();
}
