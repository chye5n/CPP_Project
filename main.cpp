#include<iostream>
#include"ScoreManager.h"
#include"Student.h"
using namespace std;

ScoreManager scoreManager;                                                  //ScoreManager 생성자

void showMenu()                                                             //메뉴 보여주기
{
    cout << "1. 데이터 입력" << endl;
    cout << "2. 입력한 모든 정보 출력" << endl;
    cout << "3. 이름으로 검색하기" << endl;
    cout << "4. 번호로 검색하기" << endl;
    cout << "5. 이름 입력 입력 받아 평균과 석차를 출력" << endl;
    cout << "6. 평균 점수가 높은 순으로 이름을 출력" << endl;
    cout << "종료를 원하시면 q 또는 Q를 누르세요" << endl;
}

void InputData(ScoreManager& scoreManager)                                  //1. 학생 정보 추가
{
    if (scoreManager.GetNum() >= MAX_DATA_COUNT) { cout << "추가 입력이 불가능합니다.\n"; }
    else
    {
        char name[30];
        int num, kor, eng, math;
        cout << "이름 : ";
        cin >> name;
        cout << "번호 : ";
        cin >> num;
        cout << "국어 : ";
        cin >> kor;
        cout << "영어 : ";
        cin >> eng;
        cout << "수학 : ";
        cin >> math;

        Student student(name, num, kor, eng, math);
        scoreManager.AddStudent(student);
    }
}

void SearchName(const ScoreManager& scoreManager)                           //3. 이름으로 검색
{
    string name;
    cout << "검색할 학생의 이름을 입력하세요: ";
    cin >> name;

    scoreManager.SearchName(name);
}

void SearchNum(const ScoreManager& scoreManager)                            //4. 번호로 검색
{
    int num;
    cout << "검색할 학생의 번호를 입력하세요: ";
    cin >> num;

    scoreManager.SearchNum(num);
}

void AvgRank(const ScoreManager& scoreManager)                              //5. 이름으로 평균과 석차 출력
{
    string name;
    cout << "평균과 석차를 출력할 학생의 이름을 입력하세요: ";
    cin >> name;

    scoreManager.AvgRank(name);
}

void RunMenu(char a, ScoreManager& scoreManager)                            //실행할 코드 선택
{
    switch (a) {
    case '1': InputData(scoreManager); break;
    case '2': scoreManager.StudentsInfo(); break;
    case '3': SearchName(scoreManager); break;
    case '4': SearchNum(scoreManager); break;
    case '5': AvgRank(scoreManager); break;
    case '6': scoreManager.AvgSort(); break;
    case 'q':
    case 'Q': cout << "프로그램을 종료합니다.\n"; exit(0); break;
    default: cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
    }
}

void selectMenu(ScoreManager& scoreManager)                                 //실행할 코드의 번호 입력받기
{
    char choice;
    cout << "숫자입력 : ";
    cin >> choice;
    RunMenu(choice, scoreManager);
}

void main() 
{
    while (1)
    {
        showMenu();
        selectMenu(scoreManager);
    }
}