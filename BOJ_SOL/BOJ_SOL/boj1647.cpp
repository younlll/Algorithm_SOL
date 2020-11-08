#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parent;

//���� Ŭ����
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

//�θ��� ���ϱ�
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

//�θ��� ã��
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {	//�� ����� �θ� ���� ���
		return true;
	}
	return false;
}

//�� ����� �θ� ��ġ��
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	//���� �θ��� �� �� ���� ������ ��ģ��
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Edge> vc;
	cin >> N >> M;
	
	parent.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;	//���� ����� ��尡 �����Ƿ� �ڱ��ڽ��� �θ�
	}

	int n1, n2, dist;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> dist;
		vc.push_back(Edge(n1, n2, dist));	//�������� �Է�(���1, ���2, ���)
	}

	//���� ����� �������� �������� ����
	sort(vc.begin(), vc.end());

	int sum = 0;
	int prev = 0;
	for (int i = 0; i < vc.size(); i++) {
		//�θ� �ٸ� ���(����Ŭ�� �߻����� �ʴ� ���)
		if (!findParent(vc[i].node[0], vc[i].node[1])) {
			sum += vc[i].distance;
			prev = vc[i].distance;	//���� �������� ����� ���� ����� ���� ū ����̴�
			unionParent(vc[i].node[0], vc[i].node[1]);
		}
	}

	//���� ū ������� ����� �Ÿ��� ���� ������ �ΰ��� �и�
	//�ּҺ������ �ΰ��� ������ ������ �� �ִ�
	cout << sum-prev << '\n';

	return 0;
}