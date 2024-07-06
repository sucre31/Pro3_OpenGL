#include "FieldManipulator.h"

FieldManipulator::FieldManipulator(){
	field.setGridSize(FieldGridSize);
}

void FieldManipulator::draw() {
	//plate.draw();
	field.draw();
}

void FieldManipulator::update() {
	field.update();
}

int FieldManipulator::getFieldX(double x) {
	int Num;
	Num = (int)((x + FieldGridSize / 2) / FieldGridSize);
	if (Num < 0) {
		Num = 0;
	}
	if (Num >= field.fieldSizeX) {
		Num = field.fieldSizeX - 1;
	}
	return Num;
}

int FieldManipulator::getFieldZ(double z) {
	int Num;
	Num = (int)((z + FieldGridSize / 2) / FieldGridSize);
	if (Num < 0) {
		Num = 0;
	}
	if (Num >= field.fieldSizeZ) {
		Num = field.fieldSizeZ - 1;
	}
	return Num;
}