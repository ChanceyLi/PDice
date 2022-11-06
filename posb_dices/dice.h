#ifndef DICE_H
#define DICE_H
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
struct Dice_Context {
    uint32_t possible;
    uint32_t index;
    uint16_t id;
    std::string name;
    Dice_Context(std::string _name, uint32_t _possible) : name(_name), possible(_possible) {}
};

struct Dice_DicTree {
    Dice_Context* ctx;
    std::unordered_map<char, Dice_DicTree*> childrens;
    Dice_DicTree(Dice_Context* _ctx) : ctx(_ctx) {}
};

class Dice {
private:
    std::unordered_map<std::string, Dice_Context*> dices;
    std::vector<Dice_Context*> id2ctx;
    Dice_DicTree* dic_tree;
    uint32_t current_sum;
    int cnt;
    uint16_t gen_id;
    std::vector<uint16_t> vec;
public:
    Dice() : current_sum(0), gen_id(0), dic_tree(new Dice_DicTree(nullptr)) {}
    Dice_Context* push(std::string name, uint32_t possible);
    std::vector<Dice_Context*> find(std::string name);
    int pop(std::string name);
    void print();
    void print(std::string prefix);
    std::string select();
};
#endif