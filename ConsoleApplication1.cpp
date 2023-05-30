#include "Processes.h"









int main()
{
	
	robo_map R = robo_map();
	
	particles p1 = particles(91, 15, 0);
	particles p2 = particles(8, 15, 1);
	particles p3 = particles(7, 15, 2);
	particles p4 = particles(8, 15, 3);
	
	R.mark_map(p1.x, p1.y);
	R.mark_map(p2.x, p2.y);
	R.mark_map(p3.x, p3.y);
	R.mark_map(p4.x, p4.y);
	R.map_print();
	

	p1.get_data(R.mp, p1.position);
	p2.get_data(R.mp, p2.position);
	p3.get_data(R.mp, p3.position);
	p4.get_data(R.mp, p4.position);


	p1.print_sensor_dat();
	p2.print_sensor_dat();
	p3.print_sensor_dat();
	p4.print_sensor_dat();


	R.map_print();



		return 0;
}


