############################################################
[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 51
  ny = 51
  xmin = -100
  xmax = 100
  ymin = -100
  ymax = 100
[]
############################################################
[GlobalParams]
  PorousFlowDictator = dictator
[]
############################################################
[UserObjects]
  [./dictator]
    type = PorousFlowDictator
    porous_flow_vars = 'P T'
    number_fluid_phases = 1
    number_fluid_components = 1
  [../]
[]
############################################################
[Variables]
  [./P]
    initial_condition = 5.0E7 # 500bar 
  [../]
  [./T]
    initial_condition = 473.15
  [../]
[]
############################################################
[Kernels]
  [./P_time_derivative]
    type = PorousFlowMassTimeDerivative 
    fluid_component = 0
    variable = P
  [../]

  [./P_mass_residual]
    type = PorousFlowAdvectiveFlux 
    fluid_component = 0
    variable = P
    gravity = '0 0 0'
  [../]

  [./T_time_derivative]
    type = PorousFlowEnergyTimeDerivative
    variable = T
  [../]
  
  [./heat_conduction]
    type = PorousFlowHeatConduction
    variable = T
  [../]

  [./heat_advection]
    type = PorousFlowHeatAdvection
    variable = T
    gravity = '0 0 0'
  [../]
[]
############################################################
[DiracKernels]
  [./P_mass_source]
    type = PTMassPointSource
    variable = P
    schedule = '0.0'
    value = '0.1'
    point = '-100.0 -100.0 0.0'
  [../]

  [./T_energy_source]
    type = PTEnergyPointSource
    variable = T
    schedule = '0.0'
    value = '0.1'
    point = '-100.0 -100.0 0.0'
    injection_temperature = 293.15
  [../]
[]
############################################################
[BCs]
  [./P_left_bottom]
    type = PTMassFluxBC 
    boundary = 'left bottom'
    variable = P
    value = 0
  [../]
  
  [./P_top_right]
    type = PTMassFreeBC 
    variable = P
    boundary = 'top right'
  [../]

  [./T_left_bottom]
    type = NeumannBC 
    boundary = 'left bottom'
    variable = T
    value = 0
  [../]
  
  [./T_right_top]
    type = PTEnergyOutFlowBC
    variable = T
    boundary = 'right top'
  [../]
[]

[Modules]
  [./FluidProperties]
    [./co2]
      type = CO2FluidProperties
    [../]
  [../]
[]
############################################################
[Materials]
  [./temperature]
    type = PorousFlowTemperature
    temperature = T 
  [../]

  [./temperture_nodal]
    type = PorousFlowTemperature
    temperature = T 
    at_nodes = true
  [../]

  [./ppss]
    type = PorousFlow1PhaseFullySaturated
    porepressure = P
  [../]

  [./co2]
    type = PorousFlowSingleComponentFluid
    fp = co2
    phase = 0
  [../]
[]
############################################################
[Executioner]
  type = Transient
  num_steps = 2
  dt = 1000

  solve_type = 'PJFNK' # default = PJFNK | NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type
                         -ksp_gmres_restart -snes_ls
                         -pc_hypre_boomeramg_strong_threshold'
  petsc_options_value = 'hypre boomeramg 201 cubic 0.7'

  l_max_its  = 20
  l_tol      = 1e-4
  nl_max_its = 50
  nl_rel_tol = 1e-4
  nl_abs_tol = 1e-7
[]
############################################################
[Outputs]
  file_base      = out
  exodus         = true
  [./Console]
    type = Console
    output_linear = true
    output_nonlinear = true
  [../]
[]
############################################################
