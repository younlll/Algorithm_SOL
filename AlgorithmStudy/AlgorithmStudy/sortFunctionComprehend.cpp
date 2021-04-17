#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	//정렬기준은 '점수가 작은순서'
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};

	//  sort(메모리주소, 정렬할 마지막 메모리주소)
	sort(students, students + 5);

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}