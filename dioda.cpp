
#include <iostream>

using namespace std;

int main()
{
	string gpio4="4";
	string gpio17="17";
	export_gpio(gpio4);
	export_gpio(gpio17);
	
	
	string dir_in="in";
	string dir_out="out";
	direction_gpio(dir_in,gpio4);
	direction_gpio(dir_out,gpio17);
	
	
	string state = "";
	
	while(true)
	{
		get_value_gpio(state,gpio17);
		if( state =="1")
		{
			usleep(20000);
			get_value_gpio(state,gpio17);
			if(state=="1")
			{
				
			set_value_gpio("1",gpio4);
			}
		}
		
	}
	return 0;
}
