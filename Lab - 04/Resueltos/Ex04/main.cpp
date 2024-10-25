#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <QString>

#include "comunicacion.h"

using namespace std;

class adulto : public QObject
{
private:
    QString nombre;
public:
    adulto (QObject *base = 0): QObject(base) {
    }
    void setNombre (const QString &nomb) {
        nombre = nomb;
    }

    QString getNombre() const {
        return nombre;
    }

    ~adulto() {
        qDebug() << "..objeto destruido...";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);





    /*
     *  PARTE A
    int x=47;
    double y=3.2478;
    string t="OK";
    QString qtcadena = QString("%1 %2 %3").arg(QString::fromStdString(t)).arg(y).arg(x);
    string cadena = qtcadena.toStdString(); //convertir dato primitivo string a QString
    qtcadena = "arequipa ciudad blanca 2021";
    qDebug() << qtcadena.contains("ciudad");
    qDebug() << qtcadena.indexOf("2021");
    return a.exec();*/

    /*
     * PARTE B
    adulto *papa = new adulto;
    adulto *hijo1 = new adulto (papa);
    adulto *hijo2 = new adulto (papa);
    hijo1->setNombre ("manuel");
    hijo2->setNombre ("Jose");
    delete papa;
    return a.exec();
    */

    QObject *person = new QObject;
    Comunicacion *pepe = new Comunicacion(person);
    Comunicacion *jose = new Comunicacion(person);

    // Conectar las señales y slots
    QObject::connect(pepe, SIGNAL(enviarmensaje(QString)), jose, SLOT(escuchar(QString)));
    QObject::connect(jose, SIGNAL(enviarmensaje(QString)), pepe, SLOT(escuchar(QString)));

    pepe->conversar("buenos días");
    jose->conversar("como vas?");

    delete person;
}
