
namespace queueSpace {

    template <typename T>
    node<T>::node () {
        nxt = nullptr;
    }

    template <typename T>
    node<T>::node (T _content) {
        content = _content;
        nxt = nullptr;
    }

    template<typename T>
    std::istream& operator>> (std::istream& in, node<T>& nd) {
        in >> nd.content;
        return in;
    }

    template<typename T>
    std::ostream& operator<< (std::ostream& out, node<T>& nd) {
        out << nd.content;
        return out;
    }

    template<typename T>
    queue<T>::queue() {
        frontPointer = backPointer = nullptr;
        sz = 0;
    }

    template<typename T>
    queue<T>::queue(const queue& other) {
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

    template<typename T>
    queue<T>& queue<T>::operator= (const queue<T>& other) {
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

    template<typename T>
    T& queue<T>::front() const {
        if (!sz) {
            // ?
        }

        return frontPointer -> content;
    }

    template<typename T>
    T& queue<T>::back() const {
        if (!sz) {
            // ?
        }

        return backPointer -> content;
    }

    template<typename T>
    int queue<T>::size() const {
        return sz;
    }

    template<typename T>
    void queue<T>::push(T newElement) {
        if (!sz) {
            frontPointer = backPointer = new node<T>(newElement);
        }
        else {
            backPointer = backPointer -> nxt = new node<T>(newElement);
        }

        ++sz;
    }

    template<typename T>
    void queue<T>::pop() {
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

    template<typename T>
    queue<T> queue<T>::operator+ (queue<T> B) const {
        queue<T> ret = *this;

        while (B.size()) {
            ret.push( B.front() );
            B.pop();
        }

        return ret;
    }

    template<typename T>
    queue<T> queue<T>::operator- (queue<T> B) const {
        queue<T> cpy = *this;

        while (cpy.size() && B.size() && cpy.front() == B.front()) {
            cpy.pop();
            B.pop();
        }

        return cpy;
    }

    template<typename T>
    bool queue<T>::operator< (const queue<T>& B) const {

        node<T>* ptr1 = this->frontPointer, *ptr2 = B.frontPointer;
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
    bool queue<T>::operator== (const queue<T>& B) const {
        return !(*this < B) && !(B < *this);
    }

    template<typename T>
    bool queue<T>::operator!= (const queue<T>& B) const {
        return !(*this == B);
    }

    template<typename T>
    queue<T>::~queue() {
        free();
    }

    template<typename T>
    void queue<T>::free() {
        while (sz) {
            pop();
        }

        frontPointer = backPointer = nullptr;
    }

    template<typename T>
    std::istream& operator>> (std::istream& in, queue<T>& q) {
        int N;
        in >> N;
        while (N--) {
            node<T> aux;
            in >> aux;
            q.push(aux.content);
        }

        return in;
    }

    template<typename T>
    std::ostream& operator<< (std::ostream& out, queue<T>& q) {

        while (q.size()) {
            node<T> aux(q.front());
            out << aux << ' ';
            q.pop();
        }
        out << '\n';

        return out;
    }

}
