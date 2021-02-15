// Two people meet each other

#include<bits/stdc++.h>

using namespace std;

bool evermeet(int a1, int v1, int a2, int v2) {
	
	if (a1 < a2 && v1 <= v2) {
		return false;
	}
	if (a1 > a2 && v1 >= v2) {
		return false;
	}
	if (a1 < a2) {
		swap(a1,a2);
		swap(v1,v2);
	}
	while(a1 >= a2) {
		if (a1 == a2) {
			return true;
		}
		a1 = a1 + v1;
		a2 = a2 + v2;
	}
}

int main() {
	int a1, v1, a2, v2;
	cout << "Enter Position of first person : ";
	cin >> a1;
	cout << "Enter Speed of first person : ";
	cin >> v1;
	cout << "Enter Position of second person : ";
	cin >> a2;
	cout << "Enter Speed of second person : ";
	cin >> v2;
	if (evermeet(a1,v1,a2,v2)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
