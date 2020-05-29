#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class vector
{
private:
  T* a;
  unsigned int size;
  unsigned int capacity;
  T* copy() const;
public:
    vector(unsigned int s =0 ,const T& x =T()); //in pezzi non è presente pezzi()
    vector(const vector& v);
    vector& operator=(const vector& v);
    ~vector();
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    T& operator[](unsigned int i) const;
    void push_back(const T& p);
    //T popBack();
    bool operator==(const vector& r) const;
    vector operator+(const vector& v);
    class iterator{
        private:
            T* ptr;
        public:
            iterator(T* n);
            iterator(const iterator& n);
            iterator& operator=(const iterator& p);
            iterator& operator++();
            iterator operator++(int);
            T& operator*() const;
            T& operator[](iterator i);
            bool operator==(const iterator& x);
            bool operator!=(const iterator& x);
        };
        iterator begin() const;
        iterator end() const;
};

#endif // VECTOR_H
