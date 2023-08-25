// 划分链表
// 给定一个单向链表的头节点head, 节点的值类型是整型,再给定一个整数pivot。实现一个调整链表的函数,将链表调整为左部分
// 都是值小于pivot的节点,中间部分都是值等于pivot的节点,右部分都是值大于pivot的节点。
// 要求:
// 1、在左、中、右三个部分的内部也做顺序要求,要求每部分里的节点从左到右的顺序与原链表中节点的先后次序一致
// 2、如果链表长度为N,要求时间复杂度O(N),空间复杂度O(1)。
// 输入描述
// 9->0->4->5->1, 3
// 输出描述
// 调整后是0->1->9->4->5

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void adjustLinkedList(ListNode *&head, int pivot) {
    ListNode *lessHead = nullptr, *lessTail = nullptr;
    ListNode *equalHead = nullptr, *equalTail = nullptr;
    ListNode *greaterHead = nullptr, *greaterTail = nullptr;

    ListNode *current = head;

    while (current) {
        ListNode *nextNode = current->next;
        current->next = nullptr;

        if (current->val < pivot) {
            if (!lessHead) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else if (current->val == pivot) {
            if (!equalHead) {
                equalHead = equalTail = current;
            } else {
                equalTail->next = current;
                equalTail = current;
            }
        } else {
            if (!greaterHead) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }

        current = nextNode;
    }

    if (lessHead) {
        if (equalHead) {
            lessTail->next = equalHead;
            equalTail->next = greaterHead;
        } else {
            lessTail->next = greaterHead;
        }
        head = lessHead;
    } else if (equalHead) {
        equalTail->next = greaterHead;
        head = equalHead;
    } else {
        head = greaterHead;
    }
}

ListNode *createLinkedList(const vector<int> &values) {
    ListNode *head = nullptr, *current = nullptr;
    for (int val: values) {
        ListNode *node = new ListNode(val);
        if (!head) {
            head = current = node;
        } else {
            current->next = node;
            current = current->next;
        }
    }
    return head;
}

void printLinkedList(ListNode *head) {
    ListNode *current = head;
    while (current->next) {
        cout << current->val << "->";
        current = current->next;
    }
    cout << current->val << endl;
}

int main() {
    vector<int> values = {9, 0, 4, 5, 1};
    int pivot = 3;

    ListNode *head = createLinkedList(values);
    adjustLinkedList(head, pivot);
    printLinkedList(head);

    return 0;
}