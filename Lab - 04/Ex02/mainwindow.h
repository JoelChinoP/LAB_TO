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

// mainwindow.cpp
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeCountryData();
    setupUI();
    
    // Conectar la señal de selección con el slot
    connect(countryList, &QListWidget::itemClicked, 
            this, &MainWindow::onCountrySelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeCountryData()
{
    // Inicializar datos de países: País -> {Idioma, Capital}
    countryData["Perú"] = {"Español", "Lima"};
    countryData["Brasil"] = {"Portugués", "Brasilia"};
    countryData["Francia"] = {"Francés", "París"};
    countryData["Japón"] = {"Japonés", "Tokio"};
    countryData["Italia"] = {"Italiano", "Roma"};
    countryData["Alemania"] = {"Alemán", "Berlín"};
    countryData["China"] = {"Mandarín", "Pekín"};
    countryData["España"] = {"Español", "Madrid"};
}

void MainWindow::setupUI()
{
    // Crear widget central y layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    
    // Configurar lista de países
    countryList = new QListWidget(this);
    countryList->setMinimumWidth(200);
    for (const auto& country : countryData) {
        countryList->addItem(country.first);
    }
    
    // Configurar panel de información
    QWidget *infoPanel = new QWidget(this);
    QVBoxLayout *infoPanelLayout = new QVBoxLayout(infoPanel);
    
    QLabel *titleLabel = new QLabel("Información del País", this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    
    languageLabel = new QLabel("Idioma: ", this);
    capitalLabel = new QLabel("Capital: ", this);
    
    languageLabel->setStyleSheet("font-size: 14px; margin: 10px;");
    capitalLabel->setStyleSheet("font-size: 14px; margin: 10px;");
    
    infoPanelLayout->addWidget(titleLabel);
    infoPanelLayout->addWidget(languageLabel);
    infoPanelLayout->addWidget(capitalLabel);
    infoPanelLayout->addStretch();
    
    // Agregar widgets al layout principal
    mainLayout->addWidget(countryList);
    mainLayout->addWidget(infoPanel);
    
    setCentralWidget(centralWidget);
    setWindowTitle("Información de Países");
    resize(600, 400);
}

void MainWindow::onCountrySelected(QListWidgetItem* item)
{
    QString country = item->text();
    if (countryData.find(country) != countryData.end()) {
        languageLabel->setText("Idioma: " + countryData[country].first);
        capitalLabel->setText("Capital: " + countryData[country].second);
    }
}

// main.cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}