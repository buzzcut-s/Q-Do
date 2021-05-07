#include "include/Task.h"

#include <QInputDialog>

#include "ui_Task.h"

Task::Task(const QString& name, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
        ui->setupUi(this);
        setName(name);

        connect(ui->editTaskButton, &QPushButton::clicked,
                this, &Task::rename);
}

Task::~Task()
{
        delete ui;
}

void Task::setName(const QString& name)
{
        ui->checkbox->setText(name);
}

QString Task::name() const
{
        return ui->checkbox->text();
}

bool Task::isCompleted() const
{
        return ui->checkbox->isChecked();
}

void Task::rename()
{
        bool    ok    = false;
        QString value = QInputDialog::getText(this, tr("Edit task"),
                                              tr("Task name"), QLineEdit::Normal,
                                              this->name(), &ok);
        if (ok && not value.isEmpty())
                {
                        setName(value);
                }
}
