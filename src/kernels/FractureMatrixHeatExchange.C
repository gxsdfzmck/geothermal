//* This file is part of the geothermal

#include "FractureMatrixHeatExchange.h"

#include "MooseVariable.h"

registerMooseObject("GeothermalApp", FractureMatrixHeatExchange);

template <>
InputParameters
validParams<FractureMatrixHeatExchange>()
{
  InputParameters params = validParams<Kernel>();

  params.addParam<Real>("heat_convection_coef", 0.0, "heat conduction coefficient between fracture fluid and rock surface");
  params.addRequiredCoupledVar(
      "couple_matrix_temperature", "The temperature of the matrix will be used.");
  return params;
}

FractureMatrixHeatExchange::FractureMatrixHeatExchange(const InputParameters & parameters)
  : Kernel(parameters), 
    _h(getParam<Real>("heat_convection_coef")),
    _couple_matrix_temperature(coupledValue("couple_matrix_temperature"))
{
}

Real
FractureMatrixHeatExchange::computeQpResidual()
{
  return  _test[_i][_qp] * _h * (_u[_qp] - _couple_matrix_temperature[_qp]);
}

Real
FractureMatrixHeatExchange::computeQpJacobian()
{
  return _test[_i][_qp]* _h * _phi[_j][_qp];
}
