### Pair with maps:

we can use a `pair` as a key in both `map` and `set`, but `not directly` in `unordered_map` and `unordered_set` without providing a `custom hash function`. This is because unordered_map and unordered_set require a hash function for the keys, while map and set use a comparison function for keys.


  ```cpp
    struct SimpleHash {
      size_t operator()(const std::pair<int, int>& p) const {
          return p.first ^ p.second;
      }
    };

    std::unordered_set<std::pair<int, int>, SimpleHash> S;
    S.insert(std::make_pair(0, 1));
  ```