#include "dice.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Dice_Context* Dice:: push(std::string name, uint32_t possible) {
    if (this->dices.find(name) != this->dices.end()) {
        std::cout << "ERROR! THIS TYPE $" << name << " IS ALREADY EXIST!" << std:: endl;
        return nullptr;
    }
    Dice_Context* dice_context = new Dice_Context(name, possible);
    this->dices[name] = dice_context;
    dice_context->id = gen_id;
    this->id2ctx.push_back(dice_context);
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

    Dice_DicTree* root = this->dic_tree;
    for (int i = 0; i < name.length(); ++i) {
        if (root -> childrens.find(name[i]) == root -> childrens.end()) {
            root -> childrens[name[i]] = new Dice_DicTree(nullptr);
        }
        root = root -> childrens[name[i]];
    }
    root -> ctx = dice_context;

    return dice_context;
}

std::vector<Dice_Context*> Dice:: find(std::string prefix) {
    std:: string name;
    for (int i = 0; i < prefix.length(); ++i) {
        if ( prefix[i] != '*') name.push_back(prefix[i]);
        else {
            if (i + 1 == prefix.length()) break;
            else {
                std:: cout << "ERROR! WRONG PREFIX! please use `help` for more information." << std:: endl;
                return {};
            }
        }
    }

    Dice_DicTree* root = this -> dic_tree;
    for (int i = 0; i < name.length(); ++i) {
        if (root->childrens.find(name[i]) == root->childrens.end()) {
            return {};
        }
        root = root -> childrens[name[i]];
    }
    std::vector<Dice_Context*> res;
    std::stack<Dice_DicTree*> stk;
    stk.push(root);
    while (!stk.empty()) {
        Dice_DicTree* t = stk.top();
        stk.pop();
        if (t->ctx) res.push_back(t->ctx);
        for (auto it = t->childrens.begin(); it != t->childrens.end(); ++it) {
            stk.push(it->second);
        }
    }
    return res;

}

int Dice:: pop(std::string name) {
    char label = name[(int)name.length()-1];
    std::vector<Dice_DicTree*> name_find;

    if (label != '*') {
        if (this->dices.find(name) == this->dices.end()) {
            std:: cout << "ERROR! THIS TYPE $" << name << " NOT FOUND!" << std:: endl;
            return -1;
        }
        Dice_DicTree* root = this->dic_tree;
        for (int i = 0; i < name.length(); ++i) {
            root = root -> childrens[name[i]];
        }
        name_find.push_back(root);
    } else {
        Dice_DicTree* root = this->dic_tree;

        for (int i = 0; i+1 < name.length(); ++i) {
            if (root -> childrens.find(name[i]) == root -> childrens.end()) {
                std:: cout << "ERROR! THIS PREFIX $" << name << " NOT FOUND!" << std:: endl;
                return -1;
            }
            root = root -> childrens[name[i]];
        }
        std::stack<Dice_DicTree*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Dice_DicTree* t = stk.top();
            if (t->ctx) name_find.push_back(t);
            stk.pop();
            for (auto it = t->childrens.begin(); it != t->childrens.end(); ++it) {
                stk.push(it->second);
            }
        }
    }
    if (name_find.size() == 0) {
        std:: cout << "ERROR! THIS PREFIX $" << name << " NOT FOUND!" << std:: endl;
        return -1;
    }
    for (auto& nm : name_find) {
        Dice_Context* ctx = nm->ctx;
        uint32_t& poss = ctx->possible;
        uint32_t& index = ctx->index;
        int curr_index = -1;
        for (int i = index; i + poss < this->current_sum; ++i) {
            this->vec[i] = this->vec[i+poss];
            if (curr_index != this->vec[i]) {
                curr_index = this->vec[i];
                Dice_Context* tmp = this->id2ctx[curr_index];
                tmp->index -= poss;
            }
        }
        this->current_sum -= poss;
        this->dices.erase(ctx->name);
        nm->ctx = nullptr;
    }
    return 0;
}

void Dice:: print() {
    if (this->current_sum == 0) {
        std:: cout << "No items!" << std::endl;
        return;
    }
    std:: cout << "Current possibilities about items:" << std:: endl;
    for (auto it = this->dices.begin(); it != this->dices.end(); ++it) {
        std::string str = it -> first;
        uint32_t& pos = it -> second -> possible;
        std:: cout << "\tItem: " << str << ", \t\tpossibility: " << std::setprecision(5) << (double)pos / this->current_sum << std::endl; 
    }
}

void Dice:: print(std::string prefix) {
    if (this->current_sum == 0) {
        std:: cout << "No items!" << std::endl;
        return;
    }
    std:: vector<Dice_Context*> res = this->find(prefix);
    if (res.size() == 0) {
        std:: cout << "ERROR! THIS PREFIX $" << prefix << " NOT FOUND!" << std:: endl;
    } else {
        std:: cout << "Current possibilities about items with prefix: " << prefix << std:: endl;
        for (auto& it : res) {
            std:: cout << "\tItem: " << it->name << ", \t\tpossibility: " << std::setprecision(5) << (double)(it->possible) / this-> current_sum << std::endl;
        }
    }
}

std::string Dice:: select() {
    if (this->current_sum == 0) {
        return "ERROR! NO ITEMS!";
    }
    std::srand((int)std::time(0));
    uint32_t get = std:: rand() % this->current_sum;
    return this->id2ctx[this->vec[get]]->name;
}