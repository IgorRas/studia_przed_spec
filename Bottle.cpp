#include <iostream>

class Bottle	{	
		const double v;
		double v2;
	public:
		Bottle(double c);
		double volume() const;
		double fill(double a);
		double pour(double b);

};

Bottle::Bottle(double c):v(c), v2()	{
}

double Bottle::volume() const	{
	return v2;
}

double Bottle::fill(double a)	{
	if(a+v2>=v)	{
		v2=v+0.0;
	}
	else	{
		v2=v2+a;
	}
	return v2;
}


double Bottle::pour(double b)	{
	double p=0;
	if(b>=v){
		v2=0;
		p=v;
	}
	else	{
		v2=v2-b;
		p=b;
	}
	return p;
}



int main ()	{
	Bottle bottle(10.);
	std::cout << bottle.volume() << " ";
	std::cout << bottle.fill(5.5) << " ";
	std::cout << bottle.volume() << " ";
	std::cout << bottle.fill(0.5) << " ";
	std::cout << bottle.volume() << " ";
}
