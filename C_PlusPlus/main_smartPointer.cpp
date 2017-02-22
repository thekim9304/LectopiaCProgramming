#if 0
#include <iostream>
using namespace std;
#include "light.h"

int main(int argc, char * argv[])
{
	my_sp<Light> room1(new Light);
	my_sp<Light> room2(new Light);
	my_sp<Light> room3(new Light);
	room_ctl(room1, false);
	room_ctl(room2);
	room_ctl(room3, false);
	cout << boolalpha << "room1 : " << room1->getStat() << endl;
	cout << "room2 : " << room2->getStat() << endl;
	cout << "room3 : " << room3->getStat() << endl;
	return 0;
}
#endif