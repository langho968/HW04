#include "RecipeManager.h"

PotionRecipe* RecipeManager::AddRecipe(string& Name, vector<string>& Ingredients)
{
    for (auto recipe : recipes)
    {
        if (recipe.GetName() == Name)
        {
            return nullptr;
        }
    }
    
    recipes.push_back(PotionRecipe(Name, Ingredients));
    
    return &recipes.back();
}

const PotionRecipe* RecipeManager::FindRecipeByName(string& Name) const
{
    for (auto& recipe : recipes)
    {
        if (recipe.GetName() == Name)
        {
            return &recipe;
        }
    }
    return nullptr;
}

const vector<PotionRecipe> RecipeManager::FindRecipesByIngredient(string& Ingredient) const
{
    vector<PotionRecipe> results;
    for (auto& recipe : recipes)
    {
        const auto& ingredients = recipe.GetIngredients();
       if (find(ingredients.begin(), ingredients.end(), Ingredient) != ingredients.end())
       {
           results.push_back(recipe);
       }
    }
    return results;
}

const vector<PotionRecipe>& RecipeManager::GetAllRecipes() const
{
    return recipes;
}
