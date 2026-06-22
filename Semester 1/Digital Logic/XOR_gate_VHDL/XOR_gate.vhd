------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (6/11/2023, 10:31:44 PM)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 2.50.200 (Feb 18, 2022)
-- Copyright (c) 2002-2022 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.all;


ENTITY XOR_gate IS
  PORT( 
    --------------------------------------> Inputs:
    iA:           IN  std_logic;
    iB:           IN  std_logic;
    --------------------------------------> Outputs:
    oY:           OUT std_logic 
    ------------------------------------------------------
    );
END XOR_gate;


ARCHITECTURE structural OF XOR_gate IS 

  ----------------------------------------> Components:
  COMPONENT NOT_gate IS
    PORT( I: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT AND2_gate IS
    PORT( I0,I1: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR2_gate IS
    PORT( I0,I1: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;

  ----------------------------------------> Signals:
  SIGNAL S001: std_logic;
  SIGNAL S002: std_logic;
  SIGNAL S003: std_logic;
  SIGNAL S004: std_logic;
  SIGNAL S005: std_logic;
  SIGNAL S006: std_logic;
  SIGNAL S007: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S001 <= iA;
  S004 <= iB;

  ----------------------------------------> Output:
  oY <= S007;

  ----------------------------------------> Component Mapping:
  C005: NOT_gate PORT MAP ( S004, S003 );
  C006: NOT_gate PORT MAP ( S001, S002 );
  C007: AND2_gate PORT MAP ( S001, S003, S005 );
  C008: AND2_gate PORT MAP ( S002, S004, S006 );
  C009: OR2_gate PORT MAP ( S005, S006, S007 );
END structural;
