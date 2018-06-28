//* This file is part of the Geothermal framework
//* modified from MOOSE framwork:
//* https://www.mooseframework.org
//* by Chengkang Mo, College of Engineering, Peking University 
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "FluidProperties.h"

template <>
InputParameters
validParams<FluidProperties>()
{
  InputParameters params = validParams<GeneralUserObject>();
  params.registerBase("FluidProperties");
  return params;
}

FluidProperties::FluidProperties(const InputParameters & parameters) : GeneralUserObject(parameters)
{
}

FluidProperties::~FluidProperties() {}
