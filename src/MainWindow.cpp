#include "include/MainWindow.h"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        connect(ui->addTaskButton, &QPushButton::clicked,
                this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
        delete ui;
}

void MainWindow::addTask()
{
}
