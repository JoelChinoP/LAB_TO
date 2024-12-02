#include <iostream>

// Interface for Recipe
class Recipe
{
public:
    virtual void prepare() = 0;
    virtual void cook() = 0;
    virtual void serve() = 0;
};

// Concrete Recipe implementations
class BreakfastRecipe : public Recipe
{
public:
    void prepare() override
    {
        std::cout << "Preparando los ingredientes para el desayuno" << std::endl;
    }
    void cook() override
    {
        std::cout << "Cocinando el desayuno" << std::endl;
    }
    void serve() override
    {
        std::cout << "Sirviendo el desayuno" << std::endl;
    }
};

class LunchRecipe : public Recipe
{
public:
    void prepare() override
    {
        std::cout << "Preparando los ingredientes para el almuerzo" << std::endl;
    }
    void cook() override
    {
        std::cout << "Cocinando el almuerzo" << std::endl;
    }
    void serve() override
    {
        std::cout << "Sirviendo el almuerzo" << std::endl;
    }
};

class DinnerRecipe : public Recipe
{
public:
    void prepare() override
    {
        std::cout << "Preparando los ingredientes para la cena" << std::endl;
    }
    void cook() override
    {
        std::cout << "Cocinando la cena" << std::endl;
    }
    void serve() override
    {
        std::cout << "Sirviendo la cena" << std::endl;
    }
};

// Abstract Factory interface
class RecipeFactory
{
public:
    virtual Recipe *createRecipe() = 0;
};

// Concrete Factory implementations
class BreakfastFactory : public RecipeFactory
{
public:
    Recipe *createRecipe() override
    {
        return new BreakfastRecipe();
    }
};

class LunchFactory : public RecipeFactory
{
public:
    Recipe *createRecipe() override
    {
        return new LunchRecipe();
    }
};

class DinnerFactory : public RecipeFactory
{
public:
    Recipe *createRecipe() override
    {
        return new DinnerRecipe();
    }
};

// Client
int main()
{
    // Use the Abstract Factory to create recipes
    RecipeFactory *factory = new BreakfastFactory();
    Recipe *recipe = factory->createRecipe();
    recipe->prepare();
    recipe->cook();
    recipe->serve();
    delete recipe;
    delete factory;

    factory = new LunchFactory();
    recipe = factory->createRecipe();
    recipe->prepare();
    recipe->cook();
    recipe->serve();
    delete recipe;
    delete factory;

    factory = new DinnerFactory();
    recipe = factory->createRecipe();
    recipe->prepare();
    recipe->cook();
    recipe->serve();
    delete recipe;
    delete factory;

    return 0;
}
