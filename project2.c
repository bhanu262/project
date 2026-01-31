#include <stdlib.h>

#define SIZE 100000

typedef struct {
    int key;
    int value;
} HashItem;

HashItem hashTable[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    while (hashTable[index].key != 0) {
        index = (index + 1) % SIZE;
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(int key) {
    int index = hash(key);
    while (hashTable[index].key != 0) {
        if (hashTable[index].key == key)
            return hashTable[index].value;
        ind
