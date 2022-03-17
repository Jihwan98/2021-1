#include <iostream>
using namespace std;

void longer(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& a_len, double& b_len);
int main() {
	cout << "line_1 의 두 좌표값을 입력하세요. x1, y1, x2, y2 : ";
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "line_2 의 두 좌표값을 입력하세요. x3, y3, x4, y4 : ";
	double x3, x4, y3, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	double line1_len, line2_len;
	longer(x1, y1, x2, y2, x3, y3, x4, y4, line1_len, line2_len);
	cout << "line_1 의 길이 : " << line1_len << endl;
	cout << "line_2 의 길이 : " << line2_len << endl;

	return 0;
}


void longer(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& a_len, double& b_len) {
	a_len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b_len = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	if (a_len > b_len)
		cout << "line_1 의 길이가" << a_len - b_len << " 만큼 더 깁니다" << endl;
	else if(b_len > a_len)
		cout << "line_2 의 길이가" << b_len - a_len << " 만큼 더 깁니다" << endl;
	else
		cout << "두 line 의 길이가 같습니다" << endl;
}