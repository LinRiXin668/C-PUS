/*
�ѳ���Ϊ n �����Ӽ��� m �Σ�m, n ��Ϊ���������Լ��㵶������ m С�����ӳ���֮�����Ϊ���٣�
���磺
����Ϊ 8 �����ӿ��Լ��� 3��3��2 ���Σ�������Ϊ 18��
����Ϊ 3 �����Ӳ�����������Ϊ 3��
��ע�⡿
ţ�����ϵ����������ӱ���ü�һ�Σ����Գ���Ϊ 3 ������������Ϊ 2�����ɳ���Ϊ 1 �� 2 �����Σ�
C++ �������������ټ�һ�ε�ʵ�֣�ͬ�ļ����� Python ���������ӿ��Բ�����ʵ��
*/

class Solution
{
public:
    int cutRope(int number)
    {
        int* dp = new int[number + 1];
        dp[0] = 0, dp[1] = dp[2] = 1, dp[3] = 2; // ���ӱ���ü�һ��
        if (number < 4)
            return dp[number];
        for (int i = 0; i < 4; ++i) // �� number >= 4 ��ʱ��dp[0~3�Ĳ���] �����ȼ�Ҫ��
            dp[i] = i;
        int max = 0;
        for (int i = 4; i <= number; ++i)
        {
            // ����һ�γ���Ϊ i �����ӣ���һ���� j ���ȣ��� f(i) = max(f(j) * f(i-j))��
            // �͵�һ���� i-j ���ȣ��ڶ����� j ���ȱ�������һ����
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = dp[j] * dp[i - j];
                max = dp[i] > max ? dp[i] : max;
                dp[i] = max;
            }
        }
        return dp[number];
    }
};

#include <iostream>


int main()
{
    Solution s;
    std::cout << s.cutRope(1) << " "
        << s.cutRope(5) << " "
        << s.cutRope(6) << " "
        << s.cutRope(7) << " "
        << s.cutRope(8) << " " << std::endl;
}