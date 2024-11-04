#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
    , currentIndex(0)
{
    ui->setupUi(this);
    //
    countryData = {
        {"Perú", "Lima"},
        {"Brasil", "Brasilia"},
        {"Argentina", "Buenos Aires"},
        {"Chile", "Santiago"},
        {"Colombia", "Bogotá"}
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Agregando nueva tarea...";
    if (currentIndex >= countryData.size()) {
        currentIndex = 0; // Volver al inicio si llegamos al final
    }

    auto countryPair = countryData[currentIndex];
    Task* task = new Task(countryPair.first, countryPair.second, this);
    mTasks.append(task);
    ui->verticalLayout->addWidget(task);

    connect(task, &Task::removed, this, &MainWindow::removeTask);

    currentIndex++;
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->verticalLayout->removeWidget(task);
    delete task;
}
