//
// Created by yoavo on 31/07/2021.
//

#ifndef ADVANCED_PROGRAMMINIG_1_SELECT_H
#define ADVANCED_PROGRAMMINIG_1_SELECT_H

#include "Comparable.h"
#include <vector>

/**
 * @brief found the key, of the k elemnt.
 * 
 * @tparam T inheritens from Comparabale.
 */
template <typename T>
class Select_k {
public:
    /**
     * @brief found the key, of the k elemnt, using The median of the medians algorithem.
     * 
     * @param data the elemnts.
     * @param k the sirial number of the elemnt to find. (start count from 1).
     * @return double the key of the k elemnt.
     */
    static double selectK(std::vector<Comparable<T>*>& data, int k);

private:
    /**
     * @brief if the data size, less then a 5, it find the k element by iteration.
     * 
     * @param data the data.
     * @param k the sirial number of the elemnt to find (start from 1). 
     * @return double the key.
     */
    static double selectKOnSmallData(std::vector<Comparable<T>*>& data, int k);
    /**
     * @brief initialize 5 Elements
     * 
     * @param data all the data.
     * @param dataOf5Elements vector to set the element in.
     * @param current5index the start index of the current 5.
     */
    static void initialize5Elements(std::vector<Comparable<T>*>& data, std::vector<Comparable<T>*>& dataOf5Elements, int current5Index);
    /**
     * @brief fond the middians of 5 elements.
     * 
     * @param data the elements vector.
     * @return T& the middians
     */
    static Comparable<T>* findMiddleBetween5(std::vector<Comparable<T>*>& data);

    /**
     * @brief Arranges the vector according to the key
     * 
     * @param data the elements vector.
     * @param key the key to sort by.
     * @return int the index of the element with that key after arrangement.
     */
    static int arrangementBy(std::vector<Comparable<T>*>& data, double key);

    /**
     * @brief initialize vector from an exsiting vector.
     * 
     * @param data the vector to copy from.
     * @param newVector the vector to copy to.
     * @param startIndex the first index to copy from. (index count from 0).
     * @param endIndex the end inde to copy. (index count from 0).
     */
    static void initializeVector(std::vector<Comparable<T>*>& data, std::vector<Comparable<T>*>& newVector, int startIndex, int endIndex);

    /**
     * @brief find the index of the elemnt in the vector with this key.
     * 
     * @param data the vector to search in.
     * @param key the key of the elemnt to find.
     * @return int the index (start count from 0).
     */
    static int find(std::vector<Comparable<T>*>& data, double key);
};

#endif //ADVANCED_PROGRAMMINIG_1_SELECT_H