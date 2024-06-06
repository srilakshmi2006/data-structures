#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct HashTable {
    int *table;
    int size;
} HashTable;
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = -1; 
    }
    return hashTable;
}
int hash(int key, int size) {
    return key % size;
}
void insert(HashTable* hashTable, int key) {
    int index = hash(key, hashTable->size);
    while (hashTable->table[index] != -1) {
        index = (index + 1) % hashTable->size;
    }
    hashTable->table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}
int search(HashTable* hashTable, int key) {
    int index = hash(key, hashTable->size);
    int startIndex = index;
    while (hashTable->table[index] != -1) {
        if (hashTable->table[index] == key) {
            return index;
        }
        index = (index + 1) % hashTable->size;
        if (index == startIndex) {
            break; 
        }
    }
    return -1; 
}
void display(HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i] != -1) {
            printf("Index %d: %d\n", i, hashTable->table[i]);
        } else {
            printf("Index %d: \n", i);
        }
    }
}
int main() {
    HashTable* hashTable = createHashTable(TABLE_SIZE);
    insert(hashTable, 23);
    insert(hashTable, 43);
    insert(hashTable, 13);
    insert(hashTable, 27);
    display(hashTable);
    int key = 43;
    int index = search(hashTable, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    key = 50;
    index = search(hashTable, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    free(hashTable->table);
    free(hashTable);
    return 0;
}
