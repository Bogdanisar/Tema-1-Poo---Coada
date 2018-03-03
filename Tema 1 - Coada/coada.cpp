#include <iostream>
#include <fstream>

namespace queueSpace {

    template<typename T> class node;
    template<typename T> class queue;
    template<typename T> std::ifstream& operator>> (std::ifstream&, node<T>&);
    template<typename T> std::ofstream& operator<< (std::ofstream&, node<T>&);
    template<typename T> std::ifstream& operator>> (std::ifstream&, queue<T>&);
    template<typename T> std::ofstream& operator<< (std::ofstream&, queue<T>&);
    template<typename T> queue<T> operator+ (queue<T>, queue<T>);
    template<typename T> queue<T> operator- (queue<T>, queue<T>);
    template<typename T> bool operator< (const queue<T>&, const queue<T>&);
    template<typename T> bool operator== (const queue<T>&, const queue<T>&);
    template<typename T> bool operator!= (const queue<T>&, const queue<T>&);

    template<typename T>
    class node {
        T content;
        node* nxt;

        friend queue<T>;
        friend std::ifstream& operator>> <T> (std::ifstream&, node<T>&);
        friend std::ofstream& operator<< <T> (std::ofstream&, node<T>&);
        friend std::ifstream& operator>> <T> (std::ifstream&, queue<T>&);
        friend std::ofstream& operator<< <T> (std::ofstream&, queue<T>&);
        friend bool operator< <T> (const queue<T>&, const queue<T>&);
        friend bool operator== <T> (const queue<T>&, const queue<T>&);
        friend bool operator!= <T> (const queue<T>&, const queue<T>&);

        public:

        node() {}

        node(T _content) {
            content = _content;
            nxt = nullptr;
        }

        void print() {
            std::cout << content << '\n';
        }
    };

    template<typename T>
    std::ifstream& operator>> (std::ifstream& in, node<T>& nd) {
        in >> nd.content;
        return in;
    }

    template<typename T>
    std::ofstream& operator<< (std::ofstream& out, node<T>& nd) {
        out << nd.content;
        return out;
    }

    template<typename T>
    class queue {
        node<T>* frontPointer;
        node<T>* backPointer;
        int sz;

        friend queue<T> operator+ <T> (queue<T>,queue<T>);
        friend queue<T> operator- <T> (queue<T>,queue<T>);
        friend bool operator< <T> (const queue<T>&, const queue<T>&);
        friend bool operator== <T> (const queue<T>&, const queue<T>&);
        friend bool operator!= <T> (const queue<T>&, const queue<T>&);

        public:

        queue() {
            frontPointer = backPointer = nullptr;
            sz = 0;
        }

        queue(const queue& other) {
            frontPointer = backPointer = nullptr;
            sz = 0;

            if (other.size() == 0) {
                return;
            }

            node<T>* ptr = other.frontPointer;

            while (ptr != nullptr) {
                push(ptr -> content);
                ptr = ptr -> nxt;
            }
        }

        queue& operator= (const queue& other) {
            free();

            frontPointer = backPointer = nullptr;
            sz = 0;

            if (other.size() == 0) {
                return *this;
            }

            node<T>* ptr = other.frontPointer;

            while (ptr != nullptr) {
                push(ptr -> content);
                ptr = ptr -> nxt;
            }

            return *this;
        }

        T& front() const {
            if (!sz) {
                // ?
            }

            return frontPointer -> content;
        }

        T& back() const {
            if (!sz) {
                // ?
            }

            return backPointer -> content;
        }

        int size() const {
            return sz;
        }

        void push(T newElement) {
            if (!sz) {
                frontPointer = backPointer = new node<T>(newElement);
            }
            else {
                backPointer = backPointer -> nxt = new node<T>(newElement);
            }

            ++sz;
        }

        void pop() {
            if (!sz) {
                return;
            }

            auto aux = frontPointer;
            frontPointer = frontPointer -> nxt;
            delete aux;
            --sz;

            if (!sz) {
                frontPointer = backPointer = nullptr;
            }
        }

        ~queue() {
            free();
        }

        private:
        void free() {
            while (sz) {
                pop();
            }

            frontPointer = backPointer = nullptr;
        }

    };

    template<typename T>
    queue<T> operator+ (queue<T> A,queue<T> B) {
        queue<T> ret;

        while (A.size()) {
            ret.push( A.front() );
            A.pop();
        }

        while (B.size()) {
            ret.push( B.front() );
            B.pop();
        }

        return ret;
    }

    template<typename T>
    queue<T> operator- (queue<T> A,queue<T> B) {

        while (A.size() && B.size() && A.front() == B.front()) {
            A.pop();
            B.pop();
        }

        return A;
    }

    template<typename T>
    bool operator< (const queue<T>& A, const queue<T>& B) {

        node<T>* ptr1 = A.frontPointer, *ptr2 = B.frontPointer;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1 -> content < ptr2 -> content) {
                return true;
            }
            if (ptr1 -> content > ptr2 -> content) {
                return false;
            }

            ptr1 = ptr1 -> nxt;
            ptr2 = ptr2 -> nxt;
        }

        if (ptr1 == nullptr && ptr2 != nullptr) {
            return true;
        }

        return false;
    }


    template<typename T>
    bool operator== (const queue<T>& A, const queue<T>& B) {
        return !(A < B) && !(B < A);
    }


    template<typename T>
    bool operator!= (const queue<T>& A, const queue<T>& B) {
        return !(A == B);
    }


    template<typename T>
    std::ifstream& operator>> (std::ifstream& in, queue<T>& q) {
        node<T> aux;
        in >> aux;
        q.push(aux.content);

        return in;
    }

    template<typename T>
    std::ofstream& operator<< (std::ofstream& out, queue<T>& q) {

        while (q.size()) {
            node<T> aux( q.front() );
            out << aux << ' ';
            q.pop();
        }
        out << '\n';

        return out;
    }
}

