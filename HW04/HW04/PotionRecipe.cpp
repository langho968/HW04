#include <vector>
#include <string>

using namespace std;

#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(const string& name, const vector<string>& ingredients)
    : potionName(name), ingredients(ingredients) {}

string PotionRecipe::GetName() const {return potionName;}

vector<string> PotionRecipe::GetIngredients() const {return ingredients;}

