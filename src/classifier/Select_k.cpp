#include "Select_k.h"
#include "Metric.h"
#include <iostream>

/**
 * 
 * @brief found the key, of the k elemnt, using The median of the medians algorithem.
 * 
 * @param data the elemnts.
 * @param k the number of the elemnt to find.
 * @return double the key of the k elemnt.
 */
template <typename T>
double Select_k<T>::selectK(std::vector<Comparable<T>*>& data, int k){
    //in case the data is to small for selectK
    if (data.size() < 5) {
        return Select_k<T>::selectKOnSmallData(data, k);
    }

    std::vector<Comparable<T>*> middianElements;
    //spliting for group of 5 and getting the middiance
    for (int current5Index = 0; current5Index < data.size() / 5; current5Index++) {
        std::vector<Comparable<T>*> dataOf5Elements;
        Select_k<T>::initialize5Elements(data, dataOf5Elements, current5Index);

        middianElements.push_back(Select_k<T>::findMiddleBetween5(dataOf5Elements));
    }

    //midin of midian
    int middle = middianElements.size() / 2;
    double key = Select_k<T>::selectK(middianElements, middle + 1);

    int midinOfMidianIndex = Select_k<T>::arrangementBy(data, key);
    // (+1) because index start count from 0, and k element from 1;
    if (k == midinOfMidianIndex + 1) {
        return data[midinOfMidianIndex]->getKey();
    }
    else if (k < midinOfMidianIndex + 1) {
        std::vector<Comparable<T>*> newVector;
        Select_k<T>::initializeVector(data, newVector, 0, midinOfMidianIndex - 1);
        return Select_k<T>::selectK(newVector, k);
    }
    else {
        std::vector<Comparable<T>*> newVector;
        Select_k<T>::initializeVector(data, newVector, midinOfMidianIndex + 1, data.size() - 1);
        return Select_k<T>::selectK(newVector, k - midinOfMidianIndex - 1);
    }
}

/**
 * @brief if the data size, less then a 5, it find the k element by iteration.
 * 
 * @param data the data.
 * @param k the sirial number of the elemnt to find. 
 * @return double the key.
 */
template <typename T>
double Select_k<T>::selectKOnSmallData(std::vector<Comparable<T>*>& data, int k) {
    //in case the arrent equals keys, this will find it:
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - 1; j++) {
            if (data[j]->getKey() > data[j + 1]->getKey()) {
                Comparable<T>* temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    //in case of error
    return data[k - 1]->getKey();
}

/**
 * @brief initialize 5 Elements
 * 
 * @param data all the data.
 * @param dataOf5Elements vector to set the element in.
 * @param current5index the start index of the current 5.
 */
template <typename T>
void Select_k<T>::initialize5Elements(std::vector<Comparable<T>*>& data, std::vector<Comparable<T>*>& dataOf5Elements, int current5Index) {
        //save the current 5 in a vector.
        for(int indexIn5 = 0; indexIn5 < 5; indexIn5++) {
            int indexInData = current5Index * 5 + indexIn5;
            dataOf5Elements.push_back(data[indexInData]);
        }
}

/**
 * @brief fond the middians of 5 elements.
 * 
 * @param data the elements.
 * @return T& the middians
 */
template <typename T>
Comparable<T>* Select_k<T>::findMiddleBetween5(std::vector<Comparable<T>*>& data) {
    int less;
    for (Comparable<T>* element : data) {
        less = 0;
        for (Comparable<T>* otherElement : data) {
            if ((*otherElement) < (*element)) {
                less++;
            } 
        }

        //middtern of 5
        if (less == 2) {
            return element;
        }
    }

    return data[0];
}

/**
 * @brief Arranges the vector according to the key
 * 
 * @param data the elements vector.
 * @param key the key to sort by.
 * @return int the index of the element with that key after arrangement.
 */
template <typename T>
int Select_k<T>::arrangementBy(std::vector<Comparable<T>*>& data, double key) {
    //getting the element with this key to the firs index.
    int keyElementIndex = Select_k<T>::find(data, key);
    Comparable<T>* temp = data[keyElementIndex];
    data[keyElementIndex] = data[0];
    data[0] = temp;

    //the index to the element after the key element
    int index = 1;
    int endIndex = data.size() - 1;

    //reordering according to the key
    while (index <= endIndex) {
        if (data[index]->getKey() > key ) {
            temp = data[index];
            data[index] = data[endIndex];
            data[endIndex] = temp;

            endIndex--;
        }
        else {
            temp = data[index];
            data[index] = data[index - 1];
            data[index - 1] = temp;

            index++;
        }
    }

    return (index - 1);
}

/**
 * @brief find the index of the elemnt in the vector with this key.
 * 
 * @param data the vector to search in.
 * @param key the key of the elemnt to find.
 * @return int the index.
 */
template <typename T>
int Select_k<T>::find(std::vector<Comparable<T>*>& data, double key) {
    int index = 0;
    for (Comparable<T>* element : data) {
        if (element->getKey() == key) {
            return index;
        }

        index++;
    }

    //In case of error
    return -1;
}

/**
 * @brief initialize vector from an exsiting vector.
 * 
 * @param data the vector to copy from.
 * @param newVector the vector to copy to.
 * @param startIndex the first index to copy from.
 * @param endIndex the last index to copy. (including)
 */
template <typename T>
void Select_k<T>::initializeVector(std::vector<Comparable<T>*>& data, std::vector<Comparable<T>*>& newVector, int startIndex, int endIndex) {
    for (int index = startIndex; index < endIndex + 1; index++) {
        newVector.push_back(data[index]);
    }
}

template class Select_k<Metric>;