#pragma once

#include <vector>
#include <string>

using namespace std;

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
public:
    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const string& name, const vector<string>& ingredients);
    
    string GetName() const;
    vector<string> GetIngredients() const;

private:
    string potionName;
    vector<string> ingredients;
};