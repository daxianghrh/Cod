#include <stdio.h>

#define BIT3 (0X1 << 3) 
// 0X1: 0001 << 3
//      1000 
static int c = 0;
//��������͵Ķ�������1�ĸ���
// x&(x-1) ���԰�x��Ӧ�Ķ������������һλ1ȥ��
/**
����:
    9: 1001
    8: 1000
    --------
       1000
    
    8: 1000
    7: 0111
    -------
       0000
    ���������Է���9�Ķ�����������2��1
*/
int calCountOfOne(int num) {
    int count_of_one = 0;
    while (num) {
        count_of_one++;
        num = num & (num -1);
    }
    return count_of_one;
}

//��������͵Ķ�������0�ĸ���
// x|(x+1)
/*
���磺
    9�� 1001
        1010
        1011 -> 1011

        1101
        1110 -> 1111

       10000���� -> ��������0�ĸ���Ϊ2
*/
int calCountOfZero(int num) {
    int count_of_zero = 0;
    while (num + 1) {
        count_of_zero++;
        num = num | (num + 1);
    }
    return count_of_zero;
}

//����һ����������a,����a��bit3Ϊ1,��������λ����
void set_bit3(void) {
    c |= BIT3;
}

//����һ����������a,����a��bit3Ϊ0,��������λ����
void clear_bit3(void) {
    c &= ~BIT3;
}


int main() {
    printf("%d\n", calCountOfOne(9999));
    printf("%d\n", calCountOfZero(9999));
    //��������������ֵ����ʹ�õ���������
    /**
        1��ʹ�üӼ���
        2�����
    */
    int a = 3, b = 5;
    printf("����ǰ:a = %d, b = %d\n", a, b);
    // a = a + b; // a = 8
    // b = a - b; // b = 3
    // a = a - b; // a = 5
    a = a^b;
    b = a^b;
    a = a^b;
    printf("������:a = %d, b = %d\n", a, b);


    set_bit3();
    printf("0x%x\n", c);
    clear_bit3();
    printf("0x%x\n", c);
    return 0;
}
