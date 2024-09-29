#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <cmath>


using namespace std;

struct CharIntConstruct
{
    int type;//0 == number , 1 == operator
    int number; //피연산자
    char symbol; //연산자
};

int symbolPrecedence(char op) //우선순위 판단
{
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    if (op == '^') { //가장 높은 순위
        return 3;

    }
    return 0;
}

vector<CharIntConstruct> make_postfix(istream& ins) {//중위 표기법 > 후위 표기법
    vector<CharIntConstruct> postfix; //후위 변형 저장할 백터
    stack<char> operators; //연산자 저장 스택
    string input;
    getline(ins, input);
    stringstream S(input); //입력 스트림 변환
    char C;

    while (S >> C) {
        if (isdigit(C)) {//숫자 입력이었을 때
            S.putback(C);
            int num;
            S >> num;
            postfix.push_back({ 0, num, 0 }); //백터에 숫자 추가
        }
        else if (C == '(') {
            operators.push(C);
        }
        else if (C == ')') {
            while (!operators.empty() && operators.top() != '(') { //괄호 전까지 숫자 추가
                postfix.push_back({ 1, 0, operators.top() });
                operators.pop();
            }
            operators.pop(); //(제거
        }
        else { //연산자일 때
            while (!operators.empty() && symbolPrecedence(operators.top()) >= symbolPrecedence(C)) { //우선순위
                postfix.push_back({ 1, 0, operators.top() });
                operators.pop();
            }
            operators.push(C);
        }
    }

    while (!operators.empty()) {//연산자가 남았을 떄
        postfix.push_back({ 1, 0, operators.top() });
        operators.pop();
    }

    return postfix; //후위표기 반환
}

bool evaluate_stack(stack<int>& numbers, const char symbol) { //스택 피연산자 꺼내 연산 수행
    if (numbers.size() < 2) {
        throw runtime_error("Error!\n");
    }

    int num2 = numbers.top();
    numbers.pop(); // 두 번째 피연산자
    int num1 = numbers.top();
    numbers.pop(); // 첫 번째 피연산자

    switch (symbol) {
    case '+':
        numbers.push(num1 + num2);
        break;
    case '-':
        numbers.push(num1 - num2);
        break;
    case '*':
        numbers.push(num1 * num2);
        break;
    case '/':
        if (num2 == 0) {
            throw runtime_error("Error!\n");
        }
        numbers.push(num1 / num2);
        break;
    case '%':
        if (num2 == 0) {
            throw runtime_error("Error!\n");
        }
        numbers.push(num1 % num2);
        break;
    case '^':
        numbers.push(pow(num1, num2));
        break;
    default:
        throw runtime_error("Error!\n");
        break;
    }
    return true;
}

int evaluate_postfix(vector<CharIntConstruct> postfix) { // 변환된 수식 스택 이용 계산
    stack<int> num; //피연산자 저장 스택
    for (const auto& token : postfix) {
        if (token.type == 0) { //숫자
            num.push(token.number); //스택에 추가
        }
        else {//연산자
            evaluate_stack(num, token.symbol); //연산
        }
    }
    return num.top(); //결과 반환
}


int main(void)
{
    while (1)
    {
        try {
            string input;
            cout << "======================\n" << endl;
            cout << "input:";
            getline(cin, input); //입력 받은 것 저장
            if (input == "EOI") {
                break;
            }

            stringstream sS(input); //스트림 변환
            vector<CharIntConstruct> postfix = make_postfix(sS);//중>후 변환
            int result = evaluate_postfix(postfix); //계산
            cout << "result : " << result << endl;
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
