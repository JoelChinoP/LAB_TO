#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QMap>

class CountryInfoWidget : public QWidget
{
    Q_OBJECT
public:
    CountryInfoWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        listWidget = new QListWidget(this);
        label = new QLabel(this);
        layout->addWidget(label);
        layout->addWidget(listWidget);


        countryData["Perú"] = qMakePair(QString("Español"), QString("Lima"));
        countryData["Japón"] = qMakePair(QString("Japonés"), QString("Tokio"));
        countryData["Francia"] = qMakePair(QString("Francés"), QString("París"));
        countryData["Alemania"] = qMakePair(QString("Alemán"), QString("Berlín"));
        countryData["Italia"] = qMakePair(QString("Italiano"), QString("Roma"));
        countryData["Brasil"] = qMakePair(QString("Portugués"), QString("Brasilia"));
        countryData["China"] = qMakePair(QString("Chino Mandarín"), QString("Pekín"));
        countryData["Reino Unido"] = qMakePair(QString("Inglés"), QString("Londres"));
        countryData["Rusia"] = qMakePair(QString("Ruso"), QString("Moscú"));

        for (const QString &country : countryData.keys())
        {
            listWidget->addItem(country);
        }
        connect(listWidget, &QListWidget::itemClicked, this, &CountryInfoWidget::onCountrySelected);
    }

private slots:
    void onCountrySelected(QListWidgetItem *item)
    {
        QString country = item->text();
        QString language = countryData[country].first;
        QString capital = countryData[country].second;
        label->setText(QString("Idioma: %1\nCapital: %2").arg(language).arg(capital));
    }

private:
    QListWidget *listWidget;
    QLabel *label;
    QMap<QString, QPair<QString, QString>> countryData;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CountryInfoWidget window;
    window.setWindowTitle("Lista de Países");
    window.resize(400, 300);
    window.show();
    return app.exec();
}

#include "main.moc"
