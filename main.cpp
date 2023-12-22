#include <chrono>
#include <iostream>
#include <vector>

void functionToMeasure() {
  const int VECTOR_SIZE = 1000000;
  std::vector<int> v(VECTOR_SIZE, 1);

  for (int i = 0; i < VECTOR_SIZE; ++i) {
    v[i] = i;
  }
}

int main() {
  const int NUM_TRIALS = 100; // 測定回数
  std::vector<long long> durations;

  for (int i = 0; i < NUM_TRIALS; ++i) {
    auto start = std::chrono::high_resolution_clock::now();

    functionToMeasure();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
    durations.push_back(duration);
  }

  long long totalDuration = 0;
  for (auto duration : durations) {
    totalDuration += duration;
  }
  double averageDuration = static_cast<double>(totalDuration) / NUM_TRIALS;

  std::cout << "Average duration: " << averageDuration << " milliseconds"
            << std::endl;

  return 0;
}
