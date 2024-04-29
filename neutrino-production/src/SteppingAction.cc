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
/// \file SteppingAction.cc
/// \brief Implementation of the B1::SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4AnalysisManager.hh"

namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  // if (!fScoringVolume) {
  //   const DetectorConstruction* detConstruction
  //     = static_cast<const DetectorConstruction*>
  //       (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  //   fScoringVolume = detConstruction->GetScoringVolume();
  // }

  // get volume of the current step
  G4LogicalVolume* volume
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();

  // check if we are in scoring volume
  // if (volume != fScoringVolume) return;

  // collect energy deposited in this step
  // G4double edepStep = step->GetTotalEnergyDeposit();
  // fEventAction->AddEdep(edepStep);

  if(volume->GetName()=="Detector")
{
    uint eid = G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
    int columnId=0;
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(columnId++, eid);
    man->FillNtupleDColumn(columnId++, step->GetTrack()->GetDefinition()->GetPDGEncoding());
    man->FillNtupleSColumn(columnId++, volume->GetName());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetParentID());

    // man->FillNtupleDColumn(columnId++, step->GetPreStepPoint()->GetPosition().x());
    // man->FillNtupleDColumn(columnId++, step->GetPreStepPoint()->GetPosition().y());
    // man->FillNtupleDColumn(columnId++, step->GetPreStepPoint()->GetPosition().z());
    man->FillNtupleDColumn(columnId++, step->GetDeltaPosition().x());
    man->FillNtupleDColumn(columnId++, step->GetDeltaPosition().y());
    man->FillNtupleDColumn(columnId++, step->GetDeltaPosition().z());

    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetVertexPosition().x());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetVertexPosition().y());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetVertexPosition().z());

    // man->FillNtupleDColumn(columnId++, step->GetDeltaTime());
    man->FillNtupleDColumn(columnId++, step->GetTrack()->GetGlobalTime());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetProperTime());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetLocalTime());

    // man->FillNtupleDColumn(columnId++, step->GetNonIonizingEnergyDeposit());
    // man->FillNtupleDColumn(columnId++, step->GetTotalEnergyDeposit());
    man->FillNtupleDColumn(columnId++, step->GetTrack()->GetTotalEnergy());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetKineticEnergy());

    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentum().x());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentum().y());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentum().z());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentumDirection().x());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentumDirection().y());
    // man->FillNtupleDColumn(columnId++, step->GetTrack()->GetMomentumDirection().z());

    man->AddNtupleRow();


}



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
