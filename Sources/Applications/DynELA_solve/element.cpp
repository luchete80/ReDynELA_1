/***************************************************************************
 *                                                                         *
 *  DynELA Project                                                         *
 *                                                                         *
 *  (c) Copyright 1997-2004                                                *
 *                                                                         *
 *      Equipe C.M.A.O                                                     *
 *      Laboratoire Genie de production                                    *
 *      Ecole Nationale d'Ingenieurs de Tarbes                             *
 *      BP 1629 - 65016 TARBES cedex                                       *
 *                                                                         *
 *                                                                         *
 *  Main Author: Olivier PANTALE                                           *
 *                                                                         *
 **************************************************************************/

// begin date : 
// revision date : 
#include <femLibrary.h>
#include <InputDyn.h>


int main() {

    Structure model;

  model.createNode(1, 0.,0.,0.);
  model.createNode(2, .1,0.,0.);
  model.createNode(3, 0.,.1,0.);
  model.createNode(4, .1,.1,0.);
  model.createNode(5, 0.,0.,.1);
  model.createNode(6, .1,0.,.1);
  model.createNode(7, 0.,.1,.1);
  model.createNode(8, .1,.1,.1);
  
}