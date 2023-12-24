#include <chrono>
#include <iostream>
#include <vector>

struct Dummy {
  int a;
  int b;
  int c;
  int d;
};

void functionToMeasure() {
  const int VECTOR_SIZE = 1000000;
  std::vector<Dummy> v;
  v.resize(VECTOR_SIZE);

  Dummy currentDummy;
  for (int i = 0; i < VECTOR_SIZE; ++i) {
    currentDummy.a = 1;
    currentDummy.b = 2;
    currentDummy.c = 3;
    currentDummy.d = 4;
    v.emplace_back(currentDummy);
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
