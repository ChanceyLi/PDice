#ifndef DICE_H
#define DICE_H
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
struct Dice_Context {
    uint32_t possible;
    uint32_t index;
    uint16_t id;
    std::string name;
    Dice_Context(std::string _name, uint32_t _possible) : name(_name), possible(_possible) {}
};

class Dice {
private:
    std::unordered_map<std::string, Dice_Context*> dices;
    uint32_t current_sum;
    uint16_t gen_id;
    std::vector<uint16_t> vec;
public:
    Dice() : current_sum(0), gen_id(0) {}
    Dice_Context* push(std::string name, uint32_t possible);
    Dice_Context* find(std::string name);
    int pop(std::string name);
    void print();
};
#endif