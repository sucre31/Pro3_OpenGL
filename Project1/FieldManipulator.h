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
	double getFieldRemainderX(double x);
	double getFieldRemainderZ(double z);
	int checkFieldValue(int i, int j) { return field.getField(i, j); }
	double getFieldGridSize() const { return FieldGridSize; }
	void setFieldGridNumber(int num) { fieldGridNumber = num; }
	int getFieldGridNumber() { return fieldGridNumber; }
private:
	const double FieldGridSize = 7.0;	//1ƒOƒŠƒbƒh‚ ‚½‚è‚Ì‘å‚«‚³
	int fieldGridNumber;
	Plate plate;
	FieldData field;
};

