<p align="center">
  <a href="https://github.com/Evgenk2020/my_think_cell_test/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/Evgenk2020/my_think_cell_test" alt="license">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test/commits">
    <img src="https://img.shields.io/github/last-commit/Evgenk2020/my_think_cell_test" alt="last commit">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test">
    <img src="https://img.shields.io/github/repo-size/Evgenk2020/my_think_cell_test" alt="repo size">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test/stargazers">
    <img src="https://img.shields.io/github/stars/Evgenk2020/my_think_cell_test" alt="stars">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test/network/members">
    <img src="https://img.shields.io/github/forks/Evgenk2020/my_think_cell_test" alt="forks">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test">
    <img src="https://img.shields.io/github/languages/top/Evgenk2020/my_think_cell_test" alt="top language">
  </a>
  <a href="https://github.com/Evgenk2020/my_think_cell_test/releases">
    <img src="https://img.shields.io/github/v/release/Evgenk2020/my_think_cell_test" alt="latest release">
  </a>
</p>

# My think-cell test

<b>This is the Think-Cell test to implement interval_map class in C++</b>

<b>Task Description</b>

`interval_map<K, V>`is a data structure that associates keys of type K with values of type V. It is designed to be used efficiently in situations where intervals of consecutive keys are associated with the same value.

Your task is to implement the assign member function of this data structure, which is outlined below `interval_map<K, V>`is implemented on top of `std::map` For more information on `std::map` you may refer to cppreference.com</br>
Each key-value-pair (k,v) in `interval_map<K, V>::m_map` means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map. The member `interval_map<K, V>::m_valBegin` holds the value that is associated with all keys less than the first key in m_map.

Example: Let M be an instance of `interval_map<int,char>` where

```c++

    M.m_valBegin == 'A',
    M.m_map == { (1,'B'), (3,'A') },

```

 Then M represents the mapping</br>
...</br>
-2 -> 'A'</br>
-1 -> 'A'</br>
0 -> 'A'</br>
1 -> 'B'</br>
2 -> 'B'</br>
3 -> 'A'</br>
4 -> 'A'</br>
5 -> 'A'</br>
...</br>

The representation in the std::map must be canonical, that is, consecutive map entries must not contain the same value:</br>
..., (3,'A'), (5,'A'), ...</br>
is not allowed. Likewise, the first entry in m_map must not contain the same value as m_valBegin. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the `interval_map<K, V>` data structure.

<b>Key type K</b>

- besides being copyable and assignable, is less-than comparable via operator `<`, and
- does not implement any other operations, in particular no equality comparison or arithmetic operators

<b>Value type V</b>

- besides being copyable and assignable, is equality-comparable via `operator==`, and
- does not implement any other operations
