#include <iostream>
#include "BoolStack.h"
#include "BoolQueue.h"

int main()
{
    BoolStack stack; // BoolStack 인스턴스 생성
    BoolQueue queue; // BoolQueue 인스턴스 생성

    int Select1, Select2;

    std::cout << "원하는 작업을 선택하세요. : (1. Queue 2. Stack ) ";
    std::cin >> Select1;

    if (Select1 == 2) { // 스택 동작 선택
        while (true) {
            std::cout << "원하는 작업을 선택하세요. :\n";
            std::cout << "(1. push 2. pop 3. top 4. isEmpty 5. getSize 6. 종료)\n";
            std::cin >> Select2;

            if (Select2 == 1) { // push
                bool item;
                while (true) {
                    std::cout << "추가할 값을 입력하세요 (0 또는 1): ";
                    std::cin >> item;
                    if (item == 0 || item == 1) {
                        stack.push(item);
                        std::cout << "값이 추가되었습니다.\n";
                        break;
                    } else {
                        std::cout << "유효하지 않은 값입니다. 0 또는 1만 입력하세요.\n";
                    }
                }
            }
            else if (Select2 == 2) { // pop
                try {
                    bool poppedValue = stack.pop();
                    std::cout << "꺼낸 값: " << poppedValue << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
            }
            else if (Select2 == 3) { // top
                try {
                    bool topValue = stack.top();
                    std::cout << "최상단 값: " << topValue << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
            }
            else if (Select2 == 4) { // isEmpty
                std::cout << (stack.isEmpty() ? "스택이 비어 있습니다." : "스택에 항목이 있습니다.") << "\n";
            }
            else if (Select2 == 5) { // getSize
                std::cout << "스택 크기: " << stack.getSize() << "\n";
            }
            else if (Select2 == 6) { // 종료
                break;
            }
            else {
                std::cout << "지원하지 않는 작업입니다.\n";
            }
        }
    }

    if (Select1 == 1) { // 큐 동작 선택
        while (true) {
            std::cout << "원하는 작업을 선택하세요. :\n";
            std::cout << "(1. enqueue 2. dequeue 3. front 4. isEmpty 5. getSize 6. 종료)\n";
            std::cin >> Select2;

            if (Select2 == 1) { // enqueue
                bool item;
                while (true) {
                    std::cout << "추가할 값을 입력하세요 (0 또는 1): ";
                    std::cin >> item;
                    if (item == 0 || item == 1) {
                        queue.enqueue(item);
                        std::cout << "값이 추가되었습니다.\n";
                        break;
                    } else {
                        std::cout << "유효하지 않은 값입니다. 0 또는 1만 입력하세요.\n";
                    }
                }
            }
            else if (Select2 == 2) { // dequeue
                try {
                    bool dequeuedValue = queue.dequeue();
                    std::cout << "꺼낸 값: " << dequeuedValue << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
            }
            else if (Select2 == 3) { // front
                try {
                    bool frontValue = queue.front();
                    std::cout << "가장 앞 항목: " << frontValue << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
            }
            else if (Select2 == 4) { // isEmpty
                std::cout << (queue.isEmpty() ? "큐가 비어 있습니다." : "큐에 항목이 있습니다.") << "\n";
            }
            else if (Select2 == 5) { // getSize
                std::cout << "큐 크기: " << queue.getSize() << "\n";
            }
            else if (Select2 == 6) { // 종료
                break;
            }
            else {
                std::cout << "지원하지 않는 작업입니다.\n";
            }
        }
    } else {
        std::cout << "지원하지 않는 작업입니다.";
    }

    return 0;
}
