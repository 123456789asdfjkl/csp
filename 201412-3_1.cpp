/*
 * 90
 */
#include "iostream"
#include "string"
#include "vector"
#include "tuple"
#include <cstdio>

int main() {
    std::string action;
    double p;
    long long s;
    long long i;
    long long buy[1000000 + 10] = {0};
    long long sell[1000000 + 10] = {0};
    std::vector<long long> candinate;
    std::vector<std::tuple<std::string, double, long long>> vi;
    while (std::cin >> action) {
        if (action == "buy") {
            std::cin >> p >> s;
            long long temp = p * 100;
            buy[temp] += s;
            candinate.push_back(temp);
        } else if (action == "sell") {
            std::cin >> p >> s;
            long long temp = p * 100;
            sell[temp] += s;
            candinate.push_back(temp);
        } else {
            std::cin >> i;
            auto elemeter = vi[i-1];
            if (std::get<0>(elemeter) == "buy") {
                long long temp = std::get<1>(elemeter) * 100;
                buy[temp] -= std::get<2>(elemeter);
            } else if (std::get<0>(elemeter) == "sell") {
                long long  temp = std::get<1>(elemeter) * 100;
                sell[temp] -= std::get<2>(elemeter);
            }
        }
        vi.push_back(std::make_tuple(action, p, s));
    }

    for (int j = 1; j <= 1000000; ++j) {
        sell[j] = sell[j - 1] + sell[j];
    }
    for (int j = 1000000 - 1; j >= 0; --j) {
        buy[j] = buy[j] + buy[j+1];
    }
    long long ans = 0;
    long long max_sum = 0;
    for (int j = 0; j < candinate.size(); ++j) {
        long long temp_pos = candinate[j];
        long long temp_value = std::min(sell[temp_pos], buy[temp_pos]);
        if (temp_value > max_sum) {
            ans = temp_pos;
            max_sum = temp_value;
        } else if (temp_value == max_sum) {
            if(ans<temp_pos){
                ans = temp_pos;
            }
        }
    }
    printf("%.2lf %lld", ans / 100.0, max_sum);
    return 0;
}