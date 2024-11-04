#include "task.h"
#include "./ui_task.h"
#include <QDebug>

Task::Task(const QString& country, const QString& capital, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
    , isEditing(false)
{
    ui->setupUi(this);

    // Inicializar los campos
    ui->taskEdit->setText(country);
    ui->capitalEdit->setText(capital);

    // Deshabilitar edición inicialmente
    ui->taskEdit->setReadOnly(true);
    ui->capitalEdit->setReadOnly(true);
}

Task::~Task()
{
    delete ui;
}

void Task::on_editButton_clicked()
{
    isEditing = !isEditing;

    if (isEditing) {
        ui->editButton->setText("Guardar");
        ui->taskEdit->setReadOnly(false);
        ui->capitalEdit->setReadOnly(false);
    } else {
        ui->editButton->setText("Editar");
        ui->taskEdit->setReadOnly(true);
        ui->capitalEdit->setReadOnly(true);
    }
}

void Task::on_quitarButton_clicked()
{
    emit removed(this);
}
