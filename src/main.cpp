#include <iostream>
#include <map>

template <typename K, typename V>
class interval_map
{
private:
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val
    interval_map(V const &val) : m_valBegin(val) {}

    // Assign value val to interval [keyBegin, keyEnd].
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.

    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {
        // INSERT YOUR SOLUTION HERE
        // ****************************
        using map_iterator = std::map<K, V>::iterator;

        if (!(keyBegin < keyEnd))
        {
            return;
        }

        auto symb = [this](map_iterator &temp)
        {
            V s;
            if (temp == m_map.begin())
            {
                s = m_valBegin;
            }

            else
            {
                s = (--temp)->second;
            }

            return s;
        };

        map_iterator it_begin = m_map.lower_bound(keyBegin);
        map_iterator it_end = m_map.upper_bound(keyEnd);
        V symbol = symb(it_end);

        if (!(val == symb(it_begin)))
        {
            it_begin = ++(m_map.insert_or_assign(it_begin, keyBegin, val));
        }

        while (it_begin != m_map.end() && !(keyEnd < it_begin->first))
        {
            if ((++it_begin) == m_map.end() || keyEnd < it_begin->first)
            {
                symbol = (--it_begin)->second;
            }

            m_map.erase(it_begin++);
        }

        if (!(val == symbol))
        {
            m_map.insert(it_begin, {keyEnd, symbol});
        }
        // ****************************
    }

    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        auto it = m_map.upper_bound(key);

        if (it == m_map.begin())
        {
            return m_valBegin;
        }

        else
        {
            return (--it)->second;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

//-----------------------------------------------------
// check for correct work of the interval map
int main()
{
    
    // int example
    interval_map<int, char> b('Q');
    b.assign(4, 6, 'f');

    for (int i = 0; i < 10; i++)
    {
        std::cout << "first interval: " << i << "--" << b[i] << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;

    // char example
    interval_map<char, int> m(3);
    m.assign('e', 'k', 135);

    for (char j = 'a'; j <= 'z'; j++)
    {
        std::cout << "second interval: " << j << "--" << m[j] << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;

    // float example
    interval_map<float, char> r('X');
    r.assign(1.3, 6.8, 'w');
    
    for (int i = 0; i < 10; i++)
    {
        std::cout << "third interval: " << i << "--" << r[i] << std::endl;
    }
}
//-----------------------------------------------------