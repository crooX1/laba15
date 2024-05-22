#include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int)), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(
        const int *a, size_t n) {
    unordered_array_set set = unordered_array_set_create(n);
    for (size_t i = 0; i < n; i++)
        unordered_array_set_insert(&set, a[i]);
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isEqual(
        unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    size_t count = 0;
    for (size_t i = 0; i < set2.size; i++) {
        if (unordered_array_set_in(&set1, set2.data[i]))
            count += 1;
    }
    return count == set1.size;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (!linearSearch_(set->data, set->size, value))
        append_(set->data, &set->size, value);
}

void unordered_array_set_deleteElement(
        unordered_array_set *set, int value) {
    size_t position = linearSearch_(set->data, set->size, value);
    if (position >= 0) {
        set->data[position] = set->data[set->size - 1];
        set->size--;
    }
}

unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set setUnion = unordered_array_set_create(set1.size +
                                                              set2.size);
    setUnion.size = set1.size;
    memcpy(setUnion.data, set1.data, set1.size * sizeof(int));
    for (size_t i = 0; i < set2.size; i++) {
        if (!unordered_array_set_in(&set1, set2.data[i]))
            unordered_array_set_insert(&setUnion, set2.data[i]);
    }
    return setUnion;
}

unordered_array_set unordered_array_set_intersection(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set setIntersection =
            unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set2.size; i++) {
        if (unordered_array_set_in(&set1, set2.data[i]))
            unordered_array_set_insert(&setIntersection, set2.data[i]);
    }
    return setIntersection;
}

unordered_array_set unordered_array_set_difference(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set setDifference =
            unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (!unordered_array_set_in(&set2, set1.data[i]))
            unordered_array_set_insert(&setDifference, set1.data[i]);
    }
    return setDifference;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set setSymmetricDifference = unordered_array_set_create(set1.size + set2.size);
    setSymmetricDifference.size = 0;
    unordered_array_set setDifference1 = unordered_array_set_difference(set1,set2);
    unordered_array_set setDifference2 = unordered_array_set_difference(set2,set1);
    unordered_array_set resDifference =unordered_array_set_union(setDifference1, setDifference2);
    unordered_array_set_delete(setDifference1);
    unordered_array_set_delete(setDifference2);

    return resDifference;
}
bool unordered_array_set_isSubset(unordered_array_set subset,unordered_array_set set) {
    return unordered_array_set_isEqual(unordered_array_set_intersection(subset, set),subset);
}
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    assert(unordered_array_set_isSubset(set, universumSet));
    return unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_print(unordered_array_set set) {
    if (set.size == 0)
        printf("{ }");
    else {
        printf("{");
        for (size_t i = 0; i < set.size; i++)
            printf("%d, ", set.data[i]);
        printf("\b\b}\n");
    }
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
    set.size = 0;
    set.capacity = 0;
}