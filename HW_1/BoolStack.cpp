#include "BoolStack.h"
#include <stdexcept>
#include <iostream>

BoolStack::BoolStack() : topNode(nullptr), size(0) {}

BoolStack::~BoolStack() {
    while (!isEmpty()) {
        pop();  // 스택이 비어질 때까지 항목 제거
    }
}

void BoolStack::push(bool item) {
    Node* newNode = new Node(item);   // 새로운 노드 생성
    newNode->next = topNode;          // 새 노드의 next를 기존 topNode로 설정
    topNode = newNode;                // topNode를 새 노드로 갱신
    size++;                           // 스택의 크기 증가
}

bool BoolStack::pop() {
    if (isEmpty()) {
    // 스택이 비어있을 때 예외 처리
        throw std::out_of_range("Stack is empty, cannot pop.");
    }

    Node* tempNode = topNode;        // 현재 최상단 노드를 임시로 저장
    bool poppedData = topNode->data; // 최상단 노드의 데이터를 저장
    topNode = topNode->next;         // 최상단을 그 다음 노드로 변경
    delete tempNode;                 // 이전 최상단 노드 메모리 해제
    size--;                          // 스택 크기 감소

    return poppedData;               // 꺼낸 데이터 반환
}

bool BoolStack::top()const{
    if (isEmpty()) {
            throw std::out_of_range("스택이 비어있어 top을 접근할 수 없습니다.");
        }
        return topNode->data;
};

bool BoolStack::isEmpty() const {
    return size == 0;
};

int BoolStack::getSize() const{
    return size;
};

