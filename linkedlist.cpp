// 대학교에서 강의 목록을 관리하는 간단한 시스템을 구현
// 강의 정보는 과목 코드, 과목 이름, 학점 수로 구성됨
// 이 시스템은 강의 정보를 추가하고, 삭제하며, 전체 강의 목록을 출력할 수 있음
/*
요구 사항:
1. 강의 정보를 저장하는 데 연결 리스트를 사용하십시오.
2. 연결 리스트를 활용한 강의 목록 관리 시스템 클래스를 설계하십시오.
3. 강의 정보를 추가하는 기능을 구현하십시오.
4. 강의 정보를 삭제하는 기능을 구현하십시오.
5. 전체 강의 목록을 출력하는 기능을 구현하십시오.
*/
#include <iostream>
#include <string>
using namespace std;

class Lecture {
public:
    string name;
    int number;
    Lecture* next;
    Lecture(string name, int number) : name(name), number(number), next(nullptr) {}
};

class LectureList {
public:
    Lecture* head;
    LectureList() : head(nullptr) {}
    void addLecture(string name, int number) {
        // TODO: 새로운 Lecture 객체를 생성하고, 연결 리스트에 추가하기
        Lecture* lecture = new Lecture(name, number);
        if(head==nullptr) {
            head = lecture; 
            return;
        }
        Lecture* listEnd = head;
        while(listEnd->next!=nullptr) listEnd = listEnd->next;
        listEnd->next = lecture;
    }
    void deleteLecture(int number) {
        // TODO: 강의 번호로 해당 강의를 찾아 연결 리스트에서 삭제하기
        //찾고자 하는 노드의 이전 노드를 prevLecture이라고 한다.
        Lecture* prevLecture = head;
        //delete하기 위해서는 해당 노드의 이전 노드와 이후 노드를 이어줘야만 한다.
        //만약 처음부터 number와 일치한다면 이전 노드가 없으므로 에러가 발생한다. 따라서 따로 처리를 해줘야한다.
        if(prevLecture->number==number) {
            head = head->next;
            delete prevLecture;
            cout << "Lecture removed." << endl;
            return;
        }
        while(prevLecture->next->number!=number && prevLecture!=nullptr) prevLecture = prevLecture->next;
        //number가 없을 경우를 대비하여 findLecture가 nullptr이면 종료되는 조건을 추가한다.
        if(prevLecture==nullptr) {
            cout << "Error. The lecture does not exist" << endl;
            return;
        }
        //지우고자 하는 노드를 curLecture이라 한다.
        Lecture* curLecture = prevLecture->next;
        //prevLecture와 curLecture 다음의 노드를 이어준다.
        prevLecture->next = curLecture->next;
        //동적할당의 free
        cout << "Lecture removed." << endl;
        delete curLecture;
    }
    void displayLectures() {    // TODO: 연결 리스트의 모든 강의를 출력하기
        Lecture* traverseLecture = head;
        while(traverseLecture!=nullptr) {
            cout << "Lecture: " << traverseLecture->name << " (" << traverseLecture->number << ")" << endl;
            traverseLecture = traverseLecture->next;
        }
    }
};

int main() {
    LectureList list;
    // TODO: 사용자로부터 강의 정보를 입력받아 리스트에 추가하는 코드 작성하기
    list.addLecture("Data Structures", 101);
    list.addLecture("Algorithms", 102);
    list.addLecture("Operating Systems", 201);
    list.addLecture("Computer Networks", 202);
    cout << "Initial list:" << endl;
    // TODO: 사용자로부터 강의 번호를 입력받아 해당 강의를 삭제하는 코드 작성하기
    list.displayLectures();
    // TODO: 연결 리스트의 모든 강의를 출력하는 코드 작성하기
    list.deleteLecture(102);
    cout << "After removing lecture 102:" << endl;
    list.displayLectures();
    return 0;
}