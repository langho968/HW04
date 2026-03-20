#pragma once
#include <string>
#include <map>



using namespace std;

class StockManager
{
public:
    
    
    void InitaializeStock(string& PotionName);
    int dispensePotion(string& PotionName);
    void ReturnPotion(const string& PotionName);
    int GetStock(string PotionName) const;
    
private:
    map<string, int> PotionStock;
    const int MAX_STOCK = 3; 

};
