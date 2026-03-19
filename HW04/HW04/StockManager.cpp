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

bool StockManager::dispensePotion(string& PotionName)
{
    auto it = PotionStock.find(PotionName);
    if ( it != PotionStock.end() )
    {
        if (it->second <= 0)
        {
            cout << "포션의 개수가 0개 입니다." << endl;
            return false;
        }
        else
        {
            --it->second;
            return true;
        }
    }
    else
    {
        return false;
    }
}

void StockManager::ReturnPotion(string& PotionName)
{
    auto it = PotionStock.find(PotionName);
    if ( it != PotionStock.end() )
    {
        ++it->second;
        cout << "포션의 개수가 기존 " << it->second-1 << "개에서 " << it->second << "개로 늘었습니다." << endl;
    }
    else
    {
        cout << "재고에 존재하지 않는 포션을 반환하셨습니다." << endl;
    }
}

int StockManager::GetStock(string& PotionName) const
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
