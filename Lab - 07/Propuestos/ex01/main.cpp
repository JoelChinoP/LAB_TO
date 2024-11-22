#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    virtual string GetName() { return ""; };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Processor : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class IntelI5 : public Processor
{
    string GetName()
    {
        return "Intel i5";
    }
    float GetPrice()
    {
        return 3000.00;
    }
    void GetConfiguration()
    {
        cout << "1.50 Ghz, up to 2.0 Ghz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4 GB - 8 GB" << endl;
    }
};

class IntelI7 : public Processor
{
    string GetName()
    {
        return "Intel i7";
    }
    float GetPrice()
    {
        return 4700.00;
    }
    void GetConfiguration()
    {
        cout << "1.6 Ghz, up to 1.99 Ghz, 9na Gen, 4 cores, 8 threads, 16 MB cache, RAM 16 GB" << endl;
    }
};

class Drive : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class HDD : public Drive
{
    string GetName()
    {
        return "Hard disk drive: ";
    }
    float GetPrice()
    {
        return 150.00;
    }
    void GetConfiguration()
    {
        cout << "Capacity: 1 TB, data transfer 1050 mbits/s" << endl;
    }
};

class SDD : public Drive
{
    string GetName()
    {
        return "Solid state drive: ";
    }
    float GetPrice()
    {
        return 270.00;
    }
    void GetConfiguration()
    {
        cout << "Capacity: 250 GB, data transfer 1800 mbits/s" << endl;
    }
};

class DisplayType : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Normal : public DisplayType
{
    string GetName()
    {
        return "Non-touch screen: ";
    }
    float GetPrice()
    {
        return 195.00;
    }
    void GetConfiguration()
    {
        cout << "15.6 inch FHD(1920 x 1080), plane, ...etc" << endl;
    }
};

class Laptop
{
public:
    void AddParts(Item *item)
    {
        mLaptopParts.push_back(item);
    }

    float GetCost()
    {
        float cost = 0.0;
        for (auto item : mLaptopParts)
        {
            cost += item->GetPrice();
        }
        return cost;
    }

    void GetConfiguration()
    {
        for (auto i = 0; i < mLaptopParts.size(); i++)
        {
            cout << mLaptopParts[i]->GetName() << " ";
            mLaptopParts[i]->GetConfiguration();
        }
    }

private:
    vector<Item *> mLaptopParts;
};

// Modificamos la clase LaptopBuilder
//  Nuevas clases base para las características adicionales
class Brand : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Color : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Monitor : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Printer : public Item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

// Implementaciones concretas de Brand
class Lenovo : public Brand
{
    string GetName() { return "Marca Lenovo: "; }
    float GetPrice() { return 0.0; }
    void GetConfiguration()
    {
        cout << "ThinkPad Series, Business Class" << endl;
    }
};

class Dell : public Brand
{
    string GetName() { return "Marca Dell: "; }
    float GetPrice() { return 0.0; }
    void GetConfiguration()
    {
        cout << "Latitude Series, Professional Grade" << endl;
    }
};

// Implementaciones concretas de Color
class Black : public Color
{
    string GetName() { return "Color Negro: "; }
    float GetPrice() { return 50.00; }
    void GetConfiguration()
    {
        cout << "Acabado mate premium" << endl;
    }
};

class Silver : public Color
{
    string GetName() { return "Color Plateado: "; }
    float GetPrice() { return 75.00; }
    void GetConfiguration()
    {
        cout << "Acabado metalizado premium" << endl;
    }
};

// Implementación de Monitor Plasma
class PlasmaMonitor : public Monitor
{
    string GetName() { return "Monitor Plasma: "; }
    float GetPrice() { return 450.00; }
    void GetConfiguration()
    {
        cout << "42 pulgadas, 4K, HDR, 144Hz" << endl;
    }
};

// Implementaciones de Impresora
class LaserPrinter : public Printer
{
    string GetName() { return "Impresora Láser: "; }
    float GetPrice() { return 299.99; }
    void GetConfiguration()
    {
        cout << "30 ppm, duplex, red, wifi" << endl;
    }
};

class InkjetPrinter : public Printer
{
    string GetName() { return "Impresora Inkjet: "; }
    float GetPrice() { return 199.99; }
    void GetConfiguration()
    {
        cout << "15 ppm, scanner, wifi" << endl;
    }
};

// Modificación de la clase LaptopBuilder para incluir nuevas opciones
class LaptopBuilder
{
public:
    Laptop *opcion1()
    {
        Laptop *lap = new Laptop();
        lap->AddParts(new Lenovo());
        lap->AddParts(new IntelI5());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        lap->AddParts(new Black());
        lap->AddParts(new LaserPrinter());
        return lap;
    }

    Laptop *opcion2()
    {
        Laptop *lap = new Laptop();
        lap->AddParts(new Dell());
        lap->AddParts(new IntelI7());
        lap->AddParts(new Normal());
        lap->AddParts(new SDD());
        lap->AddParts(new Silver());
        lap->AddParts(new PlasmaMonitor());
        lap->AddParts(new InkjetPrinter());
        return lap;
    }

    // Nueva opción premium
    Laptop *opcion3()
    {
        Laptop *lap = new Laptop();
        lap->AddParts(new Dell());
        lap->AddParts(new IntelI7());
        lap->AddParts(new PlasmaMonitor());
        lap->AddParts(new SDD());
        lap->AddParts(new Silver());
        lap->AddParts(new LaserPrinter());
        return lap;
    }
};

// Ejemplo de uso en main()
int main()
{
    LaptopBuilder cotizar;

    cout << "=== Configuración Básica ===" << endl;
    Laptop *config1 = cotizar.opcion1();
    config1->GetConfiguration();
    cout << "Precio total: $" << config1->GetCost() << endl
         << endl;

    cout << "=== Configuración Premium ===" << endl;
    Laptop *config2 = cotizar.opcion2();
    config2->GetConfiguration();
    cout << "Precio total: $" << config2->GetCost() << endl;

    delete config1;
    delete config2;
    return 0;
}