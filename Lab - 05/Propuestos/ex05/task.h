#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& country, const QString& capital, QWidget *parent = nullptr);
    ~Task();

signals:
    void removed(Task* task);

private slots:
    void on_editButton_clicked();
    void on_quitarButton_clicked();

private:
    Ui::Task *ui;
    bool isEditing;
};

#endif
