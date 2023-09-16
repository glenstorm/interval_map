#include "interval_map.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	interval_map<int, char> m_test('D');
	m_test.assign(1, 4, 'B');
	m_test.assign(5, 7, 'A');

	for( int i = -2; i < 10; ++i )
	{
		cout << "m_test[" << i << "]" << " = " << m_test[i] << endl;
	}

	/* code */
	return 0;
}
