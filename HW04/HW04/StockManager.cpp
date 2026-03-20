#include <iostream>
#include <string>
#include <map>
#include <ostream>

using namespace std;

#include "StockManager.h"

void StockManager::InitaializeStock(string& PotionName)
{
    PotionStock.insert({PotionName, MAX_STOCK});
}

int StockManager::dispensePotion(string& InputString)
{
    // 0 - 포션 개수 부족
    // 1 - 포션 제공
    // 2 - 포션 존재 X
    int status;

        auto it = PotionStock.find(InputString);
        if ( it != PotionStock.end() )
        {
            if (it->second <= 0)
            {
                cout << "포션의 개수가 0개 입니다." << endl;
                return status = 0;
            }
            else
            {
                --it->second;
                return status = 1;
            }
        }
        else
        {
            return status = 2;
        } 
 
}

void StockManager::ReturnPotion(const string& PotionName)
{
    auto it = PotionStock.find(PotionName);
    if ( it != PotionStock.end() )
    {
        if (it->second < 3)
        {
            ++it->second;
            cout << "포션의 개수가 기존 " << it->second-1 << "개에서 " << it->second << "개로 늘었습니다." << endl;
        }
        else
        {
            cout << "이미 최대 3개의 재고를 보유하고 있습니다." << endl;
        }
    }
    else
    {
        cout << "재고에 존재하지 않는 포션을 반환하셨습니다." << endl;
    }
}

int StockManager::GetStock(string PotionName) const
{
    auto it = PotionStock.find(PotionName);
    if ( it != PotionStock.end())
    {
        return it->second;
    }
    else
    {
        return 0;
    }
}
