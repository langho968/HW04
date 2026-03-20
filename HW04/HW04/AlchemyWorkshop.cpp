#include <vector>
#include <string>
#include <iostream>

#include "AlchemyWorkshop.h"

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
void AlchemyWorkshop::addRecipe(string& Name, vector<string>& Ingredients) 
{
    auto NewRecipeIndex = RecipesManager.AddRecipe(Name, Ingredients);
    if (NewRecipeIndex != -1)
    {
        cout << ">> 새로운 레시피 '" << Name << "'이(가) 추가되었습니다." << endl;
        StocksManager.InitaializeStock(Name);
    }
    else
    {
        cout << Name << "는 이미 존재하는 레시피 입니다." << endl;
    }
    
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const 
{
    const auto& AllRecipes = RecipesManager.GetAllRecipes();
    if (AllRecipes.empty()) {
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
    for (size_t i = 0; i < AllRecipes.size(); ++i) {
        auto& Potion = AllRecipes[i]; 
        cout << "- 물약 이름: " << Potion.GetName() << endl;
        cout << "  > 필요 재료: ";
            
        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < Potion.GetIngredients().size(); ++j) {
            cout << Potion.GetIngredients()[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < Potion.GetIngredients().size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "  > 물약 재고: " << StocksManager.GetStock(Potion.GetName()) << endl;
    }
    cout << "---------------------------\n";
}

// 물약 이름으로 물약 검색 메서드
void AlchemyWorkshop::FindRecipeByName(string& Name) const
{
    const auto& Recipe = RecipesManager.FindRecipeByName(Name);
    if (Recipe != nullptr)
    {
        cout << "- 물약 이름: " << Recipe->GetName() << endl;
        cout << "  > 필요 재료: ";
        for (int i = 0; i < Recipe->GetIngredients().size(); ++i)
        {
            cout << Recipe->GetIngredients()[i];
            if (i < Recipe->GetIngredients().size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "찾고 있는 포션은 존재하지 않습니다." << endl;
    }
}

// 물약 재료로 물약 검색 메서드
void AlchemyWorkshop::FindRecipesByIngredient(string& ingredient) const
{
    const auto& Recipes = RecipesManager.FindRecipesByIngredient(ingredient);
    for (int i = 0; i < Recipes.size(); ++i)
    {
        cout << "- 물약 이름: " << Recipes[i].GetName() << endl;
        cout << "  > 필요 재료: ";
        for (int j = 0; j < Recipes[i].GetIngredients().size(); ++j)
        {
            cout << Recipes[i].GetIngredients()[j];
            if (j < Recipes[i].GetIngredients().size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void AlchemyWorkshop::DispensePotion(string& InputString)
{
    int PotionStatus = StocksManager.dispensePotion(InputString);

        if (PotionStatus == 0)
        {
            cout << InputString << "의 재고가 0개 입니다." << endl;
        }
        else if (PotionStatus == 1)
        {
            cout << InputString << " 한 개 제공합니다." << endl;
        }
        else if (PotionStatus == 2)
        {
            cout << InputString << "이 존재하지 않습니다." << endl;
        }
 
}

void AlchemyWorkshop::ReturnPotion(const string& PotionName)
{
    StocksManager.ReturnPotion(PotionName);
}
