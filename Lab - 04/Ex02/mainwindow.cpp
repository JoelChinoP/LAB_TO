#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Agregar países a la lista
    ui->listWidget->addItem("Peru");
    ui->listWidget->addItem("France");
    ui->listWidget->addItem("Japan");

    // Asignar información de idioma y capital a cada país
    countryInfo["Peru"] = qMakePair(QString("Spanish"), QString("Lima"));
    countryInfo["France"] = qMakePair(QString("French"), QString("Paris"));
    countryInfo["Japan"] = qMakePair(QString("Japanese"), QString("Tokyo"));

    // Conectar la señal de selección de país con el slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onCountrySelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountrySelected(QListWidgetItem *item)
{
    QString country = item->text();
    if (countryInfo.contains(country)) {
        // Mostrar el idioma y la capital correspondiente
        ui->labelLanguage->setText("Language: " + countryInfo[country].first);
        ui->labelCapital->setText("Capital: " + countryInfo[country].second);
    }
}
