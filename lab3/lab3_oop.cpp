//Создать шаблонный класс Array3d, который внутри хранит одномерный массив,  но наружу его выдает как трехмерный.

#include<iostream>
#include"lab3_oop.h"

int main() {

	ESS::Array3d<int> array3D(3, 3, 3); 


	array3D.setValue(2, 2, 2, 456); 
	std::cout << array3D.getValue(2, 2, 2) << std::endl;  

	array3D.fill_1(4);
	array3D.Print();  
	array3D.zeroes();
	array3D.Print();
	array3D.ones();
	array3D.Print();
	return 0;

}