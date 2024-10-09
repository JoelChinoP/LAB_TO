#ifndef TIME_H
#define TIME_H

#include <memory>  // Para usar std::unique_ptr

class Time
{
private:
    std::unique_ptr<int> hour;   // Puntero inteligente para la hora
    std::unique_ptr<int> minute; // Puntero inteligente para el minuto
    std::unique_ptr<int> second; // Puntero inteligente para el segundo

public:
    // Constructor con valores por defecto
    Time(const int h = 0, const int m = 0, const int s = 0);

    // Setter
    void setTime(const int h, const int m, const int s);

    // Imprime la descripción del objeto en formato " hh:mm:ss"
    void print() const;

    // Compara 2 objetos Time
    bool equals(const Time&) const;
};

#endif // TIME_H
