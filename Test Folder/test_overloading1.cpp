#include <iostream>

using namespace std;

int sum(int, int);
float sum(float, float);

int main(){
  int a, b;
  float c, d;

  printf("두 정수를 입력하십시오.\n");
  cin >> a >> b;
  printf("두 정수의 합은 %d 입니다.\n", sum(a, b));
 
  printf("\n두 실수를 입력하십시오.\n");
  cin >> c >> d;
  printf("두 실수의 합은 %.2f 입니다.\n", sum(c, d));

  return 0;
}

int sum(int a, int b) {
  return a + b;
}

float sum(float a, float b) {
  return a + b;
}