#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include "FileHandler.h"
#include <QProcess>
#include <string>
#include <QString>
#include <string_view>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

	~MainWindow();
	Ui::MainWindow* accessUi();

public slots:
	void readXml();

private slots:
	void handleClear();

private:
	Ui::MainWindow* ui;
	XmlGraphReader* xmlHandler;
};
#endif // MAINWINDOW_H
