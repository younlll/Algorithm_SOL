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

	//���ı����� '������ ��������'
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Student students[] = {
		Student("������", 90),
		Student("�̻��", 93),
		Student("���ѿ�", 97),
		Student("������", 87),
		Student("������", 92)
	};

	//  sort(�޸��ּ�, ������ ������ �޸��ּ�)
	sort(students, students + 5);

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}