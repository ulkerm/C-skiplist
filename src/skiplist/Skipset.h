#pragma once

#include <iostream>
#include <random>
#include <vector>

template<typename T>
struct SkipNode {
    T data;
    std::vector<SkipNode*> next;
    SkipNode(T val, int level) : data(val), next(level, nullptr) {}
};

template<typename T, const int MAX_LEVEL = 32>
class skip_set {
private:
    int count = 0;
    float P = 0.5;
    int level;
    SkipNode<T> *head;

    int randomLevel() {
        int lvl = 1;
        while (((float) rand() / RAND_MAX) < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    skip_set() : level(1) {
        head = new SkipNode<T>(T(), MAX_LEVEL);
    }

    ~skip_set() {
        SkipNode<T> *current = head;
        while (current) {
            SkipNode<T> *temp = current;
            current = current->next[0];
            delete temp;
        }
    }

    int size() const {
        return count;
    }

    bool find(T value) const {
        SkipNode<T>* current = head;
        for (int i = level - 1; i >= 0; i--) {
            while (current->next[i] && current->next[i]->data < value)
                current = current->next[i];
        }
        current = current->next[0];
        return current && current->data == value;
    }

    void insert(T value) {
        std::vector<SkipNode<T>*> update(MAX_LEVEL, nullptr);
        SkipNode<T>* current = head;
        for (int i = level - 1; i >= 0; i--) {
            while (current->next[i] && current->next[i]->data < value)
                current = current->next[i];
            update[i] = current;
        }
        current = current->next[0];

        if (!current || current->data != value) {
            int newLevel = randomLevel();
            if (newLevel > level) {
                for (int i = level; i < newLevel; i++)
                    update[i] = head;
                level = newLevel;
            }
            SkipNode<T>* newNode = new SkipNode<T>(value, newLevel);
            for (int i = 0; i < newLevel; i++) {
                newNode->next[i] = update[i]->next[i];
                update[i]->next[i] = newNode;
            }
            count++;
        }
    }

    void erase(T value) {
        std::vector<SkipNode<T> *> update(MAX_LEVEL, nullptr);
        SkipNode<T> *cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->data < value)
                cur = cur->next[i];
            update[i] = cur;
        }
        cur = cur->next[0];

        if (cur && cur->data == value) {
            for (int i = 0; i < level; i++) {
                if (update[i]->next[i] != cur)
                    break;
                update[i]->next[i] = cur->next[i];
            }
            delete cur;
            while (level > 1 && !head->next[level - 1])
                level--;
            count--;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const skip_set<T, MAX_LEVEL>& s) {
        for (int i = s.level - 1; i >= 0; i--) {
            os << "Level " << i << ": ";
            SkipNode<T>* current = s.head->next[i];
            while (current) {
                os << current->data << " ";
                current = current->next[i];
            }
            os << std::endl;
        }
        return os;
    }

};
