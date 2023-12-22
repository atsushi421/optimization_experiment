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
