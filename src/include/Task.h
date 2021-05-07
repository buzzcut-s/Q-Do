#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QWidget>

namespace Ui
{
class Task;
}

class Task : public QWidget
{
        Q_OBJECT

public:
        explicit Task(const QString& name, QWidget* parent = nullptr);
        ~Task();

        void    setName(const QString& name);
        QString name() const;
        bool    isCompleted() const;

private:
        Ui::Task* ui;
};

#endif  // TASK_H
