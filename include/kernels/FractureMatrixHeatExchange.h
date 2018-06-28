//* This file is part of the geothermal Applicatin

#ifndef FractureMatrixHeatExchange_H
#define FractureMatrixHeatExchange_H

#include "Kernel.h"

class FractureMatrixHeatExchange;

template <>
InputParameters validParams<FractureMatrixHeatExchange>();

class FractureMatrixHeatExchange : public Kernel
{
public:
  FractureMatrixHeatExchange(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  
  
private: 
  Real _h;
  const VariableValue & _couple_matrix_temperature;
};

#endif // FractureMatrixHeatExchange_H
