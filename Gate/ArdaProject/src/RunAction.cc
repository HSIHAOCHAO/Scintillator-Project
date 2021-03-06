#include "RunAction.hh"

#include "G4Run.hh"
#include "globals.hh"

using namespace std;

static RunAction* instance = 0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
	outfile.open("output.txt",ios::out);
	G4cout << "Ouput file opened." << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
	outfile.close();
	G4cout << "Ouput file closed." << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
// 	G4cout << "Is the file open? " <<  outfile.is_open() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{ 
	G4cout << "### Run " << aRun->GetRunID() << " finished " << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction* RunAction::GetInstance()
{
	if (instance == 0)
		instance = new RunAction();
	return instance;
}



void RunAction::WriteToFile(G4double val, G4int scintNum)
{
// 	outfile.open("output.txt",ios::out | ios::app | ios::ate);
	if( outfile.is_open() )
		outfile << "Scint " << scintNum << " had " << val << " hits." << G4endl;
	else
		G4cout << "    The ouput file is not open!!!" << G4endl;
}