#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCountrySelected(QListWidgetItem *item);  //para manejar la selección de país

private:
    Ui::MainWindow *ui;
    QMap<QString, QPair<QString, QString>> countryInfo; //para almacenar idioma y capital
};

#endif // MAINWINDOW_H
