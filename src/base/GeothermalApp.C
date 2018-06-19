#include "GeothermalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<GeothermalApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

GeothermalApp::GeothermalApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  GeothermalApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  GeothermalApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  GeothermalApp::registerExecFlags(_factory);
}

GeothermalApp::~GeothermalApp() {}

void
GeothermalApp::registerApps()
{
  registerApp(GeothermalApp);
}

void
GeothermalApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"GeothermalApp"});
}

void
GeothermalApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"GeothermalApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
GeothermalApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
GeothermalApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
GeothermalApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
GeothermalApp__registerApps()
{
  GeothermalApp::registerApps();
}

extern "C" void
GeothermalApp__registerObjects(Factory & factory)
{
  GeothermalApp::registerObjects(factory);
}

extern "C" void
GeothermalApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  GeothermalApp::associateSyntax(syntax, action_factory);
}

extern "C" void
GeothermalApp__registerExecFlags(Factory & factory)
{
  GeothermalApp::registerExecFlags(factory);
}
