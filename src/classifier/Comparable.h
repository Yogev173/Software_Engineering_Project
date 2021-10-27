//
// Created by yoavo on 31/07/2021.
//

#ifndef ADVANCED_PROGRAMMINIG_1_COMPARABLE_H
#define ADVANCED_PROGRAMMINIG_1_COMPARABLE_H

/**
 *
 * @tparam T - the class we want to compare.
 */
template<typename T>
class Comparable {
private:
    double m_key;
    T *m_object;
public:
    /**
     *
     * @param key - the number we sort with
     * @param value -the value we sort
     */
    Comparable(double key, T *value);

    /**
     * the operator '<'
     * @param other - the other operator we compare with.
     * @return - true if the other's key is bigger then the current key.
     */
    bool operator<(Comparable<T> const &other) const;

    /**
     *
     * @return the key of the object
     */
    double getKey();

    /**
     *
     * @return - the values of the object.
     */
    T *getObject();
};

#endif //ADVANCED_PROGRAMMINIG_1_COMPARABLE_H