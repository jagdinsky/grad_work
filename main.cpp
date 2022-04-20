#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

// Алгоритм Евклида поиска НОД
unsigned gcd(unsigned a, unsigned b) {
	if (b == 0) {
		return a;
    }
	return gcd(b, a % b);
}

int main() {
    // Считывание входных данных
    std::ifstream infile("input.txt");
    unsigned k;
    infile >> k;
    unsigned alpha, beta, gamma;
    infile >> alpha >> beta >> gamma;
    std::vector<std::vector<unsigned>> h;
    for (unsigned i = 0; i < k; i++) {
        std::vector<unsigned> tmp(k, 0);
        for (unsigned j = 0; j < k; j++) {
            infile >> tmp[j];
        }
        h.push_back(tmp);
    }

    // Нахождение точек совпадения
    std::vector<std::pair<unsigned, unsigned>> points;
    for (unsigned i = 0; i < k; i++) {
        for (unsigned j = 0; j < k; j++) {
            if ((alpha * i + beta * j + gamma) % k == h[i][j]) {
                points.push_back(std::make_pair(i, j));
            }
        }
    }

    // Проверка порождения
    if (points.size() < 3) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    unsigned det;
    for (unsigned p = 0; p < points.size() - 2; p++) {
        for (unsigned q = p + 1; q < points.size() - 1; q++) {
            for (unsigned r = q + 1; r < points.size(); r++) {
                det = (points[p].first * (points[q].second - points[r].second)
                     + points[q].first * (points[r].second - points[p].second)
                     + points[r].first * (points[p].second - points[q].second)) % k;
                if (gcd(k, det) == 1) {
                    std::cout << points[p].first << " " << points[p].second << '\n';
                    std::cout << points[q].first << " " << points[q].second << '\n';
                    std::cout << points[r].first << " " << points[r].second << '\n';
                    std::cout << "YES" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "MAYBE" << std::endl;
    return 0;
}
