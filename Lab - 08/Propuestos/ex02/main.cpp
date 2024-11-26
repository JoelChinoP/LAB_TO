#include <iostream>
#include <string>
using namespace std;

// Interfaz abstracta para Button
class Button
{
public:
    virtual void Draw() = 0;
};

// Interfaz abstracta para CheckBox
class CheckBox
{
public:
    virtual void Draw() = 0;
};

// Interfaz abstracta para Linux
class LinuxGUIElement
{
public:
    virtual Button *CreateButton() = 0;
    virtual CheckBox *CreateCheckBox() = 0;
};

// Implementación de Button para Windows
class WinButton : public Button
{
public:
    void Draw()
    {
        std::cout << "Drawing Windows Button" << std::endl;
    }
};

// Implementación de CheckBox para Windows
class WinCheckBox : public CheckBox
{
public:
    void Draw()
    {
        std::cout << "Drawing Windows CheckBox" << std::endl;
    }
};

// Implementación de Button para Mac
class MacButton : public Button
{
public:
    void Draw()
    {
        std::cout << "Drawing Mac Button" << std::endl;
    }
};

// Implementación de CheckBox para Mac
class MacCheckBox : public CheckBox
{
public:
    void Draw()
    {
        std::cout << "Drawing Mac CheckBox" << std::endl;
    }
};

// Implementación de Linux GUI Element
class LinuxGUIFactory : public LinuxGUIElement
{
public:
    Button *CreateButton()
    {
        return new LinuxButton();
    }

    CheckBox *CreateCheckBox()
    {
        return new LinuxCheckBox();
    }
};

// Implementación de Button para Linux
class LinuxButton : public Button
{
public:
    void Draw()
    {
        std::cout << "Drawing Linux Button" << std::endl;
    }
};

// Implementación de CheckBox para Linux
class LinuxCheckBox : public CheckBox
{
public:
    void Draw()
    {
        std::cout << "Drawing Linux CheckBox" << std::endl;
    }
};

class GUIFactory
{
public:
    static Button *CreateButton(std::string os)
    {
        if (os == "Windows")
        {
            return new WinButton();
        }
        else if (os == "Mac")
        {
            return new MacButton();
        }
        else if (os == "Linux")
        {
            return new LinuxButton();
        }
        return nullptr;
    }

    static CheckBox *CreateCheckBox(std::string os)
    {
        if (os == "Windows")
        {
            return new WinCheckBox();
        }
        else if (os == "Mac")
        {
            return new MacCheckBox();
        }
        else if (os == "Linux")
        {
            return new LinuxCheckBox();
        }
        return nullptr;
    }
};

int main()
{
    cout << "Cliente: ";
    Button *button = GUIFactory::CreateButton("Windows");
    button->Draw();

    CheckBox *checkBox = GUIFactory::CreateCheckBox("Mac");
    checkBox->Draw();

    cout << endl;

    cout << "Cliente: ";
    Button *linuxButton = GUIFactory::CreateButton("Linux");
    linuxButton->Draw();

    CheckBox *linuxCheckBox = GUIFactory::CreateCheckBox("Linux");
    linuxCheckBox->Draw();

    cout << endl;

    return 0;
}