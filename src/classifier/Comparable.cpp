
//
// Created by yoavo on 03/08/2021.
//
#include "Comparable.h"
#include "Metric.h"

/**
 * @tparam T - the class we sort/compare
 * @param other - the other object we compare
 * @return - true if the other object is "bigger" then the current object.
 */
template<typename T>
Comparable<T>::Comparable(double key, T *value) {
    m_key = key;
    m_object = value;
}

template<typename T>
bool Comparable<T>::operator<(Comparable<T> const &other) const {
    return m_key < other.m_key;
}

/**
 * @tparam T - the class we sort/compare
 * @return - the key.
 */
template<typename T>
double Comparable<T>::getKey() {
    return this->m_key;
}

template<typename T>
T *Comparable<T>::getObject() {
    return m_object;
}

template class Comparable<Metric>;