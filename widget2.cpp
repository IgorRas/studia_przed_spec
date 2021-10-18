#include <iostream>
#include <string>
#include <list>

class Widget {
	public:
		std::string name;
		std::list<Widget> dzieci;
		Widget(std::string nowy):name(nowy) {
			
		}
		virtual ~Widget() {
			dzieci.clear();
			name = "";
		}
		virtual void add(Widget *dziecko) {
			dzieci.push_back(*dziecko);
		}
		virtual void print() {
			std::cout << name <<std::endl;;
			for(Widget i: dzieci) {
				std::cout  << name << " "<< i.name <<std::endl;
				for(auto j: i.dzieci) {
					std::cout  << name << " "<< i.name << " " <<j.name <<std::endl;
				}
			}
		}
};
class Button: public Widget  {
	public:
		Button(std::string nowy):Widget(nowy) {
		//	std::cout<<"Button"<<std::endl;
		}
};



class Edit: public Widget {
	public:
		Edit(std::string nowy):Widget(nowy) {
		//	std::cout<<"Edit"<<std::endl;
		}
};



int main() {

	Button *yes = new Button("yes");
	Button *no = new Button("no");
	Widget *panel = new Widget("panel");
	panel->add(yes);
	panel->add(no);
	Edit *edit = new Edit("edit");
	Widget *window = new Widget("window");
	window->add(panel);
//	panel->print();
	window->add(edit);
	window->print();
	delete window;
}
