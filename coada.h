#ifndef COADA_TEMA_POO
#define COADA_TEMA_POO

#include <iostream>
#include <fstream>

namespace queueSpace {

    template<typename T> class node;
    template<typename T> class queue;
    template<typename T> std::istream& operator>> (std::istream&, node<T>&);
    template<typename T> std::ostream& operator<< (std::ostream&, node<T>&);
    template<typename T> std::istream& operator>> (std::istream&, queue<T>&);
    template<typename T> std::ostream& operator<< (std::ostream&, queue<T>&);

    template<typename T>
    class node {
        T content;
        node* nxt;

        friend queue<T>;
        friend std::istream& operator>> <T> (std::istream&, node<T>&);
        friend std::ostream& operator<< <T> (std::ostream&, node<T>&);
        friend std::istream& operator>> <T> (std::istream&, queue<T>&);
        friend std::ostream& operator<< <T> (std::ostream&, queue<T>&);

        public:

        node();
        node(T _content);
    };

    template<typename T>
    class queue {
        node<T>* frontPointer;
        node<T>* backPointer;
        int sz;

        public:

        queue();
        queue(const queue& other);
        queue& operator= (const queue& other);
        T& front() const;
        T& back() const;
        int size() const;
        void push(T newElement);
        void pop();
        queue<T> operator+ (queue<T> B) const;
        queue<T> operator- (queue<T> B) const;
        bool operator< (const queue<T>& B) const;
        bool operator== (const queue<T>& B) const;
        bool operator!= (const queue<T>& B) const;
        ~queue();

        private:
        void free();
    };
}

#include "coada.cpp"

#endif // COADA_TEMA_POO
