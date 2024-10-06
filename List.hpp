#pragma once
#include <iostream>

#include "Node.hpp"

template <typename Data>
class LinkedList{
    public:
        Node<Data>* head;
        Node<Data>* tail;

        LinkedList() : head(nullptr), tail(nullptr) {};
        LinkedList(const LinkedList& other){
            
            Node<Data>* others_node = other.head;
            this->head = new Node<Data>(others_node->data); 
            others_node = others_node->next;
            while(others_node != nullptr) {
                this->push_back(others_node->data);
                others_node = others_node->next;    
            }   
        }
        
        Data& operator[](int index) {
            Node<Data>* current = head;
            int current_index = 0;
            while (current != nullptr && current_index < index) {
                current = current->next;
                current_index++;
            }
            return current->data;
        }
        ~LinkedList() {
            while (this->head != nullptr) {
                Node<Data>* next = this->head->next;
                delete this->head;
                this->head = next;
            }
        }
        int size(){
            Node<Data>* current = head;
            int current_index = 0;
            while (current != nullptr) {
                current_index++;
                current = current->next;
                
            }
            return current_index;          

        }
        void push_back(const Data& value) {
            Node<Data>* newNode = new Node<Data>(value, nullptr);
            if (this->tail != nullptr) {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
            }
        }
        void insert(int index, const Data& value){
            if (index < 0) {
                std::cout << "Invalid index" << std::endl;
                return;
            }

            Node<Data>* new_node = new Node<Data>(value, nullptr);

            if (index == 0) {
                new_node->next = head;
                head = new_node;

                if (tail == nullptr) {
                    tail = new_node;
                }
            } else {
                Node<Data>* current = head;
                int current_index = 0;

                while (current != nullptr && current_index < index - 1) {
                    current = current->next;
                    current_index++;
                }

                if (current == nullptr) {
                    std::cout << "Invalid index" << std::endl;
                    delete new_node;
                    return;
                }

                new_node->next = current->next;
                current->next = new_node;

                if (current == tail) {
                    tail = new_node;
                }
            }
        }
        void pop_head(){
            if (head == nullptr) {
                std::cout << "List is empty" << std::endl;
            }
            else {
                Node<Data>* temp = head;
                head = head->next;
                delete temp;
            }
        }
        void pop_tail(){
            if (head == nullptr) {
                std::cout << "List is empty" << std::endl;
            } if (head == tail) {
                pop_head();
            } else {
                Node<Data>* node = head;
                while (node->next != tail) node = node->next;
                node->next = nullptr;
                delete tail;
                tail = node;
            }
        }
        void pop(int index){
            if (index < 0) {
                std::cout << "Invalid index" << std::endl;
                return;
            }
            Node<Data>* current = head;
            int current_index = 0;
            if (index == 0) {
                pop_head();
                return;
            } else if (current->next == tail) {
                pop_tail();
                return;
            } else {
                while (current != nullptr && current_index < index - 1) {
                    current = current->next;
                    current_index++;
                }
                if (current == nullptr) {
                    std::cout << "Invalid index" << std::endl;
                    return;
                }
                Node<Data>* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
        void pop_value(Data value){
            if (head == nullptr) return;
            if (head->data == value) {
                pop_head();
                return;
            }
            if (tail->data == value) {
                pop_tail();
                return;
            }
            Node<Data>* current = head;
            while (current != nullptr && current->data != value) {
                current = current->next;
            }
            if (current == nullptr) { // Если дошли до конца и не нашли
                std::cout << "Invalid index" << std::endl;
                return;
            }
            Node<Data>* temp = current;
            current = current->next;
            delete temp;
        }
        void search(Data value){
            Node<Data>* curr = head;
            while (curr->data != value && curr->next != nullptr) {
                curr = curr->next;
            }
            if (curr->data == value)
                std::cout << "yes!" << std::endl;
            else std::cout << "No element in list" << std::endl;
        }
        void display(){
            Node<Data>* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};