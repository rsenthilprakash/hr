#include <iostream>

int main(void)
{
    int N, K;

    std::cin >> N;
    std::cin >> K;

    int L = N + K - 1;
    char * in = new char[L + 1];
    char * out = new char[N + 1];

    std::cin >> in;

    out[0] = in[0];

    for (int i = 1; i <= K - 1; i++) {
	bool in_i = in[i] == '1' ? true : false;
	bool in_i_1 = in[i - 1] == '1' ? true : false;
	bool out_i = in_i ^ in_i_1;

	out[i] = out_i ? '1' : '0';
    }

    for (int i = K; i <= N - 1; i++) {
	bool in_i = in[i] == '1' ? true : false;
	bool in_i_1 = in[i - 1] == '1' ? true : false;
	bool out_i_K = out[i - K] == '1' ? true : false;
	bool out_i = (in_i ^ in_i_1) ^ out_i_K;

	out[i] = out_i ? '1' : '0';
    }

    out[N] = '\0';

    std::cout << out << std::endl;

    delete[] in;
    delete[] out;
    return 0;
}
