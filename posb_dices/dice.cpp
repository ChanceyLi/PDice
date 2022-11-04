#include "dice.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Dice_Context* Dice:: push(std::string name, uint32_t possible) {
    if (this->find(name)) {
        std::cout << "ERROR! THIS TYPE $" << name << " IS ALREADY EXIST!" << std:: endl;
        return nullptr;
    }
    Dice_Context* dice_context = new Dice_Context(name, possible);
    this->dices[name] = dice_context;
    dice_context->id = gen_id;
    id2name.push_back(name);
    dice_context->index = current_sum;
    uint32_t size = this->vec.size();
    if (current_sum + possible < size) {
        for (int i = current_sum; i < current_sum + possible; ++i) {
            this->vec[i] = gen_id;
        }
    } else {
        for (int i = current_sum; i < size; ++i) {
            this->vec[i] = gen_id;
        }
        for (int i = size; i < current_sum + possible; ++i) {
            this->vec.push_back(gen_id);
        }
    }
    this->current_sum += possible;
    this->gen_id++;
    return dice_context;
}

Dice_Context* Dice:: find(std::string name) {
    if (this->dices.find(name) != this->dices.end()) {
        return this->dices[name];
    }
    return nullptr;
}

int Dice:: pop(std::string name) {
    if (this->find(name) == nullptr) {
        std:: cout << "ERROR! THIS TYPE $" << name << "NOT FOUND!" << std:: endl;
        return -1;
    }
    Dice_Context* dice = this->dices[name];
    uint32_t& poss = dice->possible;
    uint32_t& index = dice->index;

    for (int i = index; i + poss < this->vec.size(); ++i) {
        this->vec[i] = this->vec[i+poss];
    }
    this->current_sum -= poss;
    this->dices.erase(name);
    return 0;
}

void Dice:: print() {
    std:: cout << "Current possibilities about items:" << std:: endl;
    for (auto it = this->dices.begin(); it != this->dices.end(); ++it) {
        std::string str = it -> first;
        uint32_t& pos = it -> second -> possible;
        std:: cout << "\tItem: " << str << ", possibility: " << std::setprecision(5) << (double)pos / this->current_sum << std::endl; 
    }
}

std::string Dice:: select() {
    std::srand((int)std::time(0));
    uint32_t get = std:: rand() % this->current_sum;
    return this->id2name[vec[get]];
}