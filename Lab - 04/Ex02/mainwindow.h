// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <map>

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
    void onCountrySelected(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
    QListWidget *countryList;
    QLabel *languageLabel;
    QLabel *capitalLabel;
    std::map<QString, std::pair<QString, QString>> countryData;
    void initializeCountryData();
    void setupUI();
};
#endif // MAINWINDOW_H