#include "task.h"
#include "./ui_task.h"

Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}

void Task::on_removeButton_clicked()
{
    emit removed(this);
}
