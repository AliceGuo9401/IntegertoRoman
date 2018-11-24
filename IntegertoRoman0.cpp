#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string intToRoman(int num) {
    map<int, string> valueSymbol{{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                 {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                 {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
                                 {1000, "M"}};  //map定义在头文件map中，列表初始化
                                
    int temp(0);
    int numTemp(num);
    vector<int> numbers;
    while (numTemp != 0) {
        temp = numTemp % 10;
        numbers.push_back(temp);
        numTemp = numTemp / 10;
    }

    vector<string> roman;
    for (int i = numbers.size() - 1; 0 <= i; --i) {
        int j(i);
        int value = numbers[i];
        int weighted(1);
        while (j != 0) {
            weighted = weighted * 10;
            --j;
        }

        if (weighted == 1000) {
            while (value != 0) {
                roman.push_back(valueSymbol[1000]);
                --value;
            }
        }
        if (weighted == 100 || weighted == 10 || weighted == 1) {
            if (value == 1 || value == 4 ||value == 5 || value == 9)
                roman.push_back(valueSymbol[weighted * value]);
            else if (1 < value && value < 4) {
                while (value != 0) {
                    roman.push_back(valueSymbol[weighted]);
                    --value;
                }
            }else if (5 < value && value < 9) {
                roman.push_back(valueSymbol[weighted * 5]);
                value = value - 5;  /**/
                while (value != 0) {
                    roman.push_back(valueSymbol[weighted]);
                    --value;
                }
            }
        }
    }
    string strRoman = roman[0];
    for (int i = 1; i< roman.size(); ++i){
        strRoman = strRoman + roman[i]; //string对象，s1 + s2返回连接后的结果
    }
    return strRoman;
}
int main() {
    int num(60);
    string roman = intToRoman(num);
    cout << roman;
    return 0;
}
