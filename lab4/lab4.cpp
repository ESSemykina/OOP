#include "keyboard.hpp" 

int main()
{
	ESS::Keyboard key;

	key.addCommand("a", "?"); 
	key.addCommand("b", "!"); 
	key.addCommand("ctrl+c", "copy"); 
	key.addCommand("ctrl+v", "paste"); 

	key.workflow("ctrl+c a b b a ctrl+v "); 

	key.undo(); 
	key.undo(); 

	return 0; 
}