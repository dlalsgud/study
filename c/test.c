#include <stdio.h>

void main() {
	int sleeping_time[4][5] = {{ 8,8,7,4,6 },{9,10,6,7,7},{6,6,5,8,7},{10,10,6,5,8}};

	for (int i = 0; i < 4; i++) {
		int sum = 0;
		
		for (int j = 0; j < 5; j++) {
			sum += sleeping_time[i][j];

		}
		printf("%d의 학년의 평균 수면시간 %f\n",(i+1),(sum/5.0));
	}

}
