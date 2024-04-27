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
/// \file RunAction.cc
/// \brief Implementation of the B1::RunAction class

#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
// #include "Run.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"

namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
  // add new units for dose
  //

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  void RunAction::BeginOfRunAction(const G4Run*)
  {
  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();



  G4AnalysisManager* man = G4AnalysisManager::Instance();
    // man->SetNtupleMerging(true); // very important
    man->OpenFile("output.csv");

    man->CreateNtuple("simple", "out_data");

    man->CreateNtupleDColumn("eid");        // column Id = 0
    man->CreateNtupleDColumn("pid");        // column Id = 1
    // man->CreateNtupleSColumn("detectorId"); // column Id = 2
    // man->CreateNtupleDColumn("is_primary"); // column Id = 3

    // if (det->recordPosition())
    {
      man->CreateNtupleDColumn("posx");     // column Id = 4
      man->CreateNtupleDColumn("posy");     // column Id = 5
      man->CreateNtupleDColumn("posz");     // column Id = 6
      // man->CreateNtupleDColumn("del_posx"); // column Id = 7
      // man->CreateNtupleDColumn("del_posy"); // column Id = 8
      // man->CreateNtupleDColumn("del_posz"); // column Id = 9

      // man->CreateNtupleDColumn("vertex.x"); // column Id = 7
      // man->CreateNtupleDColumn("vertex.y"); // column Id = 8
      // man->CreateNtupleDColumn("vertex.z"); // column Id = 9
    }
    // if (det->recordTime())
    {
      // man->CreateNtupleDColumn("del_t");     // column Id = 10
      // man->CreateNtupleDColumn("globTime");  // column Id = 11
      // man->CreateNtupleDColumn("propTime");  // column Id = 12
      // man->CreateNtupleDColumn("localTime"); // column Id = 13
    }

    // if (det->recordEnergy())
    {
      // man->CreateNtupleDColumn("ni_edep");  // column Id = 14
      // man->CreateNtupleDColumn("tot_edep"); // column Id = 15
      man->CreateNtupleDColumn("tot_E");    // column Id =16
      // man->CreateNtupleDColumn("tot_KE");   // column Id=17
    }
    // if (det->recordMomentum())
    {
      // man->CreateNtupleDColumn("momx"); // column Id = 18
      // man->CreateNtupleDColumn("momy"); // column Id = 19
      // man->CreateNtupleDColumn("momz"); // column Id = 20
      // man->CreateNtupleDColumn("px");   // column Id = 21
      // man->CreateNtupleDColumn("py");   // column Id = 22
      // man->CreateNtupleDColumn("pz");   // column Id = 23
    

    }
    man->FinishNtuple();
 

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* run)
{

  // Run conditions
  //  note: There is no primary generator action object for "master"
  //        run manager for multi-threaded mode.


    G4AnalysisManager* man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();
    G4cout<<"File writing done...\n";
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::AddEdep(G4double edep)
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
