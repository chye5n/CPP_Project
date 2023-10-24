#pragma once

#define MAX_DATA_COUNT 10

#ifndef _SCOREMANAGER_H_
#define _SCOREMANAGER_H_

#include "student.h"

class ScoreManager 
{
private:
    Student students[MAX_DATA_COUNT];               //학생을 최대 10명까지 저장하도록 배열의 범위 지정
    int numStudents;                                //학생 수 저장

public:
    ScoreManager();                                 //기본생성자
    void AddStudent(const Student& student);        //학생 정보 추가
    void StudentsInfo() const;                      //모든 학생들의 정보 출력
    void SearchName(const string& name) const;      //이름으로 학생의 정보 출력
    void SearchNum(int number) const;               //번호로 학생의 정보 출력
    void AvgRank(string targetName) const;          //이름을 입력받아 평균과 석차 출력
    void AvgSort() const;                           //평균이 높은 순서대로 이름 출력

    const Student& GetStudent(int index) const;     //해당 인덱스에 저장되어있는 학생의 정보 반환
    int GetNum() const;                             //클래스에 저장되어있는 학생의 수 반환
};

#endif // !_SCOREMANAGER_H_
