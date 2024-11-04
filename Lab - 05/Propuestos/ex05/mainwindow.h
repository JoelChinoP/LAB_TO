#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void removeTask(Task* task);

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;
    QVector<QPair<QString, QString>> countryData;
    int currentIndex;
};
#endif // MAINWINDOW_H
