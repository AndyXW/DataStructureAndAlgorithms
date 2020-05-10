#ifndef COMPARE_H
#define COMPARE_H

#include <map>
#include <string>

using namespace std;

map<string, int> master_level = {{"HuangShang", 1}, {"DaMoLaoZu", 1},
                                     {"SaoDiSeng", 1}, {"ZhangSanFeng", 2},
                                     {"DuGuQiuBai", 2}, {"JueYuan", 2},
                                     {"WuYaZi", 3}, {"DuanYu", 4},
                                     {"XuZu", 4}, {"QiaoFeng", 4},
                                     {"WangChongYang", 4}, {"LaoWanTong", 4},
                                     {"HongQiGong", 5}, {"HuangYaoShi", 5},
                                     {"OuYangFeng", 5}, {"DuanHUangYe", 5},
                                     {"GuoJing", 5}, {"YangGuo", 5},
                                     {"XiaoLongNv", 6}, {"ZhangWuJi", 6},
                                     {"JinLunFaWang", 6}, {"FangZhengDaShi", 7},
                                     {"LingHuChong", 7}, {"DongFangBuBai", 7},
                                     {"RenWoXing", 8}, {"XieXun", 9},
                                     {"ZhangCuiShan", 9}, {"ChongXuDaoZhang", 9},
                                     {"ZuoLengChan", 9}, {"TaoGuLiuXian", 10},
                                     {"BuJieHeShang", 10}};

class MasterCompare{
public:
    static bool lt(string x, string y) {
        return (master_level[x] > master_level[y]);
    }
    static bool eq(string x, string y) {
        return (master_level[x] = master_level[y]);
    }
    static bool gt(string x, string y) {
        return (master_level[x] < master_level[y]);
    }
    
};

#endif