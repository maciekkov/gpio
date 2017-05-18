#include <string>
#include <fstream>

using namespace std;

int export_gpio(const string& num)
{
	string export_str = "/sys/class/gpio/export";
	ofstream exportfile(export_str.c_str());
	if(exportfile.good())
	{
		exportfile << num;
		exportfile.close();
		return 0;
	}
	else
	{
	return -1;
	}

}
int direction_gpio(const string& dir,const string& num)
{
	string direction_str = "/sys/class/gpio/gpio"+num+"direction";
	ofstream directionfile(direction_str.c_str());
	if(directionfile.good())
	{
		directionfile << dir;
		directionfile.close();
		return 0;
	}
	else
	{
		return -1;
	}
}

int set_value_gpio(const string& val,const string& num)
{
	string value_str = "/sys/class/gpio/gpio"+num+"/value";
	ofstream valuefile(value_str.c_str());
	if(valuefile.good())
	{
		valuefile << val;
		valuefile.close();
		return 0;
	}
	else
	{
	return -1;
	}
}

int get_value_gpio(string& val,const string& num)
{
	string value_str = "/sys/class/gpio/gpio"+num+"/value";
	ifstream getvaluefile(value_str.c_str());
	if(getvaluefile.good())
	{
		getvaluefile >> val;
		if(val !="0")
		val = "1";
		else
		val="0";
		getvaluefile.close();
		return 1;
	}
	else
	{
		return -1;
	}

}
int unexport_gpio(const string& num)
{
	string unexport_str = "/sys/class/gpio/unexport";
	ofstream unexportfile(unexport_str.c_str());
	if(unexportfile.good())
	{
		unexportfile << num;
		unexportfile.close();
		return 0;
	}
	else
	{
	return -1;
	}
}
















