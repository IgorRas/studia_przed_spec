#include <iostream>

class Button {
	public:
		bool on1;
		Button(): on1(false){}
		bool on() const { return on1;}
		virtual Button press() {}
		virtual Button release() {}
};

class PushButton: public Button {
	public:
	Button press() {on1 = true;
		return *this; }
	Button release() {on1 = false;
		return *this; }
};

class SwitchButton: public Button {
	public:
	Button press() {
	if(on1==false){
		on1=true;
	}
	else
	on1=false;
	return *this;
	}
	Button release() {
	return *this;
	}
};


int main() {
	std::cout << std::boolalpha;
	Button *pushButton = new PushButton;
	std::cout << pushButton->on() << " ";
	pushButton->press();
	std::cout << pushButton->on() << " ";
	pushButton->release();
	std::cout << pushButton->on() << std::endl;
	delete pushButton;
	Button *switchButton = new SwitchButton;
	std::cout << switchButton->on() << " ";
	pushButton->press();
	std::cout << switchButton->on() << " ";
	pushButton->release();
	std::cout << switchButton->on() << " ";
	pushButton->press();
	std::cout << switchButton->on() << std::endl;
	delete switchButton;
}
