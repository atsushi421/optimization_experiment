# optimization_experiment

## size()

### Used

Average duration: 8.15 milliseconds

```c++
const int VECTOR_SIZE = 1000000;
std::vector<int> v(VECTOR_SIZE, 1);

for (int i = 0; i < v.size(); ++i) {
  v[i] = i;
}
```

### Not Used

Average duration: 6.14 milliseconds

```c++
const int VECTOR_SIZE = 1000000;
std::vector<int> v(VECTOR_SIZE, 1);

for (int i = 0; i < VECTOR_SIZE; ++i) {
  v[i] = i;
}
```

## emplace_back()

### Direct

Average duration: 45.36 milliseconds

```c++
void functionToMeasure() {
  const int VECTOR_SIZE = 1000000;
  std::vector<Dummy> v;
  v.resize(VECTOR_SIZE);

  for (int i = 0; i < VECTOR_SIZE; ++i) {
    v.emplace_back(Dummy{1, 2, 3, 4});
  }
}
```

### Indirect

Average duration: 45.24 milliseconds

```c++
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
```
