#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
{
    ui->setupUi(this);
    //connect(ui->addTaskButton, &QPushButton::clicked,
    //        this, &MainWindow::on_addTaskButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Agregando nueva tarea...";
    Task* task = new Task(this);
    mTasks.append(task);
    ui->verticalLayout->addWidget(task);

    connect(task, &Task::removed, this, &MainWindow::removeTask);
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->verticalLayout->removeWidget(task);
    delete task;
}
