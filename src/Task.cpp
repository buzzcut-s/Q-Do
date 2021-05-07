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
        connect(ui->checkbox, &QCheckBox::toggled,
                this, &Task::checked);

        connect(ui->removeTaskButton, &QPushButton::clicked,
                [this] { emit removed(this); });
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

void Task::checked(bool checked)
{
        QFont font(ui->checkbox->font());
        font.setStrikeOut(checked);
        ui->checkbox->setFont(font);

        emit statusChanged(this);
}
