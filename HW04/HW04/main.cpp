#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"

int main()
{
    AlchemyWorkshop myWorkshop;

    while (true) {
        cout << "⚗️ 연금술 공방 관리 시스템" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 모든 레시피 출력" << endl;
        cout << "3. 포션 이름으로 검색" << endl;
        cout << "4. 포션 재료로 검색" << endl;
        cout << "5. 포션 지급" << endl;
        cout << "6. 포션 반납" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // 여러 재료를 입력받기 위한 로직
            vector<string> ingredients_input;
            string ingredient;
            cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;
            
            while (true) {
                cout << "재료 입력: ";
                getline(cin, ingredient);
                
                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            } else {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
            }

        } else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        } else if (choice == 3) {
            string PotionName;
            cout << "찾는 물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, PotionName);
            
            myWorkshop.FindRecipeByName(PotionName);
            
        } else if (choice == 4) {
            string ingredient;
            cout << "찾는 물약의 재료: ";
            cin.ignore(10000, '\n');
            getline(cin, ingredient);
            
            myWorkshop.FindRecipesByIngredient(ingredient);
                
        } else if (choice == 0)
        {
            cout << "공방 문을 닫습니다..." << endl;
            break;
            
        } else if (choice == 5)
        {
            string PotionName;
            cout << "원하는 물약의 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, PotionName);
            
            myWorkshop.DispensePotion(PotionName);
     
            
        
        } else if (choice == 6)
        {
            string PotionName;
            cout << "반납하는 물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, PotionName);
            
            myWorkshop.ReturnPotion(PotionName);
        } else {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}