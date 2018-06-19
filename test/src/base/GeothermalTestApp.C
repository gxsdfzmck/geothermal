//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "GeothermalTestApp.h"
#include "GeothermalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<GeothermalTestApp>()
{
  InputParameters params = validParams<GeothermalApp>();
  return params;
}

GeothermalTestApp::GeothermalTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  GeothermalApp::registerObjectDepends(_factory);
  GeothermalApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  GeothermalApp::associateSyntaxDepends(_syntax, _action_factory);
  GeothermalApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  GeothermalApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    GeothermalTestApp::registerObjects(_factory);
    GeothermalTestApp::associateSyntax(_syntax, _action_factory);
    GeothermalTestApp::registerExecFlags(_factory);
  }
}

GeothermalTestApp::~GeothermalTestApp() {}

void
GeothermalTestApp::registerApps()
{
  registerApp(GeothermalApp);
  registerApp(GeothermalTestApp);
}

void
GeothermalTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
GeothermalTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
GeothermalTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
GeothermalTestApp__registerApps()
{
  GeothermalTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
GeothermalTestApp__registerObjects(Factory & factory)
{
  GeothermalTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
GeothermalTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  GeothermalTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
GeothermalTestApp__registerExecFlags(Factory & factory)
{
  GeothermalTestApp::registerExecFlags(factory);
}
