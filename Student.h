#pragma once
#include <string>
using namespace std;

#ifndef _STUDENT_H_	//if not define		//define되어있지 않다면 define해라
#define _STUDENT_H_

class Student 
{
private:
    string name;
    int number,koreanScore, englishScore, mathScore;

public:
    Student();                              //기본생성자
    Student(const string& name, int number, int koreanScore, int englishScore, int mathScore);  //학생의 정보 받기
    void Info() const;               //학생의 정보 출력
    double Avg() const;        //학생의 평균계산

    const string& GetName() const;          //학생의 이름 반환
    const int GetNumber() const;            //학생의 번호 반환
};

#endif // !_STUDENT_H_
