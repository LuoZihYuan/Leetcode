#include <iostream>
using namespace std;

struct MyListNode {
    int val;
    MyListNode *prev;
    MyListNode *next;
    MyListNode() : val(0), prev(nullptr), next(nullptr) {}
    MyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    MyListNode(int x, MyListNode *prev, MyListNode *next) : val(x), prev(prev), next(next) {}
};

/* Your implementation of `Solution` goes here. */
class MyLinkedList {
private:
    int _size;
    MyListNode *head;
    MyListNode *tail;
public:

    MyLinkedList() : _size(0), head(nullptr), tail(nullptr) {}
    
    int get(int index) {
        if(index >= _size) return -1;
        MyListNode *curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        MyListNode *newNode = new MyListNode(val, nullptr, head);
        if(head != nullptr) head->prev = newNode;
        head = newNode;
        _size++;
        if(tail == nullptr) tail = head;
    }

    void deleteAtHead() {
        if(_size == 0) return;
        MyListNode *delNode = head;
        head = head->next;
        delete delNode;
        if(head != nullptr) head->prev = nullptr;
        else tail = nullptr;
        _size--;
    }
    
    void addAtTail(int val) {
        MyListNode *newNode = new MyListNode(val, tail, nullptr);
        if(tail != nullptr) tail->next = newNode;
        tail = newNode;
        _size++;
        if(head == nullptr) head = tail;
    }

    void deleteAtTail() {
        if(_size == 0) return;
        MyListNode *delNode = tail;
        tail = tail->prev;
        delete delNode;
        if(tail != nullptr) tail->next = nullptr;
        else head = nullptr;
        _size--;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if (index == _size) {
            addAtTail(val);
            return;
        }
        MyListNode *curr = head;
        for(int i = 1; i < index; i++)
            curr = curr->next;
        MyListNode *newnode = new MyListNode(val, curr, curr->next);
        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(_size == 0 || index >= _size) return;
        if(index == 0){
            deleteAtHead();
            return;
        }
        if(index == _size-1) {
            deleteAtTail();
            return;
        }
        MyListNode *curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        _size--;
    }

    int size() {
        return _size;
    }
};
/* Uncomment the following code snippet on Leetcode for performance optimization. */
// int init = [] {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     ofstream out("user.out");
//     cout.rdbuf(out.rdbuf());
// 
//     for (string s; getline(cin, s); cout << '\n') {
//         string t;
//         getline(cin, t);
//         int tar = stoi(t);
// 
//         for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
//             bool _neg = 0;
//             if (s[_i] == '-')
//                 ++_i, _neg = 1;
//             int v = s[_i++] & 15;
//             while ((s[_i] & 15) < 10)
//                 v = v * 10 + (s[_i++] & 15);
//             if (_neg)
//                 v = -v;
//             if (v == tar) {
//                 cout << i;
//                 goto next;
//             }
//             if (v > tar)
//                 break;
//         }
//         cout << -1;
//     next:;
//     }
//     exit(0);
//     return 0;
// }();

int main() {
    
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(0);
    myLinkedList.addAtIndex(1,4);
    myLinkedList.addAtTail(8);
    myLinkedList.addAtHead(5);
    myLinkedList.addAtIndex(4,3);
    myLinkedList.addAtTail(0);
    myLinkedList.addAtTail(5);
    myLinkedList.addAtIndex(6,3);
    myLinkedList.deleteAtIndex(7);
    myLinkedList.deleteAtIndex(5);
    myLinkedList.addAtTail(4);
    
    return 0;

}