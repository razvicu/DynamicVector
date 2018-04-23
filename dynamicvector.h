//
// Created by razvan on 24.03.2018.
//

#ifndef LAB5_6_DYNAMICVECTOR_H
#define LAB5_6_DYNAMICVECTOR_H

template <class TElement>
class DynamicVector {
private:
    int capacity;
    int size;
    TElement *elems;
public:
    // Class constructor, initializing the array with a capacity of 10
    explicit DynamicVector(int capacity = 10);
    // Copy constructor
    DynamicVector(const DynamicVector& dv);
    // Destructor
    ~DynamicVector();
    // Assignment operator
    DynamicVector& operator=(const DynamicVector& dv);
    // Minus operator
    DynamicVector<TElement>& operator-(const TElement& element);
    // Adds an element to the array
    void add(const TElement &element);
    // Removes an element from the array
    void remove(int pos);
    // Inserts an element in the array, at a given position
    void insert(const TElement &element, int pos);
    // Returns the size of the array
    int getSize() const;
    // Returns element from a given position
    TElement getElement(int pos);
    // Returns all array elements
    TElement *getAllElements() const;

protected:
    // Expands array's capacity
    void resize(int scale = 2);
};

template<class TElement>
DynamicVector<TElement>::DynamicVector(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->elems = new TElement[this->capacity];

}

template<class TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector &dv) {
    this->capacity = dv.capacity;
    this->size = dv.size;
    this->elems = new TElement[dv.capacity];
    for ( int i = 0; i < this->size; ++i )
        this->elems[i] = dv.elems[i];
}

template<class TElement>
DynamicVector<TElement>::~DynamicVector() {
    delete[] elems;
}

template<class TElement>
DynamicVector<TElement> &DynamicVector<TElement>::operator=(const DynamicVector &dv) {
    this->capacity = dv.capacity;
    this->size = dv.size;
    if (this != &dv) {
        delete[] this->elems;

        this->elems = new TElement[this->capacity];
        for ( int i = 0; i < this->size; ++i )
            this->elems[i] = dv.elems[i];
    }
    return *this;
}

template<class TElement>
void DynamicVector<TElement>::add(const TElement &element) {
    if (this->capacity == this->size)
        this->resize();
    this->elems[this->size++] = element;
}

template<class TElement>
void DynamicVector<TElement>::remove(int pos) {
    for ( int i = pos; i < this->size - 1; ++i )
        this->elems[i] = this->elems[i+1];

    this->size--;
}

template<class TElement>
int DynamicVector<TElement>::getSize() const {
    return this->size;
}

template<class TElement>
TElement *DynamicVector<TElement>::getAllElements() const {
    return this->elems;
}

template<class TElement>
void DynamicVector<TElement>::resize(int scale) {
    this->capacity *= scale;
    TElement *aux = new TElement[this->capacity];
    for ( int i = 0; i < this->size; ++i )
        aux[i] = this->elems[i];

    delete[] this->elems;
    this->elems = aux;
}

template<class TElement>
void DynamicVector<TElement>::insert(const TElement &element, int pos) {
    this->elems[pos] = element;
}

template<class TElement>
DynamicVector<TElement> &DynamicVector<TElement>::operator-(const TElement &element) {
    for ( int i = 0; i < getSize(); ++i )
        if ( this->elems[i] == element )
            remove(i);
    return *this;
}

template<class TElement>
TElement DynamicVector<TElement>::getElement(int pos) {
    return this->elems[pos];
}


#endif //LAB5_6_DYNAMICVECTOR_H

