#pragma once
#include "Plate.h"
#include "FieldData.h"
class FieldManipulator
{
public:
	FieldManipulator();
	virtual ~FieldManipulator() = default;
	void draw();
	void update();
	int getFieldX(double x);
	int getFieldZ(double z);
	int checkFieldValue(int i, int j) { return field.getField(i, j); }
	double getFieldGridSize() const { return FieldGridSize; }
private:
	const double FieldGridSize = 5.0;	//1ƒOƒŠƒbƒh‚ ‚½‚è‚Ì‘å‚«‚³
	Plate plate;
	FieldData field;
};

