#include "ScoreManager.h"
#include <iostream>
#include <algorithm>
using namespace std;

ScoreManager::ScoreManager() : numStudents(0) { }       //처음 생성될 경우 학생 수는 0

void ScoreManager::AddStudent(const Student& student)  { students[numStudents++] = student; }   //학생의 정보를 받아 students배열에 저장 후 학생 수 증가

void ScoreManager::StudentsInfo() const           //모든 학생들의 정보 반환
{
    for (int i = 0; i < numStudents; ++i) { students[i].Info(); }
}

void ScoreManager::SearchName(const std::string& name) const      //학생의 이름을 입력받아 학생의 정보 출력
{
    bool found = false;                     //학생의 이름이 있는 경우 true로 변경
    for (int i = 0; i < numStudents; ++i)   //저장되어있는 학생 수만큼 반복
    {
        if (students[i].GetName() == name)  //이름이 같을 경우
        {
            students[i].Info();      //학생의 정보 출력
            found = true;
        }
    }

    if (!found) { cout << "해당 이름의 학생을 찾을 수 없습니다.\n"; }  //맞는 이름이 없을 경우 출력
}

void ScoreManager::SearchNum(int number) const     //학생의 번호를 입력받아 학생의 정보 출력
{
    bool found = false;                         //번호에 맞는 학생이 있는 경우 true로 변경
    for (int i = 0; i < numStudents; ++i)       //저장되어있는 학생 수만큼 반복
    {
        if (students[i].GetNumber() == number)  //같은 번호가 존재할 경우
        {
            students[i].Info();          //학생의 정보 출력
            found = true;
        }
    }

    if (!found) { cout << "해당 번호의 학생을 찾을 수 없습니다.\n"; }  //맞는 번호가 없을 경우 출력
}

void ScoreManager::AvgRank(string targetName) const    //이름을 입력받아 평균과 석차 출력
{
    int targetIndex = -1;                           //입력 받은 학생의 인덱스 찾기
    for (int i = 0; i < numStudents; ++i)           //저장되어있는 학생 수만큼 반복
    {
        if (students[i].GetName() == targetName) { targetIndex = i; }   //저장되어있는 이름이 입력받은 이름과 같을 경우 targetIndex는 i로 저장
    }

    if (targetIndex != -1)                          //인덱스가 변경되었을 경우
    {
        const Student& targetStudent = students[targetIndex];   //입력받은 학생의 정보 가져오기
        double average = targetStudent.Avg();      //학생의 평균 계산
        
        int rank = 1;                                           //학생의 석차를 저장할 변수생성
        for (int i = 0; i < numStudents; ++i) { if (students[i].Avg() > average) { rank++; } }     //다른 학생들과 평균을 계산하여 입력받은 학생의 평균보다 높을 경우 rank증가

        cout << "이름 : " << targetStudent.GetName() << ", 평균 : " << average << " 석차 : " << rank << endl;   //학생의 평균과 석차 출력
    }
    else { cout << "해당 이름의 학생을 찾을 수 없습니다.\n";}  //이름이 없을 경우
}

void ScoreManager::AvgSort() const             //평균이 높은 순서대로 이름 출력
{
    Student studentsCopy[MAX_DATA_COUNT];                       //평균 순서대로 저장할 새로운 배열 생성
    for (int i = 0; i < numStudents; ++i) { studentsCopy[i] = students[i]; }    //배열에 저장되어있는 정보 복사

    sort(studentsCopy, studentsCopy + numStudents, [](const Student& a, const Student& b) { return a.Avg() > b.Avg(); } );    // 평균에 따라 내림차순 정렬

    cout << "평균이 높은 순으로 학생 이름 출력\n";
    for (int i = 0; i < numStudents; ++i) { cout << studentsCopy[i].GetName() << "\n"; }    //정렬된 배열 순서대로 출력
}

const Student& ScoreManager::GetStudent(int index) const { return students[index]; }        //private로 지정되어있는 학생의 정보 반환

int ScoreManager::GetNum() const { return numStudents; }                            //private로 지정되어있는 저장되어있는 학생 수 반환