#pragma once
#include <vector>
#include <string>

using namespace std;

#include "PotionRecipe.h"

class RecipeManager
{
public:
    PotionRecipe* AddRecipe(string& Name, vector<string>& Ingredients);
    const PotionRecipe* FindRecipeByName(string& Name) const;
    const vector<PotionRecipe> FindRecipesByIngredient(string& Ingredient) const;
    const vector<PotionRecipe>& GetAllRecipes() const;

    
private:
    vector<PotionRecipe> recipes;
};
