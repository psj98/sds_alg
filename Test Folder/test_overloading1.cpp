#include <iostream>

using namespace std;

int sum(int, int);
float sum(float, float);

int main(){
  int a, b;
  float c, d;

  printf("�� ������ �Է��Ͻʽÿ�.\n");
  cin >> a >> b;
  printf("�� ������ ���� %d �Դϴ�.\n", sum(a, b));
 
  printf("\n�� �Ǽ��� �Է��Ͻʽÿ�.\n");
  cin >> c >> d;
  printf("�� �Ǽ��� ���� %.2f �Դϴ�.\n", sum(c, d));

  return 0;
}

int sum(int a, int b) {
  return a + b;
}

float sum(float a, float b) {
  return a + b;
}