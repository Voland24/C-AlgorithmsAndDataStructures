#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>

#include <sstream>
#include <memory>
#include <iostream>
#include <stdexcept>

namespace dsa {


    // forward declaration
    template <class T>
    class DoublyLinkedList;

    template <typename T>
    class DoublyLinkedList{

        public:     
            template <typename U>
            // internal Node class for data
            class Node
            {
                private:
                    T data_;
                    Node<T> *prev_, *next_;
                    // for accessing Node internal private fields
                    friend class DoublyLinkedList<T>;
            
                public:
                     Node():prev_(nullptr), next_(nullptr){

                        }

                     Node(const T &data, Node<T> * prev, Node<T> *next): data_(data), prev_(prev), _next_(next){

                     }

                    std::string toString() const {
                    std::stringstream os;
                    os << "Node (" << data_ << ")";
                    return os.str();
                        }

                    friend std::ostream& operator<<(std::ostream &strm, const Node<T> &a){
                    return strm << a.toString();
                }

            };

        private:
        int size_ = 0;
        Node<T> *head_;
        Node<T> *tail_;

        public:

            DoublyLinkedList():size_(0), head_(nullptr), tail_(nullptr){}

            virtual ~DoublyLinkedList(
                clear();
            )

        // we will use the Iterator class to sequentially access the Nodes of the linked list

        class Iterator
        {
            public:
             Iterator() noexcept: currNode_ (head_) {}

             Iterator(const Node<T>* pNode) noexcept : currNode_ (pNode) {}

             Iterator& operator=(Node<T>* pNode)
             {
                this->currNode_ = pNode;
                return *this;
             }

             //Prefix ++ overload
             Iterator& operator++()
             {
                if (currNode_)
                    currNode_ = currNode_->next_;
                return *this;
             }

             //Postfix ++ overload
             Iterator operator++(int)
             {
                Iterator iterator = *this;
                ++*this;
                return iterator;
             }

             bool operator!=(const Iterator& iterator)
             {
                return currNode_ != iterator.currNode_;
             }

             T operator*()
             {
                return currNode_->data_;
             }
         
            private:
                const Node>T>* currNode_;
        };

       
        //empty linked list, O(n) complexity

        void clear()
        {
            Node<T> *trav = head_;
            while (trav != nullptr)
            {
                Node<T> *next = trav->next_;
                delete trav;
                trav = nullptr;
                trav = next;
            }
            head_ = nullptr;
            tail_ = nullptr;
            trav = nullptr;
            size_ = 0;
        }

        //return size of linked list
        int size(){ return size_;}

        bool isEmpty(){ return size() == 0;}

        //add element to tail of linked list, O(1) if we have tail pointer, O(n) if there is only head
        void add(const T &elem){
            addLast(elem);
        }

        //Add node to tail implementation
        void addLast(const T &elem)
        {
            if (isEmpty()) {
                head_ = new Node<T>(elem, nullptr, nullptr);
                tail_ = head_;
            }
            else
            {
                tail_->next_ = new Node<T>(elem, tail_, nullptr);
                tail_ = tail_->next_;
            }
            size_++;
        }

    };


}