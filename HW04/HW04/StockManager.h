#pragma once
#include <string>
#include <map>

using namespace std;

class StockManager
{
public:
    
    
    void InitaializeStock(string& PotionName);
    bool dispensePotion(string& PotionName);
    void ReturnPotion(string& PotionName);
    int GetStock(string& PotionName) const;
    
private:
    map<string, int> PotionStock;
    const int MAX_STOCK = 3; 
};
