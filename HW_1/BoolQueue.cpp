/*
#include "BoolQueue.h"
#include <stdexcept>

void BoolQueue::enqueue(bool item){

};

bool BoolQueue::dequeue(){

};

bool BoolQueue::front() const{

};

bool BoolQueue::isEmpty() const{

};

int BoolQueue::getSize() const{

};
*/

#include "BoolQueue.h"
#include <stdexcept>
#include <iostream>

BoolQueue::BoolQueue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

BoolQueue::~BoolQueue() {
    while (!isEmpty()) {
        dequeue();  // 큐가 비어질 때까지 항목 제거
    }
}

void BoolQueue::enqueue(bool item) {
    Node* newNode = new Node(item);  // 새로운 노드 생성
    if (isEmpty()) {
        frontNode = rearNode = newNode; // 큐가 비어있으면 front와 rear 모두 새 노드로 설정
    } else {
        rearNode->next = newNode;       // 기존 rear 노드의 next를 새 노드로 설정
        rearNode = newNode;             // rear 노드를 새 노드로 갱신
    }
    size++;  // 큐 크기 증가
}

bool BoolQueue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("큐가 비어있어 dequeue할 수 없습니다.");
    }

    Node* tempNode = frontNode;         // 현재 front 노드를 임시로 저장
    bool dequeuedData = frontNode->data; // front 노드의 데이터를 저장
    frontNode = frontNode->next;        // front를 그 다음 노드로 변경
    delete tempNode;                    // 이전 front 노드 메모리 해제
    size--;                              // 큐 크기 감소

    if (isEmpty()) {
        rearNode = nullptr;              // 큐가 비어있으면 rear도 nullptr로 설정
    }

    return dequeuedData;                // 꺼낸 데이터 반환
}

bool BoolQueue::front() const {
    if (isEmpty()) {
        throw std::out_of_range("큐가 비어있어 front를 접근할 수 없습니다.");
    }
    return frontNode->data;             // front 노드의 데이터 반환
}

bool BoolQueue::isEmpty() const {
    return size == 0;                    // 큐 크기가 0이면 true 반환
}

int BoolQueue::getSize() const {
    return size;                         // 현재 큐 크기 반환
}
