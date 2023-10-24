#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), number(0), koreanScore(0), englishScore(0), mathScore(0) { } //처음 생성될 경우 학생의 정보 초기화

Student::Student(const string& name, int number, int koreanScore, int englishScore, int mathScore) : name(name), number(number), koreanScore(koreanScore), englishScore(englishScore), mathScore(mathScore) { } //학생의 정보 저장

void Student::Info() const                                  //학생의 정보 출력
{
    double average = Avg();                    //평균 계산
    cout << "이름 : " << name << ", 번호 : " << number << ", 국어 : " << koreanScore << ", 영어 : " << englishScore << ", 수학 : " << mathScore << ", 평균 : " << average << endl;
}

double Student::Avg() const { return static_cast<double>(koreanScore + englishScore + mathScore) / 3; }    //평균계산

const string& Student::GetName() const { return name; }     //private로 지정되어있는 학생의 이름 반환

const int Student::GetNumber() const { return number; }     //private로 지정되어있는 학생의 번호 반환
