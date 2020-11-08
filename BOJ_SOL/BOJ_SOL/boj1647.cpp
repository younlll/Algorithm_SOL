#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parent;

//간선 클래스
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

//부모노드 구하기
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

//부모노드 찾기
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {	//두 노드의 부모가 같은 경우
		return true;
	}
	return false;
}

//두 노드의 부모 합치기
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	//구한 부모노드 중 더 작은 값으로 합친다
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
		parent[i] = i;	//현쟁 연결된 노드가 없으므로 자기자신이 부모
	}

	int n1, n2, dist;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> dist;
		vc.push_back(Edge(n1, n2, dist));	//간선정보 입력(노드1, 노드2, 비용)
	}

	//간선 비용을 기준으로 오름차순 정렬
	sort(vc.begin(), vc.end());

	int sum = 0;
	int prev = 0;
	for (int i = 0; i < vc.size(); i++) {
		//부모가 다른 경우(사이클이 발생하지 않는 경우)
		if (!findParent(vc[i].node[0], vc[i].node[1])) {
			sum += vc[i].distance;
			prev = vc[i].distance;	//가장 마지막에 연결된 간선 비용이 가장 큰 비용이다
			unionParent(vc[i].node[0], vc[i].node[1]);
		}
	}

	//가장 큰 비용으로 연결된 거리를 끊어 마을을 두개로 분리
	//최소비용으로 두개의 마을을 관리할 수 있다
	cout << sum-prev << '\n';

	return 0;
}