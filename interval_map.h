#ifndef INTERVAL_MAP_H_GUARD
#define INTERVAL_MAP_H_GUARD

#include <map>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
		:m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
		// Check if the interval is valid
		if (!(keyBegin < keyEnd)) {
			return; // Empty interval, do nothing
		}

		// Find the first element with a key greater than or equal to keyBegin
		auto itBegin = m_map.lower_bound(keyBegin);

		// Insert a new element with keyBegin and val
		// or update the existing element if it's not the end of the map
		if (itBegin == m_map.begin() || (--itBegin)->second != val) {
			// If it's the beginning of the map or the previous value is different,
			// insert a new element
			auto res = m_map.insert(std::pair<K, V>(keyBegin, val));
			itBegin = res.first;
		}

		// Find the first element with a key greater than or equal to keyEnd
		auto itEnd = m_map.lower_bound(keyEnd);

		// Erase all elements in the range [keyBegin, keyEnd) except the one with keyBegin
		m_map.erase(++itBegin, itEnd);
}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.


#endif
	// INTERVAL_MAP_H_GUARD
