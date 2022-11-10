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

void Dice::print_items_dfs(Dice_DicTree* root) {
    if (!root) return;
    if (root->ctx) {
        std::string& str = root->ctx->name;
        uint32_t& pos = root->ctx->possible;
        std:: cout << "\tItem: " << str << ", \t\tpossibility: " << std::setprecision(5) << (double)pos / this->current_sum << std::endl; 
    }
    for (auto it = root->childrens.begin(); it != root->childrens.end(); ++it) {
        print_items_dfs(it->second);
    }
}

void Dice::pop_item_in_dictree(Dice_DicTree* dic) {
    if (dic->ctx == nullptr) return;
    Dice_Context* ctx = dic->ctx;
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
    delete dic->ctx;
    dic->ctx = nullptr;
}

void Dice::pop_items_backtracking(Dice_DicTree* father, const char& ch) {
    Dice_DicTree* root = father->childrens[ch];
    for (auto it = root->childrens.begin(); it != root->childrens.end(); ++it) {
        // std:: cout<< "key: " << it->first << ", value: " << it->second << std:: endl;
        pop_items_backtracking(root, it->first);
    }
    root->childrens.erase(root->childrens.begin(), root->childrens.end());
    pop_item_in_dictree(root);
    delete father->childrens[ch];
    father->childrens[ch] = nullptr;
}

int Dice:: pop(std::string name) {
    char label = name[(int)name.length()-1];

    if (label != '*') {
        if (this->dices.find(name) == this->dices.end()) {
            std:: cout << "ERROR! THIS TYPE $" << name << " NOT FOUND!" << std:: endl;
            return -1;
        }
        Dice_DicTree* root = this->dic_tree;
        for (int i = 0; i < name.length(); ++i) {
            root = root -> childrens[name[i]];
        }
        pop_item_in_dictree(root);
    } else {
        Dice_DicTree* root = this->dic_tree;
        Dice_DicTree* prev = nullptr;
        char last_char;

        if (name.length() == 1) {
            for (auto it = root->childrens.begin(); it != root->childrens.end(); ++it) {
                pop_items_backtracking(root, it->first);
            }
            root->childrens.erase(root->childrens.begin(), root->childrens.end());
            return 0;
        }

        for (int i = 0; i+1 < name.length(); ++i) {
            if (root -> childrens.find(name[i]) == root -> childrens.end()) {
                std:: cout << "ERROR! THIS PREFIX $" << name << " NOT FOUND!" << std:: endl;
                return -1;
            }
            prev = root;
            root = root -> childrens[name[i]];
            last_char = name[i];
        }

        pop_items_backtracking(prev, last_char);
        prev->childrens.erase(last_char);
    }

    return 0;
}

void Dice:: print() {
    if (this->current_sum == 0) {
        std:: cout << "No items!" << std::endl;
        return;
    }
    std:: cout << "Current possibilities about items:" << std:: endl;
    this->print_items_dfs(this->dic_tree);
}

void Dice:: print(std::string prefix) {
    if (this->current_sum == 0) {
        std:: cout << "No items!" << std::endl;
        return;
    }
    Dice_DicTree* root = this->dic_tree;
    for (int i = 0; i < prefix.length(); ++i) {
        if (prefix[i] == '*' && i+1 < prefix.length()) {
            std::cout << "ERROR! WRONG PREFIX!" << std::endl;
            error_message();
            return;
        }
        if (prefix[i] != '*') {
            if (root->childrens.find(prefix[i]) == root->childrens.end()) {
                std::cout << "ERROR! PREFIX NOT FOUND!" << std::endl;
                error_message();
                return;
            } else {
                root = root->childrens[prefix[i]];
            }
        }
    }
    print_items_dfs(root);
}

std::string Dice:: select() {
    if (this->current_sum == 0) {
        return "ERROR! NO ITEMS!";
    }
    std::srand((int)std::time(0));
    uint32_t get = std:: rand() % this->current_sum;
    return this->id2ctx[this->vec[get]]->name;
}