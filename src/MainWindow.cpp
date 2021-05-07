#include "include/MainWindow.h"

#include <QInputDialog>

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
        bool    ok   = false;
        QString name = QInputDialog::getText(this, tr("Add task"),
                                             tr("Task name"), QLineEdit::Normal,
                                             tr("Untitled task"), &ok);
        if (ok && not name.isEmpty())
                {
                        auto* task = new Task(name);
                        m_tasks.append(task);
                        ui->tasksLayout->addWidget(task);
                }
}
