//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the B1::DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4bool checkOverlaps = true;

 
  
  // define materials
  
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");//AIR
  G4Material* target_mat = nist->FindOrBuildMaterial("??"); // Set to Aluminum target
  G4Material* detector_mat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE"); // plastic scintillator
  

  // define sizes:
  // World (cube)
  G4double world_sizeXY = 1.1*m; // 1.1 m cube
  G4double world_sizeZ =  100*cm; // 1 m thick
  // target (cube) and detector sizes
  G4double target_sizeXY = 1*m; // 1 m lateral size
  G4double target_sizeZ  = ??*cm; //  cm thickness

  // target (cube) and detector sizes
  G4double det_sizeXY = 1*m; // 1 m lateral size
  G4double det_sizeZ  = ??*cm; //  cm thickness



 // create world volume
  G4Box* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0) // world usually placed at 0,0,0
                      logicWorld,            //its logical volume
                      "World",               //its name 
                      0,                     //its mother  volume - world mother volume is 0
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking


  // create target
  G4Box* solidTar =
    new G4Box("Target",                    //its name
        0.5*target_sizeXY, 0.5*target_sizeXY, 0.5*target_sizeZ); //its size

  G4LogicalVolume* logicTar =
    new G4LogicalVolume(solidTar,            //its solid
                        target_mat,             //its material
                        "Target");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicTar,                //its logical volume
                    "Target",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  

  
  

  // Top detector
  G4Box* solidDetT =
    new G4Box("DetectorT",                    //its name
        0.5*det_sizeXY, 0.5*det_sizeXY, 0.5*det_sizeZ); //its size

  G4LogicalVolume* logicDetT =
    new G4LogicalVolume(solidDetT,            //its solid
                        target_mat,             //its material
                        "DetectorT");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0,0,-2.5*cm),         //at (0,0,0)
                    logicDetT,                //its logical volume
                    "DetectorT",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Exercise: create a bottom detector displace by 2.5 cm along z from the centre

 
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
