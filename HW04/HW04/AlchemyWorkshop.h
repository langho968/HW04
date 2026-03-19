#pragma once

#include <vector>
#include <string>

#include "RecipeManager.h"
#include "StockManager.h"

using namespace std;


class AlchemyWorkshop {
    private:
    vector<PotionRecipe> recipes;
public:
    RecipeManager RecipesManager;
    StockManager StocksManager;
    
    void addRecipe(string& Name, vector<string>& Ingredients);
    void displayAllRecipes() const;
    void FindRecipeByName(string& name) const;
    void FindRecipesByIngredient(string& ingredient) const;
    bool DispensePotion(const string& PotionName);
    void ReturnPotion(const string& PotionName);
};